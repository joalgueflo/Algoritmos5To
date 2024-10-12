#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

// Estructura para representar un nodo en el TRIE
struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {
        children.resize(ALPHABET_SIZE, nullptr);
    }
};

class Trie {
private:
    TrieNode* root;
    
    // Función auxiliar para el recorrido DFS
    void dfsUtil(TrieNode* node, string& current, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(current);
        }
        
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] != nullptr) {
                current.push_back('a' + i);
                dfsUtil(node->children[i], current, result);
                current.pop_back();
            }
        }
    }

public:
    //inicializa el TRIE con un nodo raíz vacío
    Trie() {
        root = new TrieNode();
    }
    
    // Inserta una palabra en el TRIE
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    // Busca una palabra en el TRIE
    // Retorna true si la palabra existe, false en caso contrario
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
    
    // Realiza un recorrido en profundidad (DFS) del TRIE
    // Retorna un vector con todas las palabras en el TRIE
    vector<string> dfs() {
        vector<string> result;
        string current;
        dfsUtil(root, current, result);
        return result;
    }
};

int main() {
    Trie trie;
    
    int N;
    cin >> N;
    
    // Insertar palabras en el TRIE
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }
    
    // Realizar recorrido DFS e imprimir resultado
    vector<string> dfsResult = trie.dfs();
    for (const string& word : dfsResult) {
        cout << word << " ";
    }
    cout << endl;
    
    int M;
    cin >> M;
    
    // Buscar palabras en el TRIE
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;
        cout << trie.search(word) << " ";
    }
    cout << endl;
    
    return 0;
}