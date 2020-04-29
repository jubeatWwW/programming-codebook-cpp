#include "rearrangement.h"

namespace rearrangement {
    // https://www.geeksforgeeks.org/rearrange-array-arri/
    template<class T, class LN = int>
    void rearrange_array_with_index(T arr[], LN n) {
        set<T> s;
        for (LN i = 0; i < n; i += 1) {
            s.insert(arr[i]);
        }

        for (LN i = 0; i < n; i += 1) {
            arr[i] = s.find(i) != s.end() ? i : -1;
        }
    }

    template<class T, class LN = int>
    void reverse_iterative(T arr[], LN n) {
        LN mid = n / 2;
        for (LN i = 0; i < mid - 1; i += 1) {
            swap(arr[i], arr[n - 1 - i]);
        }
    }
    
    void reverse_iterative(string str) {
        auto len = str.length();
        auto mid = len / 2;
        for (size_t i = 0; i < mid - 1; i += 1) {
            swap(str[i], str[len - 1 - i]);
        }
    }

    template<class T, class LN = int>
    void reverse(T arr[], LN begin, LN end) {
        if (begin >= end) {
            return;
        }

        swap(arr[begin], arr[end]);
        reverse(arr, begin + 1, end - 1);
    }

    template<class LN = int>
    void reverse(string str, LN begin, LN end) {
        if (begin >= end) {
            return;
        }

        swap(str[begin], str[end]);
        reverse(str, begin + 1, end - 1);
    }

    template<class T, class LN = int>
    void reverse_recursive(T arr[], LN n) {
        reverse(arr, 0, n - 1);
    }

    void reverse_recursive(string str) {
        reverse(str, (size_t)0, str.length() - 1);
    }

    // https://www.geeksforgeeks.org/rearrange-array-arri-arrj-even-arri/
    template<class T, class LN = int>
    T* rearrange_by_odd_even(T arr[], LN n) {
        sort(arr, arr + n);

        T* new_arr = new T[n];

        LN odd_pos = n % 2 ? n - 2 : n - 1;
        LN even_pos = 0;

        for (LN i = 0; i < n / 2; i += 1) {
            new_arr[odd_pos] = arr[i];
            odd_pos -= 2;
            new_arr[even_pos] = arr[(n / 2) + i];
            even_pos += 2;
        }

        if (n % 2) {
            new_arr[even_pos] = arr[n - 1];
        }

        return new_arr;
    }
}