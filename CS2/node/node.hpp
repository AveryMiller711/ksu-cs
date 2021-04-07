// Linked Lists

#include <iostream>

template <typename T>
class node {
public:
        node()              : next(0) {};
        node(const T& x)    : data(x), next(0) {};
    T data;
    node <T>* next;
};

//CLASS INV: tos -> x1 -> x2 -> ... -> xN -> 0
template <typename T>
class stack {
public:
            stack() : tos(0) {};
            ~stack();
            stack(const stack&);
    stack&  operator=(stack rhs) { swap(rhs); return *this; };
    void    swap(stack&);
    bool    isEmpty() const { return tos == 0; };
    bool    isFull() const;
    T       pop();
    T       top() const { assert(!isEmpty()); return tos->data; };
    void    push(const T&);
private:
    node<T> *tos;
};

//REQUIRES: tos -> x1 -> x2 -> ... -> xN -> 0
//ENSURE: tos -> item -> x1 -> ... -> xN -> 0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}

template <typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
stack<T>::~Stack() {
    node<T> *temp;
    while(tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {
    node<T> *temp = actual.tos;
    node<T> *bottom;
    while(temp != 0) {
        if(tos == 0) {
            tos = new node<T>(temp->data);
            bottom = tos;
        } else {
            bottom->next = new node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template <typename T>
void stack<T>::swap(stack& rhs) {
    node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node<T>();
    if(temp == 0) return true;  //No more memory to allocate
    delete temp;
    return false;
}

int main() {

    node<int> *ptr;

    ptr = new node<int>(10);
    ptr->next = new node<int>(20);
    ptr->next->next = new node <int>(30);

    node<int> *temp, *temp2;

    temp = ptr;
    while(temp != 0) {
        std::cout << temp->next;
        temp2 = temp;
        temp = temp->next;
        delete temp2;
    }

    return 0;
}