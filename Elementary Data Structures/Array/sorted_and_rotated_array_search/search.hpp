#ifndef H_SEARCH_HPP
#define H_SEARCH_HPP

#include <algorithm>
using namespace std;

namespace sorted_and_rotated_array_search {
    template<typename T, typename LN = int>
    LN find_pivot(T arr[], LN l, LN h) {
        if (l > h) {
            return -1;
        }

        if (l == h) {
            return l;
        }

        LN mid = (l + h) / 2;
        if (arr[mid] > arr[mid + 1]) {
            return mid;
        }

        if (arr[mid] < arr[mid - 1]) {
            return (mid - 1);
        }

        if (arr[l] > arr[mid]) {
            return find_pivot(arr, l, mid - 1);
        }

        return find_pivot(arr, mid + 1, h);
    }

    template<typename T, typename LN = int>
    LN bsearch(T arr[], LN l, LN h, T target) {
        if (l > h) {
            return -1;
        }

        LN mid = (l + h) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            return bsearch(arr, (mid + 1), h, target);
        }

        return bsearch(arr, l, (mid - 1), target);
    }

    // https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    template<typename T, typename LN = int>
    LN single(T arr[], LN n, T target) {
        LN pivot = find_pivot(arr, 0, n - 1);

        /* array not rotated */
        if (pivot < 0) {
            return bsearch(arr, 0, n - 1, target);
        }

        if (arr[pivot] == target) {
            return pivot;
        }

        if (arr[0] <= target) {
            return bsearch(arr, 0, (pivot - 1), target);
        }

        return bsearch(arr, (pivot + 1), n - 1, target);
    }

    // https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    template<typename T, typename LN = int>
    LN improved_search(T arr[], LN l, LN h, T target) {
        if (l > h) {
            return -1;
        }

        LN mid = (l + h) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        // check if left side array is sorted
        if (arr[l] < arr[mid]) {
            if (arr[l] <= target && target < arr[mid]) {
                return improved_search(arr, l, mid - 1, target);
            }
            return improved_search(arr, (mid + 1), h, target);
        }

        if (arr[mid] < target && target <= arr[h]) {
            return improved_search(arr, (mid + 1), h, target);
        }
        return improved_search(arr, l, (mid - 1), target);
    }

    template<typename T, typename LN = int>
    LN single_improved(T arr[], LN n, T target) {
        improved_search(arr, 0, n - 1, target);
    }

    // https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
    template<typename T, typename LN = int>
    bool pair_in_sorted_rotated(T arr[], LN n, T sum) {
        int l, r;
        LN pivot = find_pivot(arr, 0, n - 1);
        if (pivot < 0) {
            l = 0;
            r = n - 1;
        } else {
            l = (pivot + 1) % n;
            r = pivot;
        }

        while(l != r) {
            if (arr[l] + arr[r] == sum) {
                return true;
            }
            if (arr[l] + arr[r] < sum) {
                l = (l + 1) % n;
            } else {
                r = (n + r - 1) % n;
            }
        }
        return false;
    }

    // https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
    template<typename T, typename LN = int>
    LN pair_in_sorted_rotated_count(T arr[], LN n, T sum) {
        int l, r;
        LN pivot = find_pivot(arr, 0, n - 1);
        if (pivot < 0) {
            l = 0;
            r = n - 1;
        } else {
            l = (pivot + 1) % n;
            r = pivot;
        }
        
        int cnt = 0;
        while(l != r) {
            if (arr[l] + arr[r] == sum) {
                cnt += 1;
                if ((l + 1) % n == r) {
                    return cnt;
                }

                l = (l + 1) % n;
                r = (n + r - 1) % n;
            }
            if (arr[l] + arr[r] < sum) {
                l = (l + 1) % n;
            } else {
                r = (n + r - 1) % n;
            }
        }
        return false;
    }

    // https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
    /*
        R_0 = 0*arr[0] + 1*arr[1] + 2*arr[2] + ... + (n-2)*arr[n-1] + (n-1)*arr[n-1]
        R_1 = 0*arr[n-1] + 1*arr[0] + 2*arr[1] + 3*arr[2] + ... + (n-1)*arr[n-2]
        R_2 = 0*arr[n-2] + 1*arr[n-1] + 2*arr[0] + 3*arr[1] + ... + (n-1)*arr[n-3]

        R_1 - R_0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]
                  = (arr[0] + arr[1] + ... + arr[n-2] + arr[n-1]) - n*arr[n-1]
        R_2 - R_1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]
                  = arr[0] + arr[1] + ... + arr[n-3] + (arr[n-2] - n*arr[n-2]) + arr[n-1]
                  = (arr[0] + arr[1] + ... + arr[n-1]) - n*arr[n-2]

        R_j - R_(j-1) = (arr[0] + arr[1] + ... + arr[n-1]) - n*arr[n-j]
        R_j = arr_sum - n*arr[n-j] + R_(j-1)

        max_sum = min(arr[n-j])
    */
    template<typename T, typename LN = int>
    LN max_sum_of_rotations(T arr[], LN n) {
        LN sum = 0;
        LN mul_sum = 0;

        // calc R_0
        for (LN i = 0; i < n; i += 1) {
            sum += arr[i];
            mul_sum += i * arr[i];
        }

        LN max_sum = mul_sum;
        for (LN i = 1; i < n; i += 1) {
            // R_j = R_(j-1) + arr_sum - n*arr[n-j]
            mul_sum += (sum - n * arr[n-i]);
            max_sum = max(max_sum, mul_sum);
        }

        return max_sum;
    }

    // https://www.geeksforgeeks.org/maximum-sum-iarri-among-rotations-given-array/
    // method 3
    // As we know for an array the maximum sum will be when the array is sorted in ascending order.
    template<typename T, typename LN = int>
    LN max_sum_of_sorted_rotated(T arr[], LN n) {
        LN pivot = find_pivot(arr, 0, n - 1);
        LN sum = 0;

        LN lowest_index = (pivot + 1) % n;
        for (LN i = 0; i < n; i += 1) {
            sum += (i * arr[(i + lowest_index) % n]);
        }
        return sum;
    }
}

#endif