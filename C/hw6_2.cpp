#include <iostream>
#include <algorithm>
#include <stdexcept>  // 用于 std::out_of_range
#include <string>

class Dynarray {
private:
    std::size_t _size;
    int* _data; 

    void swap(Dynarray& k) noexcept {
        std::swap(_size, k._size);
        std::swap(_data, k._data);
    }

public:
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    using const_pointer = const int*;
    using const_reference = const int&;

    Dynarray() : _size(0), _data(nullptr) {}

    explicit Dynarray(size_type n) : _size(n), _data(new value_type[n]{}) {}

    Dynarray(size_type n, value_type x) : _size(n), _data(new value_type[n]) {
        std::fill(_data, _data + _size, x);
    }

    Dynarray(const const_pointer begin, const const_pointer end) 
        : _size(end - begin), _data(new value_type[_size]) {
        std::copy(begin, end, _data);
    }

    Dynarray(const Dynarray& other) : _size(other._size), _data(new value_type[_size]) {
        std::copy(other._data, other._data + _size, _data);
    }

    Dynarray(Dynarray&& other) noexcept : _size(other._size), _data(other._data) {
        other._data = nullptr;
        other._size = 0;
    }

    ~Dynarray() {
        delete[] _data;
    }

    Dynarray& operator=(const Dynarray& p) {
        if (this != &p) {
            Dynarray temp(p); // 临时对象 p的副本
            swap(temp);  // 交换后临时对象temp会自动析构
        }
        return *this;
    }

    Dynarray& operator=(Dynarray&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            other._data = nullptr;
            other._size = 0;
        }
        return *this;   
    }

    // 提供公共接口访问 _data
    const_pointer data() const {
        return _data;
    }

    reference operator[](size_type i) {
        return _data[i];
    }

    const_reference operator[](size_type i) const {
        return _data[i];
    }

    size_type size() const noexcept {
        return _size;
    }

    bool empty() const noexcept {
        return _size == 0;
    }

    int& at(size_type n) {
        if (n >= _size) {
            throw std::out_of_range("Dynarray index out of range!");
        }
        return _data[n];
    }

    const int& at(size_type n) const {
        if (n >= _size) {
            throw std::out_of_range("Dynarray index out of range!");
        }
        return _data[n];
    }

    // 输出字符串 e.g [1, 2, 3, 5]
    std::string output() const {
        std::string a = "[";
        for (size_t i = 0; i < _size; ++i) {
            a += std::to_string(_data[i]); // 将int转为string
            if(i != _size - 1){
                a += ", ";
            }
        }
        a += "]";
        return a;
    }
};

// 全局比较操作符 在类外，有两个参数
bool operator==(const Dynarray& lhs, const Dynarray& rhs) {
    return std::equal(lhs.data(), lhs.data() + lhs.size(), rhs.data(), rhs.data() + rhs.size());
}

bool operator<(const Dynarray& lhs, const Dynarray& rhs) {
    return std::lexicographical_compare(lhs.data(), lhs.data() + lhs.size(), rhs.data(), rhs.data() + rhs.size());
}

bool operator!=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(lhs == rhs);
}

bool operator>(const Dynarray& lhs, const Dynarray& rhs) {
    return rhs < lhs;
}

bool operator<=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Dynarray& lhs, const Dynarray& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const Dynarray& arr) {
    os << arr.output();
    return os;
}



