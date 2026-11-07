#include "heap.h"
#include <utility>

Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end)
    : heapData(start, end) {
    int size = heapData.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        int parent = i;
        while (2 * parent + 1 < size) {
            int child = 2 * parent + 1;
            if (child + 1 < size && heapData[child + 1] < heapData[child]) {
                child++;
            }
            if (heapData[parent] <= heapData[child]) {
                break;
            }
            std::swap(heapData[parent], heapData[child]);
            parent = child;
        }
    }
}

void Heap::push(int value) {
    heapData.push_back(value);
    int child = heapData.size() - 1;
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (heapData[parent] <= heapData[child]) {
            break;
        }
        std::swap(heapData[parent], heapData[child]);
        child = parent;
    }
}

void Heap::pop() {
    if (heapData.empty()) {
        return;
    }
    heapData[0] = heapData.back();
    heapData.pop_back();
    int size = heapData.size();
    int parent = 0;
    while (2 * parent + 1 < size) {
        int child = 2 * parent + 1;
        if (child + 1 < size && heapData[child + 1] < heapData[child]) {
            child++;
        }
        if (heapData[parent] <= heapData[child]) {
            break;
        }
        std::swap(heapData[parent], heapData[child]);
        parent = child;
    }
}

int Heap::top() {
    return heapData.at(0);
}

bool Heap::empty() {
    return heapData.empty();
}
