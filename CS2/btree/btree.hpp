
#ifndef BTREE_HPP_
#define BTREE_HPP_

#include <iostream>

template <typename T>
class btree {
public:
              btree () : left(0), right(0), empty(true) {};
              btree (const T& item) : left(0), right(0), empty(false), data(item) {};
              ~btree();
              btree (const btree<T>&);
    void      swap  (btree<T>&);
    btree<T>& btree (btree<T> rhs) { swap(rhs); return *this; };

    bool      isEmpty  () const { return empty; };
    bool      isFull   () const;
    void      binsert  (const T&);
    bool      find     (const T&);
    void      inorder  (std::ostream&) const;
    void      preorder (std::ostream&) const;
    void      postorder(std::ostream&) const;

private:
    btree<T> *left, *right;
    bool     empty;
    T        data;
};

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree<T>(){
    data = actual.data;
    empty = actual.empty;
    if(actual.left) left = new btree<T>(*(actual.left));
    if(actual.right) right = new btree<T>(*(actual.right));
}

template <typename T>
btree<T>::~btree(){
    if(left) delete left;
    if(right) delete right;
    //Compiler cleans up *this;
}

template <typename T>
void btree<T>::swap(btree<T>& rhs){
    T temp = data;
    data = rhs.data;
    rhs.data = temp;
    bool tempty = empty;
    empty = rhs.empty;
    rhs.empty = tempty;

    btree<T> *ptr = left;
    left = rhs.left;
    rhs.left = ptr;
    ptr = right;
    right = rhs.right;
    rhs.right = ptr;
}

template <typename T>
bool btree<T>::isFull() const{

}

template <typename T>
void btree<T>::binsert(const T& x){
    if(empty) {
        data = x;
        empty = false;
    } else if (x < data){
        if(!left) left = new btree<T>(x);
        else left->binsert(x);              //(*left).binsert(x);
    } else {
        if(data == x) return;
        if(!right) right = new btree<T>(x);
        else right->binsert(x);
    }
}

template <typename T>
bool btree<T>::find(const T& key){
    if(empty) return false;
    if(key == data) return true;
    if(key < data)
        if(left) return left->find(key) else return false;
    else
        if(right) return right->find(key) else return false;
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const{
    if(empty) return;
    if(left) left->inorder(out);
    out << data << " ";
    if(right) right->inorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const{
    if(empty) return;
    out << data << " ";
    if(left) left->preorder(out);
    if(right) right->preorder(out);
}

template <typename T>
void btree<T>::postorder(std::ostream& out) const{
    if(empty) return;
    if(left) left->postorder(out);
    if(right) right->postorder(out);
    out << data << " ";
}


#endif