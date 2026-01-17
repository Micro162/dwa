#include <iostream>

using namespace std;


template <typename T>
class Stack {
private:
    
    struct Node {
        T data;      
        Node* next;  
    };

    Node* top; 

public:
    // Конструктор
    Stack() {
        top = nullptr; 
    }

   
    ~Stack() {
        while (top != nullptr)
            pop();
    }

    void push(const T& value) {
        Node* temp = new Node; 
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == nullptr) return; 

        Node* temp = top;
        top = top->next;
        delete temp;
    }

 
    T peek() const {
        return top->data;
    }

    // Проверка 
    bool isEmpty() const {
        return top == nullptr;
    }

  
    void print() const {
        Node* cur = top;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.print(); 

    s.pop();
    s.print(); 

    cout << "Top: " << s.peek() << endl;

    return 0;
}
