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

    // https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
    template<class T, class LN = int>
    void rearrange_positive_negative(T arr[], LN n) {
        LN pivot =  0;
        // use 0 as pivot to separate positive and negative number
        for (LN i = 0; i < n; i += 1) {
            if (arr[i] > 0) {
                swap(arr[pivot], arr[i]);
                pivot += 1;
            }
        }

        int pos = 1;
        int neg = pivot + 1;
        while (neg < n && pos < neg && arr[pos] > 0) {
            swap(arr[pos], arr[neg]);
            pos += 2;
            neg += 1;
        }
    }

    // https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
    template<class T, class LN = int>
    void rearrange_positive_negative_with_rotation(T arr[], LN n) {
        LN rotate_start = -1;

        for (LN i = 0; i < n; i += 1) {
            if (rotate_start < 0) {
                if ((arr[i] > 0 && !(i % 2)) || (arr[i] < 0 && i % 2)) {
                    rotate_state = i;
                    continue;
                }
            }
            if (rotate_start >= 0) {
                if ((arr[rotate_start] > 0 && arr[i] < 0)
                    || (arr[rotate_start] < 0 && arr[i] > 0)) {
                    right_rotation(arr + rotate_start, 1, i - rotate_start + 1);

                    if (rotate_start - i > 1) {
                        rotate_start += 2;
                    } else {
                        rotate_start = -1;
                    }
                }
            }
        }
    }

    // https://www.geeksforgeeks.org/move-zeroes-end-array/
    template<class T, class LN = int>
    void move_zero_to_end(T arr[], LN n) {
        LN non_zero_count = 0;
        for (LN i = 0; i < n; i += 1) {
            if (arr[i] != 0) {
                arr[non_zero_count] = arr[i];
                non_zero_count += 1;
            }
        }

        for (LN i = non_zero_count; i < n; i += 1) {
            arr[i] = 0;
        }
    }

    // https://www.geeksforgeeks.org/move-zeroes-end-array-set-2-using-single-traversal/
    template<class T, class LN = int>
    void move_zero_to_end_single_traversal(T arr[], LN n) {
        LN non_zero_count = 0;
        for (LN i = 0; i < n; i += 1) {
            if (arr[i] != 0) {
                swap(arr[non_zero_count], arr[i]);
                non_zero_count += 1;
            }
        }
    }

    // https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
    template<class T, class LN = int>
    LN bring_less_number_together_min_swap(T arr[], LN n, LN k) {
        LN less_than_k_count = 0;
        for (LN i = 0; i < n; i += 1) {
            if (arr[i] <= k) {
                less_than_k_count += 1;
            }
        }

        LN greater_than_k_count = 0;
        for (LN i = 0; i < less_than_k_count; i += 1) {
            if (arr[i] > k) {
                greater_than_k_count += 1;
            }
        }

        LN swap_count = greater_than_k_count;
        for (LN window_begin = 0, window_end = less_than_k_count;
            window_end < n;
            window_begin += 1, window_end += 1) {
            if (arr[window_begin] > k) {
                greater_than_k_count -= 1;
            }
            if (arr[window_end] > k) {
                greater_than_k_count += 1;
            }

            swap_count = min(swap_count, greater_than_k_count);
        }
        return swap_count;
    }
}