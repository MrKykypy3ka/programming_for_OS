#include <iostream>
using namespace std;

class Queue {
    private:
        int* data; // массив для хранения данных очереди
        int size; // размер массива
        int front; // индекс первого элемента в очереди
        int rear; // индекс последнего элемента в очереди
    public:
        Queue() { // конструктор по умолчанию
            size = 10; // начальный размер очереди равен 10
            data = new int[size];
            front = -1;
            rear = -1;
        }
        Queue(int n) { // конструктор с параметром
            size = n;
            data = new int[size];
            front = -1;
            rear = -1;
        }
        ~Queue() { // деструктор
            delete[] data;
        }
        bool isEmpty() {
            return front == -1 && rear == -1;
        }
        bool isFull() {
            return (rear + 1) % size == front;
        }
        void add(int item) {
            if (isFull()) {
                // увеличиваем размер очереди в два раза
                int* newData = new int[size * 2];
                int j = 0;
                for (int i = front; i <= rear; i = (i + 1) % size) {
                    newData[j] = data[i];
                    j++;
                }
                delete[] data;
                data = newData;
                front = 0;
                rear = j - 1;
                size *= 2;
            }
            if (isEmpty()) {
                front = 0;
                rear = 0;
                data[rear] = item;
            }
            else {
                rear = (rear + 1) % size;
                data[rear] = item;
            }
        }
        void remove() {
            if (isEmpty()) {
                cout << "Очередь пуста" << endl;
            }
            else if (front == rear) {
                cout << "Удален элемент: " << data[front] << endl;
                front = -1;
                rear = -1;
            }
            else {
                cout << "Удален элемент: " << data[front] << endl;
                front = (front + 1) % size;
            }
        }
        void print() {
            if (isEmpty()) {
                cout << "Очередь пуста" << endl;
            }
            else {
                cout << "Очередь: ";
                for (int i = front; i <= rear; i = (i + 1) % size) {
                    cout << data[i] << " ";
                }
                cout << endl;
            }
        }
    };