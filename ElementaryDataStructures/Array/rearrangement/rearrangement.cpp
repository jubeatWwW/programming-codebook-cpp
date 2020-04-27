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
}