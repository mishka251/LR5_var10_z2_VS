#include <iostream>

struct List {
    int value;
    List* next;
    List* prev;
};


List* first;

void initList() {
    int n;
    std::cout << "elements count" << std::endl;
    std::cin >> n;
    int a;
    first = new List();
    List* last = first;
    for (int i = 0; i < n; ++i) {
        std::cout << "item " << i << " = ";
        std::cin >> a;
        last->value = a;
        if (i < n - 1) {
            List* newItem = new List();
            last->next = newItem;
            newItem->prev = last;
            last = last->next;
        }
    }
}

void printList() {
    List* last = first;
    while (last != nullptr) {
        std::cout << last->value << "  ";
        last = last->next;
    }
    std::cout << std::endl;
}

void moveToRight() {
    List* end = first;
    while (end->next != nullptr) {
        end = end->next;
    }

    int k;
    std::cout << "k = ";
    std::cin >> k;

    if (k <= 0) {
        std::cout << "Error k<=";
        return;
    }

    end->next = first;
    first->prev = end;

    for (int i = 0; i < k; i++) {
        first = first->next;
    }

    first->prev->next = nullptr;
    first->prev = nullptr;
}

int main() {
    initList();
    printList();
    moveToRight();
    printList();
    return 0;
}