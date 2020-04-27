#ifndef H_ARRAY_ROTATION_HPP
#define H_ARRAY_ROTATION_HPP

#include <cstdio>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

#define MAKE_FUNC(NAME) template<typename T, typename LN = int> \
    void NAME(T* arr, LN d, LN n)

namespace array_rotation {
    void print_test(void);

    template<typename T, typename LN = int>
    using func_type = void (*)(T*, LN, LN);

    template<typename T>
    using func_map = unordered_map<string, func_type<T>>;

    // https://www.geeksforgeeks.org/array-rotation/
    MAKE_FUNC(using_temp_array) {
        d = d % n;

        T tmp[d];
        for (LN i = 0; i < n; i++) {
            if (i < d) {
                tmp[i] = arr[i];
            } else {
                arr[i - d] = arr[i];
            }

            if (i >= n - d) {
                arr[i] = tmp[i - (n - d)];
            }
        }
    }

    // https://www.geeksforgeeks.org/array-rotation/
    MAKE_FUNC(one_by_one) {
        d = d % n;

        for (LN i = 0; i < d; i++) {
            T tmp = arr[0];
            for (LN j = 0; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = tmp;
        }
    }

    template<typename LN>
    LN gcd(LN a, LN b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // https://www.geeksforgeeks.org/array-rotation/
    MAKE_FUNC(juggling) {
        d = d % n;
        LN split_set = gcd(n, d);

        for (LN i = 0; i < split_set; i++) {
            T tmp = arr[i];

            LN prev = i, next = (i + d) % n;
            while (i != next) {
                arr[prev] = arr[next];
                prev = next;
                next = (next + d) % n;
            }
            arr[prev] = tmp;
        }
    }

    template<typename T, typename LN>
    void reverse(T* arr, LN l, LN r) {
        l = min(l, r);
        r = max(l, r);
        LN half_len = (r - l + 1) / 2;
        for (LN i = 0; i < half_len; i++) {
            swap(arr[l + i], arr[r - i]);
        }
    }

    // https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
    MAKE_FUNC(reversal) {
        d = d % n;

        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }

    template<typename T, typename LN>
    void range_swap(T* arr, LN l, LN r, LN d) {
        for (LN i = 0; i < d; i++) {
            swap(arr[l + i], arr[r + i]);
        }
    }

    // https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
    MAKE_FUNC(block_swap) {
        if (d == 0 || d == n) {
            return;
        }

        if (d == n - d) {
            range_swap(arr, 0, n - d, d);
            return;
        } else if (d > n - d) {
            /* A(0 ~ n - d - 1) B(n - d ~ n - 1)
            Al(0 ~ n - d - 1) Ar(n - d ~ d - 1) B(d ~ n - 1)
            => B Ar Al
            then block_swap(ArAl, len(Ar), len(ArAl)) */
            range_swap(arr, 0, d, n - d);
            block_swap(arr, d - (n - d), d);
        } else {
            /* A(0 ~ d - 1) B(d ~ n - 1)
            A(0 ~ d - 1) Bl(d ~ n - d - 1) Br(n - d ~ n - 1)
            => Br Bl A
            then block_swap(BrBl, len(Br))
            */
            range_swap(arr, 0, n - d, d);
            block_swap(arr, d, n - d);
        }
    }

    // https://www.geeksforgeeks.org/quickly-find-multiple-left-rotations-of-an-array/
    template<typename T, typename LN = int> \
    T* quick_left_rotate(T* arr, LN d, LN n) {
        T* new_arr = new T[n];

        for (LN i = 0; i < n; i += 1) {
            new_arr[i] = arr[(d + i) % n];
        }
        return new_arr;
    }

    template<typename T>
    func_map<T> methods = {
        { "using_temp_array", &using_temp_array },
        { "one_by_one", &one_by_one },
        { "juggling", &juggling },
        { "reversal", &reversal },
        { "block_swap", &block_swap },
    };
}
 
#endif
