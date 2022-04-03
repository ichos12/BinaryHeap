#include "pch.h"
#include "Heap.h"

using namespace std;

Heap ReadData()
{
    fstream fileInput("input.txt");
    Heap heap;
    int elem;
    int size;
    fileInput >> size;
    for (int i = 0; i < size; i++) {
        fileInput >> elem;
        heap.InsertElement(elem);
    }
    heap.Heapify(0);
    return heap;
}

int main(int argc, char** argv) {
    Heap heap = ReadData();
    std::cout << std::endl;
    heap.OutputHeap();
    std::cout << std::endl;
    heap.UpdateElement(5, 57);

    std::cout << std::endl << "Max element: " << heap.GetAndDeleteMaxElement();
    std::cout << std::endl << "Update heap: " << std::endl;
    heap.OutputHeap();
    return 0;
}