#ifndef H_REARERANGEMENT_HPP
#define H_REARERANGEMENT_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

namespace rearrangement {
    template<class T, class LN = int>
    void rearrange_array_with_index(T[], LN);

    template<class T, class LN = int>
    void reverse_iterative(T[], LN);

    void reverse_iterative(string);

    template<class T, class LN = int>
    void reverse_recursive(T[], LN);
    
    void reverse_recursive(string);

    template<class T, class LN = int>
    T* rearrange_by_odd_even(T[], LN);
}

#endif