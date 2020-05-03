#ifndef H_REARERANGEMENT_HPP
#define H_REARERANGEMENT_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <set>

#include "../array_rotation/array_rotation.hpp"

using namespace std;
using namespace array_rotation;

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

    template<class T, class LN = int>
    void rearrange_positive_negative(T[], LN);

    template<class T, class LN = int>
    void rearrange_positive_negative_with_rotation(T[], LN);

    template<class T, class LN = int>
    void move_zero_to_end(T[], LN);

    template<class T, class LN = int>
    LN bring_less_number_together_min_swap(T[], LN);
}

#endif