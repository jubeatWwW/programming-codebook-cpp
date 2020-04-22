#include <stdio.h>
#include <iostream>
#include "array_rotation/array_rotation.hpp"
#include "sorted_and_rotated_array_search/search.hpp"
using namespace std;
using namespace sorted_and_rotated_array_search;

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    array_rotation::func_map<int> map = array_rotation::methods<int>;
    
    for (const auto& rotation_func : map) {
        rotation_func.second(arr, 2, 8);

        for (int i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        int position = single(arr, 8, 3);
        cout << "found 3 at position: " << position << endl;
        position = single(arr, 8, 4);
        cout << "found 4 at position: " << position << endl;
        position = single_improved(arr, 8, 3);
        cout << "found 3 at position: " << position << endl;
        position = single_improved(arr, 8, 4);
        cout << "found 4 at position: " << position << endl;
    }

    return 0;
}