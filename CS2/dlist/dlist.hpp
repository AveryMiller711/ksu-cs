#ifndef DLIST_HPP
#define DLIST_HPP

template <typename T>
class dnode {
public:
        dnode()             : next(0), prev(0)          {};
        dnode(const T& x)   : data(x), next(0), prev(0) {};

    T data;
    dnode<T>    *next,
                *prev;
};

template <typename T> class List;

template <typename T>
class Itr {
public:
        Itr()               : current(0)    {};
        Itr(dnode<T> *ptr)  : current(ptr)  {};

    //++i preincrement
    Itr<T>& operator++();   {   if(current) current = current->next;
                                return *this;                       };
    //i++ postincrement (dummy int parameter)
    Itr<T>  operator++(int) {   Itr<T> result(current);
                                if(current) current = current->next;
                                return result;                      };
    //--i
    Itr<T>& operator--()    {   if(current) current = current->prev;
                                return *this;                       }; 
    //i-- (dummy int parameter)
    Itr<T>  operator--(int) {   Itr<T> result(current);
                                if(current) current = current->prev;
                                return result;                      }; 
    
    bool    operator==(Itr<T> rhs) { return current == rhs.current; };
    bool    operator!=(Itr<T> rhs) { return current != rhs.current; };

    T       operator* () const { return current->data; };
    T&      operator* ();      { return current->data; };

    const dnode<T>* operator->() const { return current; };
    dnode<T>*       operator->()       { return current; };

    friend class List<T>;

private:
    dnode<T> *current;
};

template <typename T>
class List {
public:
        List() : beginning(0), ending(0) {};
        ~List();
        List(const List<T>&);

    void swap(List<T>&);
    List<T>& operator=(List<T> rhs) { swap(rhs); return *this; };

    bool isEmpty () const { return beginning == 0; };
    bool isFull  () const;
    int  length  () const;

    Itr<T>       operator[](int);
    const Itr<T> operator[](int)      const;
    Itr<T>       find      (const T&);
    const Itr<T> find      (const T&) const;

    Itr<T>       begin()       { return Itr<T>(beginning); };
    const Itr<T> begin() const { return Itr<T>(beginning); };
    Itr<T>       end  ()       { return Itr<T> (ending);   };
    const Itr<T> end  () const { return Itr<T> (ending);   };

    T  front() const { return beginning->data; };
    T& front()       { return beginning->data; };
    T  back () const { return ending->data;    };
    T& back ()       { return ending->data;    };

    void remove      (Itr<T>);
    void insertBefore(Itr<T>, const T&);
    void insertAfter (Itr<T>, const T&);



private:
    dnode<T> *beginning, *ending;
};

template <typename T>
void List<T>::insertBefore(Itr<T> ptr, const T& item) {
    dnode<T> *temp = new dnode<T>(item);
    if(beginning == 0) { //Empty list
        beginning = temp;
        ending    = temp;
    } else if (ptr == beginning) { //Insert at beginning of list
        beginning->prev = temp;
        temp->next      = beginning;
        beginning       = temp;
    } else { //All other cases
        temp->next      = ptr.current;
        temp->prev      = ptr->prev;
        ptr->prev->next = temp;
        ptr->prev       = temp;
    }
}

template <typename T>
void List<T>::insertAfter(Itr<T> ptr, const T& item) {
    dnode<T> *temp = new dnode<T>(item);
    if(ending == 0) {
        beginning = temp;
        ending    = temp;
    } else if (ptr == ending) {
        ending->next    = temp;
        temp->prev      = ending;
        ending          = temp;
    } else {
        ptr->next->prev = temp;
        temp->next      = ptr->next;
        temp->prev      = ptr.current;
        ptr->next       = temp;
    }
}

template <typename T>
void List<T>::remove(Itr<T> ptr) {
    if(isEmpty()) return;
    if(ptr == 0)  return;

    if(ptr == beginning)
        beginning       = beginning->next;
    else
        ptr->prev->next = ptr->next;
    if(ptr == ending)
        ending          = ending->prev;
    else
        ptr->next->prev = ptr->prev;

    delete ptr.current;
}

template <typename T>
int List<T>::length() const {
    Itr<T> ptr = begin();
    int    len = 0;
    while(ptr != 0) {
        ++len;
        ++ptr;
    }
    return len;
}

template <typename T>
Itr<T> List<T>::operator[](int n) {
    if(n < 0) return Itr<T>();
    Itr<T> result = begin();
    int i = 0;
    while(i != n) {
        if(result == 0) break;
        ++result;
        ++i;
    }
    return result;
}

template <typename T>
const Itr<T> List<T>::operator[](int n) const {
    if(n < 0) return Itr<T>();
    Itr<T> result = begin();
    int i = 0;
    while(i != n) {
        if(result == 0) break;
        ++result;
        ++i;
    }
    return result;
}

template <typename T>
Itr<T> List<T>:: find(const T& key) {
    Itr<T> result(beginning);
    while(result != 0) {
        if(result->data == key) return result;
        ++result;
    }
    return Itr<T>();
}

template <typename T>
const Itr<T> List<T>:: find(const T& key) const {
    Itr<T> result(beginning);
    while(result != 0) {
        if(result->data == key) return result;
        ++result;
    }
    return Itr<T>();
}

template <typename T>
bool List<T>::isFull() const {
    dnode<T> *temp = new(std::nothrow) dnode<T>();
    if(temp == 0) return true;
    delete temp;
    return false;
}

template <typename T>
List<T>::~List() {
    dnode<T> *temp;
    while(beginning != 0) {
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

template <typename T>
List<T>::List(const List<T>& actual) : List() {
    Itr<T> temp = actual.beginning;
    while(temp != 0) {
        if(beginning == 0) { //Empty
            beginning = new dnode<T>(temp->data);
            ending = beginning;
        } else {
            ending->next = new dnode<T>(temp->data);
            ending->next->prev = ending;
            ending = ending->next;
        }
        ++temp;
    }
}

template <typename T>
void List<T>::swap(List<T>& rhs) {
    dnode<T> *temp = beginning;
    beginning = rhs.beginning;
    rhs.beginning = temp;
    temp = ending;
    ending = rhs.ending;
    rhs.ending = temp;
}

#endif