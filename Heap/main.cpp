#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos elementos en un vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para insertar un elemento en un heap
void insertIntoHeap(vector<int>& heap, int element) {
    // Agregamos el nuevo elemento al final del heap
    heap.push_back(element);
    int idx = heap.size() - 1; // Índice del nuevo elemento

    // Realizamos un bucle para asegurarnos de que el heap property se mantenga
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        // Si el padre es menor que el nuevo elemento, intercambiamos
        swap(heap, idx, (idx - 1) / 2);
        // Actualizamos el índice al del padre
        idx = (idx - 1) / 2;
    }
}

int main() {
    vector<int> heap;

    // Insertamos algunos elementos en el heap
    insertIntoHeap(heap, 10);
    insertIntoHeap(heap, 20);
    insertIntoHeap(heap, 15);
    insertIntoHeap(heap, 40);
    insertIntoHeap(heap, 50);
    insertIntoHeap(heap, 100);

    // Imprimimos el heap
    cout << "Heap: ";
    for (int num : heap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}