#include "pch.h"
#include "Heap.h"

Heap::Heap() {
    heap = new int[SIZE];
    HeapSize = 0;
}

void Heap::InsertElement(int newValue) {
    int index, parentElementIndex;
    index = HeapSize;
    heap[index] = newValue;
    parentElementIndex = (index - 1) / 2;
    while (parentElementIndex >= 0 && index > 0) {
        if (heap[index] > heap[parentElementIndex]) {
            int temp = heap[index];
            heap[index] = heap[parentElementIndex];
            heap[parentElementIndex] = temp;
        }
        index = parentElementIndex;
        parentElementIndex = (index - 1) / 2;
    }
    HeapSize++;
}

void Heap::OutputHeap(void) {
    int index = 0;
    int childIndex = 1;
    while (index < HeapSize) {
        while ((index < childIndex) && (index < HeapSize)) {
            std::cout << heap[index] << " ";
            index++;
        }
        std::cout << std::endl;
        childIndex = childIndex * 2 + 1;
    }
}

void Heap::Heapify(int i) {
    int left, right;
    int temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < HeapSize) {
        if (heap[i] < heap[left]) {
            temp = heap[i];
            heap[i] = heap[left];
            heap[left] = temp;
            Heapify(left);
        }
    }
    if (right < HeapSize) {
        if (heap[i] < heap[right]) {
            temp = heap[i];
            heap[i] = heap[right];
            heap[right] = temp;
            Heapify(right);
        }
    }
}

int Heap::GetAndDeleteMaxElement(void) {
    int indexMaxElement = 0;
    int maxElement = heap[indexMaxElement];
    heap[indexMaxElement] = heap[HeapSize - 1];
    HeapSize--;
    Heapify(indexMaxElement);
    return(maxElement);
}

void Heap::UpdateElement(int indexElemForUpdate, int updateValue) {
    if (indexElemForUpdate > HeapSize) {
        std::cout << "Index out of range this heap =)" << std::endl;
        return;
    }
    int parentIndexElemForUpdate = (indexElemForUpdate - 1) / 2;
    heap[indexElemForUpdate] = updateValue;
    Heapify(parentIndexElemForUpdate);
}