#include <iostream>
using namespace std;

//Swap function for sort methods
template <class T>
void swap(vector<T> &list, int a, int b)
{
    if (a != b)
    {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}




template <class T>
void merge(vector <T> &list, int left, int mid, int right){
    //Create left list
    vector<T> leftList;
    for(int i = left; i <= mid; i++){
        leftList.push_back(list[i]);
    }
    //Create right list
    vector<T> rightList;
    for(int j = mid+1; j<=right; j++){
        rightList.push_back(list[j]);
    }

    int auxIndex = left;

    int leftIndex=0;
    int rightIndex=0; 


    //Compare while theres elements on both lists

    while(leftIndex < leftList.size() && rightIndex < rightList.size()){
        //Compare values in leftList and rightList

        //left is smaller
        if(leftList[leftIndex] < rightList[rightIndex]){
            list[auxIndex] = leftList[leftIndex];
            leftIndex++;
        }else{
            //Right is smaller
            list[auxIndex] = rightList[rightIndex];
            rightIndex++;
        }
        //Increment auxIndex
        auxIndex++;
    }


    //Empty values on left list
    while(leftIndex < leftList.size()){
        list[auxIndex] = leftList[leftIndex];
        leftIndex++;
        auxIndex++;
    }


    //Empty values on right list
    while(rightIndex <rightList.size()){
        list[auxIndex] = rightList[rightIndex];
        rightIndex++;
        auxIndex++;
    }

}


//------------------------- Merge Sort -------------------------
template <class T>
void mergeSort(vector<T> &list, int left, int right){
    
    if(left<right){
        int mid = left + (right-left)/2;
        //Ordenamos la lista del lado izquierdo
        mergeSort(list,left,mid);
        //Ordenamos la lista del lado derecho
        mergeSort(list,mid+1,right);
        
        //Merge both lists
        merge(list,left,mid,right);
    }
}


// Casos de prueba

// n = 10
// Lista desordenada: 5 3 2 1 4 6 7 8 9 10
// Lista ordenada: 1 2 3 4 5 6 7 8 9 10

// n = 5
// Lista desordenada: 5 4 3 2 1
// Lista ordenada: 1 2 3 4 5

// n = 7
// Lista desordenada: 1.3 4.5 2.3 6.7 3.4 7.8 8.9
// Lista ordenada: 1.3 2.3 3.4 4.5 6.7 7.8 8.9

// n = 3
// Lista desordenada: 4.5 3.4 2.3
// Lista ordenada: 2.3 3.4 4.5

// n = 1
// Lista desordenada: 1
// Lista ordenada: 1



int main()
{
    int n;
    cout << "Ingrese el tamaño de la lista a ordenar: ";
    cin >> n;

    vector<float> listaDesordenada(n);
    cout << "Ingrese los elementos de la lista a ordenar: ";
    for(int i = 0; i < n; i++)
    {
        cin >> listaDesordenada[i];
    }
    cout << "Lista desordenada: ";
    for(int i = 0; i < n; i++)
    {
        cout << listaDesordenada[i] << " ";
    }

    mergeSort(listaDesordenada, 0, n-1);
    printf("\nLista ordenada: ");
    for(int i = 0; i < n; i++)
    {
        cout << listaDesordenada[i] << " ";
    }

}
