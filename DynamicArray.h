#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

template<typename T> class DynamicArray; //En caso de no compilar

template <typename T>
std::ostream& operator <<(std::ostream &o, const DynamicArray<T> &a);

template <typename T>
class DynamicArray {
        int size;  
        T *arr;
        void resize(int newSize);
    public:
        DynamicArray();
        DynamicArray(const T* ptr, int size);
        DynamicArray(const DynamicArray &o);
        void push_back(T elem); 
        void insert(T elem, int pos);
        void remove(int pos);
        int getSize() const {
            return size;
        }
        void clear();
        void print() const;

        ~DynamicArray();
        friend std::ostream& operator<< <>(std::ostream &o, const DynamicArray<T> &a);
};
template <typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    arr = new T[0];
}
template <typename T>
DynamicArray<T>::DynamicArray(const T*ptr, int size) {
    this->size = size;
    this->arr = new T[size];

    for(int i = 0; i < size; i++)
        arr[i] = ptr[i];
}
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &o) {
    this->size = o.size;
    this->arr = new T[o.size];

    for(int i = 0; i < size; i++)
        arr[i] = o.arr[i];
}
template <typename T>
void DynamicArray<T>::resize(int newSize){
    int *tmp = new T[newSize];
    int minSize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minSize; i++)
        tmp[i] = arr[i];
    delete[]arr;
    size = newSize;
    arr=tmp;
}
template <typename T>
void DynamicArray<T>::push_back(T elem) {
    resize(size+1);
    arr[size-1]=elem;
}
template <typename T>
void DynamicArray<T>::insert(T elem,int pos){
    resize(size+1);
    for(int i=size;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=elem;
}
template <typename T>
void DynamicArray<T>::remove(int pos){
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    resize(size-1);
}
template <typename T>
void DynamicArray<T>::clear(){
    resize(0);
}
template <typename T>
void DynamicArray<T>::print() const {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete []arr;
}
template <typename T>
std::ostream& operator << (std::ostream &o, const DynamicArray<T> &a){
    for(int i=0;i<a.getSize();i++){
        o << a.arr[i] <<" ";
    }
    o <<'\n';
    return o;
}
#endif