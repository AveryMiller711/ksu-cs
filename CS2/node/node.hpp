template <typename T>
class node {
public:
    node()  : next(0) {};
    node(const T& x)    : data(x), next(0) {};
    T data;
    node <T>* next;
};