#include <stdio.h>
#include <utility>
using namespace std;

template<typename T>
void using_temp_array(T& arr, int d) {
    int n = sizeof(arr) / sizeof(arr[0]);
    d = d % n;

    T tmp[d];
    for (unsigned i = 0; i < n; i++) {
        if (i < d) {
            tmp[i] = arr[i];
        } else {
            arr[i - d] = arr[i]
        }

        if (i >= n - d) {
            arr[i] = tmp[i - (n - d)];
        }
    }
}
