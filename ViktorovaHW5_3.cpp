#include <iostream>

const int N = 4;
struct Queue {
    int data[N];
    int last;
};
void Creation(Queue* Q) { Q->last = 0; }
bool Full(Queue* Q) {
    if (Q->last == 0) {
        return true;
    }
    else {
        return false;
    }
}
void Add(Queue* Q) {
    if (Q->last == N) {
        std::cout << std::endl << "Queue is full" << std::endl;
        return;
    }
    int value;
    std::cout << std::endl << "Element value is -->";
    std::cin >> value;
    Q->data[Q->last++] = value;
    std::cout << std::endl << "Element was added to queue" << std::endl;
}
void Delete(Queue* Q) {
    for (int i = 0; i < Q->last && i < N; i++) {
        Q->data[i] = Q->data[i + 1];
        Q->last--;
    }
}
int Top(Queue* Q) { return Q->data[0]; }
int Size(Queue* Q) { return Q->last; }

int main() {
    Queue Q;
    Creation(&Q);
    char number{};
    while (true) {
        std::cout << "1. Add the element" << std::endl;
        std::cout << "2. Delete the element" << std::endl;
        std::cout << "3. Display top element" << std::endl;
        std::cout << "4. Find out the queue size" << std::endl;
        std::cout << "0. Exit\n";
        std::cout << " Command number ";

        std::cin >> number;
        switch (number) {
        case '1':
            Add(&Q);
            break;

        case '2':
            if (Full(&Q)) {
                std::cout << std::endl << "Queue is empty" << std::endl;
            }
            else {

                Delete(&Q);
                std::cout << std::endl
                    << "Element was deleted from the queue" << std::endl;
            }
            break;

        case '3':
            if (Full(&Q)) {
                std::cout << std::endl << "Queue is empty" << std::endl;
            }
            else {
                std::cout << std::endl << "Top element " << Top(&Q) << std::endl;
            }
            break;

        case '4':
            if (Full(&Q)) {
                std::cout << std::endl << "Queue is empty" << std::endl;
            }
            else {
                std::cout << std::endl << "Queue size is: " << Size(&Q) << std::endl;
            }
            break;

        case '0':
            break;
        default:
            std::cout << std::endl << "Command isn`t defined";
            break;
        }
    }
    return 0;
}
