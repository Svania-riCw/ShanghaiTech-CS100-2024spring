#include <cstddef> //std::size_t nullptr
#include <stdexcept> // std::out_of_range
#include <algorithm> //copy

class Dynarray {
private:
    std::size_t size_;
    int* data;

    void swap(Dynarray& k) noexcept {
        std::swap(size_, k.size_);
        std::swap(data, k.data);
    }

public:
    //默认构造函数
    Dynarray() : size_(0), data(nullptr) {}


    explicit Dynarray(std::size_t n) : size_(n), data(new int[n]()) {}  //零值化（）


    Dynarray(std::size_t n, int x) : size_(n), data(new int[n]) {
        std::fill(data, data + size_, x);
    }


    Dynarray(const int* begin, const int* end) 
        : size_(end - begin), data(new int[size_]) {
        std::copy(begin, end, data);
    }


    Dynarray(const Dynarray& p) 
        : size_(p.size_), data(new int[size_]) {
        std::copy(p.data, p.data + size_, data);
    }

    //右值引用
    Dynarray(Dynarray&& p) noexcept 
        : size_(p.size_), data(p.data) {
        p.size_ = 0;
        p.data = nullptr;
    }

    //析构函数
    ~Dynarray() {
        delete[] data;
    }

    //copy
    Dynarray& operator=(const Dynarray& p) {
        if (this != &p) {
            Dynarray temp(p); // 临时对象 p的副本
            swap(temp);  // 交换后临时对象temp会自动析构，保障异常安全
        }
        return *this;
    }

    //move
    Dynarray& operator=(Dynarray&& p) noexcept {
        if (this != &p) {
            delete[] data;
            size_ = p.size_;
            data = p.data;
            p.size_ = 0;
            p.data = nullptr;
        }
        return *this;
    }


    std::size_t size() const noexcept {
        return size_;
    }


    bool empty() const noexcept {
        return size_ == 0;
    }


    int& at(std::size_t n) {
        if (n >= size_) {
            throw std::out_of_range("Dynarray index out of range!");
        }
        return data[n];
    }

    // read-only
    const int& at(std::size_t n) const {
        if (n >= size_) {
            throw std::out_of_range("Dynarray index out of range!");
        }
        return data[n];
    }
};
