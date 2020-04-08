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
}

#endif