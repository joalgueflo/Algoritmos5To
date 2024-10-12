#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void z_function(const std::string &t, const std::string &m) {
	std::string s = m + "@" + t;
    int n = s.size();
	std::vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
		if(z[i] == m.size()){
			std::cout << std::boolalpha << true << ' ' << i - m.size() << std::endl;
			return;
		}
    }
	std::cout << std::boolalpha << false << std::endl;
}

const int64_t m = 1000000007;
const int64_t p = 67;
int char_value(char c){
	if(c == '\n') return 1 + 26 + 26 + 10;
	else if(std::islower(c)) return c - 'a' + 1;
	else if(std::isupper(c)) return c - 'A' + 1 + 26;
	else if(std::isdigit(c)) return c - '0' + 1 + 26 + 26;
	else return 0;
}

std::vector<int64_t> pows;
std::vector<int64_t> compute_hash(std::string const& s) {
    int64_t hash_value = 0;
    int64_t p_pow = 1;
	pows.clear();
	std::vector<int64_t> prefix_hash;
    for (char c : s) {
        hash_value = (hash_value + char_value(c) * p_pow) % m;
		prefix_hash.push_back(hash_value);
		pows.push_back(p_pow);
        p_pow = (p_pow * p) % m;
    }
	pows.push_back(p_pow);
    return prefix_hash;
}

bool is_palindrome(int idx, int size, const std::vector<int64_t> &h, const std::vector<int64_t> &rh, bool even = false){
	int left = idx - size;
	int right = idx + size - even;

	if(left < 0 || right >= h.size()) return false;

	int64_t left_hash = h[right] - (left-1==0? 0: h[left-1]);
	int64_t right_hash = rh[left] - (right+1==h.size()? 0: rh[right+1]);

	int lts = left;
	int rte = (h.size()-1)-right;

	if (lts < rte)
		left_hash = (left_hash * pows[rte - lts]) % m;

	if (lts > rte)
		right_hash = (right_hash * pows[lts - rte]) % m;
		
	return left_hash == right_hash;
}

void longest_palindrome(const std::string &t, const std::vector<int64_t> &ht, const std::vector<int64_t> &hrt){
	int ai = 0, al = 1;

	for(int i = 0; i < t.size(); i++){
		int l = 0;
		int r = t.size();
		while(l <= r){
			int m = (r + l) / 2;
			if(is_palindrome(i, m, ht, hrt, 0)) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		l--;
		if(2 * l + 1 > al){
			ai = i - l;
			al = 2 * l + 1;
		}

		l = 0;
		r = t.size();
		while(l <= r){
			int m = (r + l) / 2;
			if(is_palindrome(i, m, ht, hrt, 1)) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		l--;
		if(2 * l > al){
			ai = i - l;
			al = 2 * l;
		}
	}

	std::cout << ai+1 << ' ' << ai + al << ' ';
	std::cout << t.substr(ai, al) << std::endl;
}

// Función que devuelve el substring común más largo entre dos strings
string longestCommonSubstring(const string& str1, const string& str2) {
    // Sacamos las longitudes de los strings
    int m = str1.size();
    int n = str2.size();
    int maxLength = 0; 
    int endIndex = 0; 

    // Creamos un vector de vectores de enteros de tamaño m+1 x n+1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Llenamos la matriz dp con la longitud del substring común más largo
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Si los caracteres son iguales, la longitud del substring común es la longitud del substring común anterior + 1
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // Actualizamos maxLength y endIndex si encontramos un substring común más largo
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                // Si los caracteres no son iguales, la longitud del substring común es 0
                dp[i][j] = 0;
            }
        }
    }

    // Extraemos el substring común más largo
    if (maxLength == 0) {
        return ""; // No se encontró ningún substring común
    }
    return str1.substr(endIndex - maxLength + 1, maxLength);
}

int main(){

	std::ifstream it1, it2, im1, im2, im3;
	it1.open("transmission1.txt");
	it2.open("transmission2.txt");
	im1.open("mcode1.txt");
	im2.open("mcode2.txt");
	im3.open("mcode3.txt");

	std::string line;
	std::string t1, t2, m1, m2, m3;
	while(std::getline(it1, line))
		t1 += line + '\n';
	while(std::getline(it2, line))
		t2 += line + '\n';
	while(std::getline(im1, line))
		m1 += line + '\n';
	while(std::getline(im2, line))
		m2 += line + '\n';
	while(std::getline(im3, line))
		m3 += line + '\n';

	
	
	// parte uno: Z function
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;

	cout << "Parte 1" << endl;
	cout<<endl;
	z_function(t1, m1);
	z_function(t1, m2);
	z_function(t1, m3);
	z_function(t2, m1);
	z_function(t2, m2);
	z_function(t2, m3);


	// parte 2, string hashing
	
	// every char has a diferent value (up to 63)
	// smallest prime bigger than 63 is 67
	/* for(char c = 'a'; c <= 'z'; c++) std::cout << char_value(c) << ' '; */
	/* for(char c = 'A'; c <= 'Z'; c++) std::cout << char_value(c) << ' '; */
	/* for(char c = '0'; c <= '9'; c++) std::cout << char_value(c) << ' '; */
	/* std::cout << char_value('\n') << ' '; */
	/* std::cout << std::endl; */
	
	cout<<endl;
	cout << "Parte 2" << endl;
	cout<<endl;
	std::string rt1 = t1;
	reverse(rt1.begin(), rt1.end());
	std::vector<int64_t> ht1 = compute_hash(t1);
	std::vector<int64_t> hrt1 = compute_hash(rt1);
	reverse(hrt1.begin(), hrt1.end());
	longest_palindrome(t1, ht1, hrt1);

	std::string rt2 = t2;
	reverse(rt2.begin(), rt2.end());
	std::vector<int64_t> ht2 = compute_hash(t2);
	std::vector<int64_t> hrt2 = compute_hash(rt2);
	reverse(hrt2.begin(), hrt2.end());
	longest_palindrome(t2, ht2, hrt2);

	//Parte 3 
	cout<<"Parte 3" << endl;
	cout<<endl;
	std::string lcs = longestCommonSubstring(t1, t2);
    if (!lcs.empty()) {
        size_t startPos = t1.find(lcs); 
		int endPos = startPos + lcs.length();
		cout<<startPos<<endl;
		cout<<endPos<<endl;
		cout<<lcs<<endl;
    } else {
        std::cout << "No common substring found." << std::endl;
    }

	return 0;
}
