#ifndef DLIST_HPP
#define DLIST_HPP

template <typename T>
class dnode {
public:
    dnode() : next(0), prev(0) {};
    dnode(const T& x) : data(x), next(0), prev(0) {};
    T data;
    dnode<T> *next
            *prev;
};

template <typename T>
class Itr {
public:
    Itr() : current(0) {};
    Itr(dnode<T> *ptr) : current(ptr) {};
    Itr<T>& operator++(); //++i
    Itr<T> operator++(int); //i++
    Itr<T>& operator--(); //--i
    Itr<T> operator--(int); //i--
    T operator*() const;
    T& operator*();
    conse dnode<T>* operator->() const;
    dnode<T>* operator->();

private:
    dnode<T> *current;
};

template <typename T>
class List {
public:

private:
    dnode<T> *beginning, *ending;
};

#endif