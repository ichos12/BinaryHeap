#pragma once

class Heap {
    int* heap;
    int HeapSize;
public:
    static const int SIZE = 100;
    Heap();
    void InsertElement(int);
    void OutputHeap();
    int GetAndDeleteMaxElement();
    void UpdateElement(int, int);
    void Heapify(int);
};