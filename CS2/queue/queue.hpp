//
//

//CLASS INV: beginning -> x1 -> x2 -> ... xN <- ending
//
template <typename T>
class queue {
public:
                queue       () : beginning(0), ending(0) {};
                ~queue      ();
                queue       (const queue<T>&);
    void        swap        (queue<T>&);
    queue<T>&   operator=   (queue<T>rhs) { swap(rhs); return *this; };
    bool        isEmpty     () const { return beginning == 0; };
    bool        isFull      () const;
    void        enqueue     (const T&);
    T           dequeue     ();
    T           front       () const { assert(!isEmpty()); return beginning->data; };

private:
    node<T> *beginning, *ending;
};

//REQUIRES: beginning -> x1 -> ... -> xN <- ending
//ENSURES: beginning -> x1 -> ... -> xN -> item <- ending
template <typename T>
void queue<T>::enqueue(const T& item) {
    assert(!isFull());
    if(ending == 0) {
        ending = new node<T>(item);
        beginning = ending;
    } else {
        ending->next = new node<T>(item);
        ending = ending->next;
    }
}

//REQUIRES: beginning -> x1 -> ... -> xN <- ending
//ENSURES: beginning -> x1 -> ... -> xN <- ending && RETVAL == x1
template <typename T>
T queue<T>::dequeue() {
    assert(!isEmpty());
    T result = beginning->data;
    node<T> *temp = beginning;
    beginning = beginning->next;
    if(beginning == 0) ending = 0; //Empty queue
    delete temp;
    return result;
}

template <typename T>
queue<T>::~queue() {
    node<T> *temp;
    while(beginning != 0) {
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}