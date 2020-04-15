#ifndef H_SEARCH_HPP
#define H_SEARCH_HPP

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

        if (arr[mid] > target) {
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

        if (arr[pivot] > target) {
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
}

#endif