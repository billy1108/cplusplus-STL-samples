#ifndef MERGESORT_H_
#define MERGESORT_H_
#include <iostream>

template<typename RI>
  void mergeSort(RI first, RI last) {
  if (last - first > 1) {
typedef typename
  std::iterator_traits<RI>::value_type value_type;
RI middle = first + (last - first) / 2;
    std::vector<value_type> left_table(first, middle);
    std::vector<value_type> right_table(middle, last);
    mergeSort(left_table.begin(), left_table.end());
    mergeSort(right_table.begin(), right_table.end());

    merge(left_table.begin(), left_table.end(),
          right_table.begin(), right_table.end(),
          first);
    
  }
}
template<typename RI>
  void merge(RI left, RI end_left,
             RI right, RI end_right,
             RI out) {

  while (left != end_left && right != end_right) {
    if (*left < *right) {
      *out++ = *left++;
    } else {
      *out++ = *right++;
    }
  }

  while (left != end_left) {
    *out++ = *left++;
  }

  while (right != end_right) {
    *out++ = *right++;
  }
}

#endif
