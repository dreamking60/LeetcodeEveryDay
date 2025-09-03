#include <iostream>
using namespace std;

// Operations for reference counting
template<typename T>
class ShareCount {
    private:
        T * ptr; // Point to the actual object
        int count; // Reference count

        // Forbid copy constructor and assignment operator
        ShareCount(const ShareCount&) = delete;
        ShareCount& operator=(const ShareCount&) = delete;

    public:
        ShareCount(T *p) : ptr(p), count(1) {}
       ~ShareCount() {
            delete ptr;
        }
         
        // Increment reference count
        void increment() {count++;}

        // Decrement reference count and delete if it reaches zero
        void decrement() {
            if(--count == 0) {
                delete this;
            }
        }

        // Get the ptr
        T* get() const {
            return ptr;
        }
};

template<typename T>
class SharePtr {
    private:
        T *ptr; // Point to the actual object
        ShareCount<T> *countPtr; // Organize the reference count

    public:
        SharePtr(T *p = nullptr) : ptr(p) {
            if(p) {
                countPtr = new ShareCount<T>(p);
            } else {
                p = nullptr;
            }
        }
        
        // Copy constructor
        SharePtr(const SharePtr &other) : ptr(other.ptr), countPtr(other.countPtr) {
            if(countPtr) {
                countPtr->increment();
            }
        }

        // Move constructor
        SharePtr(SharePtr && other) : ptr(other.ptr), countPtr(other.countPtr) {
            other.ptr = nullptr;
            other.countPtr = nullptr;
        }

        // Destructor
        ~SharePtr() {
            if(countPtr) {
                countPtr->decrement();
            }
        }

        T* operator->() const {
            return ptr;
        }

        T& operator*() const {
            return *ptr;
        }

        // Reset
        void reset(T* p = nullptr) {
            if(p != ptr) {
                if(countPtr) {
                    countPtr->decrement();
                }
            }

            ptr = p;
            if(p) {
                countPtr = new ShareCount<T>(p);
            } else {
                countPtr = nullptr;
            }

        }

        // Get the original ptr
        T* get() const {
            return ptr;
        }
};

int main() {
    SharePtr<int> p1(new int(10));
    SharePtr<int> p2 = p1; // Copy constructor

    cout << "p1: " << *p1 << endl; // Output: 10
    cout << "p2: " << *p2 << endl; // Output: 10

    p1.reset();
    cout << "p2 after p1 reset: " << *p2 << endl; // Output: 10

    SharePtr<int> p3 = std::move(p2);
    cout << "p3 after move: " << *p3 << endl; // Output: 10
    //cout << "p2 after move: " << *p2 << endl; // Undefined behavior

    return 0;
}