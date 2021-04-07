#ifndef BTREEV2_HPP_
#define BTREEV2_HPP_

#include <iostream>

template <typename T>
class btree {
public:
              btree () : root(0) {};
              btree (const btree<T>&);
              ~btree();
    void      swap  (btree<T>&);
    btree<T>& operator=(btree<T> rhs) { swap(rhs); return *this; };

    bool      isEmpty  () const { return root; };
    bool      isFull   () const;
    void      binsert  (const T&);
    bool      find     (const T&) const;
    void      bremove  (const T&);
    void      inorder  (std::ostream&) const;
    void      preorder (std::ostream&) const;
    void      postorder(std::ostream&) const;

private:
    bnode<T> *root;
};

template <typename T>
class bnode {
public:
              bnode      () : left(0), right(0) {};
              bnode      (const T& item) : left(0), right(0), data(item) {};
              bnode      (const bnode<T>&);
              ~bnode     ();
    bool      find       (const T&) const;
    void      binsert    (const T&);
    bnode<T>* bremove    (const T&);
    T         predecessor() const;

private:
    bnode<T> *left;
    bnode<T> *right;
    T        data;
};

template <typename T>
bool btree<T>::find(const T& key) const {
    if(!root) return false;
    return root->find(key);
}

template <typename T>
bool bnode<T>::find(const T& key) const {
    if(key == data) return true;
    if(key < data) {
        if(left) return left->find(key);
        else return false;
    } else {
        if(right) return right->find(key);
        else return false;
    }
}

template <typename T>
void btree<T>::binsert(const T& x){
    if(!root) root = new bnode<T>(x);
    else root-binsert(x);
}

template <typename T>
void bnode<T>::binsert(const T& x){
    if(x < data) {
        if(left) left->binsert(x);
        else left = new bnode<T>(x);
    } else {
        if(x == data) return;
        if(right) right->binsert(x);
        else right = new bnode<T>(x);
    }
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const{
    if(root) root->inorder(out);
}

template <typename T>
void bnode<T>::inorder(std::ostream& out) const{
    if(left) left-inorder(out);
    out << data << "";
    if(right) right->inorder(out);
}

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree() {
    if(actual.root)
        root = new bnode<T>(*(actual.root));
}

//4.5.2021
template <typename T>
btree<T>::bnode(const bnode<T>& actual) : bnode() {

}

template <typename T>
btree<T>::~btree() {
    if(root) delete root;
}

template <typename T>
bnode<T>::~bnode() {
    if(left) delete left;
    if(right) delete right;
    //Compiler cleans up the rest
}

template <typename T>
T bnode<T>::predecessor() const {
    if(right) return right->predecessor();
    return data;
}

template <typename T>
void btree<T>::bremove(const T& x) {
    if(find(x)) root = root->bremove(x);
}

template <typename T>
bnode<T>* bnode<T>::bremove(const T& x) {
    if(x == data) {
        if(!left && !right) { //No children
            delete this;
            return 0;
        }
        if(!left && right) { //Right child only
            bnode<T> *temp = right;
            right = 0;
            delete this;
            return temp;
        }
        if(left && !right) { //Left child only
            bnode<T> *temp = left;
            left = 0;
            delete this;
            return temp;
        }
        data = left->predecessor(); //Two children
        left = left-bremove(data);
        return this;
    } else {
        if(x < data)
            left = left->bremove(x);
        else
            right = right->bremove(x);
    }
    return this;
}

#endif