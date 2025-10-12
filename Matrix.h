/**
 * @brief Шаблонный класс одномерного массива.
 */

#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

namespace miit {
    namespace algebra {

        template<typename T>
        class Matrix
        {
        private:
            T* data;
            size_t size;

        public:
            Matrix();
            explicit Matrix(size_t sz);
            Matrix(const Matrix& other);
            Matrix& operator=(const Matrix& other);
            ~Matrix();

            T& operator[](size_t index);
            const T& operator[](size_t index) const;

            void fill(const T& value);
            std::string toString() const;

            size_t getSize() const { return size; }
        };


        template<typename T>
        Matrix<T>::Matrix() : data(nullptr), size(0) {}

        template<typename T>
        Matrix<T>::Matrix(size_t sz) : size(sz)
        {
            if (size > 0) {
                data = new T[size];
            }
            else {
                data = nullptr;
            }
        }

        template<typename T>
        Matrix<T>::Matrix(const Matrix& other) : size(other.size)
        {
            if (size > 0) {
                data = new T[size];
                for (size_t i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }
        }

        template<typename T>
        Matrix<T>& Matrix<T>::operator=(const Matrix& other)
        {
            if (this != &other) {
                delete[] data;
                size = other.size;
                if (size > 0) {
                    data = new T[size];
                    for (size_t i = 0; i < size; ++i) {
                        data[i] = other.data[i];
                    }
                }
                else {
                    data = nullptr;
                }
            }
            return *this;
        }

        template<typename T>
        Matrix<T>::~Matrix()
        {
            delete[] data;
        }

        template<typename T>
        T& Matrix<T>::operator[](size_t index)
        {
            if (index >= size) throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        template<typename T>
        const T& Matrix<T>::operator[](size_t index) const
        {
            if (index >= size) throw std::out_of_range("Index out of bounds");
            return data[index];
        }

        template<typename T>
        void Matrix<T>::fill(const T& value)
        {
            for (size_t i = 0; i < size; ++i) {
                data[i] = value;
            }
        }

        template<typename T>
        std::string Matrix<T>::toString() const
        {
            std::ostringstream oss;
            for (size_t i = 0; i < size; ++i) {
                oss << data[i];
                if (i != size - 1) oss << " ";
            }
            return oss.str();
        }

    }
} 
