#ifndef SHELLSORT_H_
#define SHELLSORT_H_

template<typename RI>
  void insert(RI first, RI next_pos, 
              int gap);

template<typename RI>
  void shellSort(RI first, RI last) {
  int gap = (last - first) / 2;
  while (gap > 0) {
    for (RI next_pos = first + gap;
         next_pos != last; ++next_pos) {
         insert(first, next_pos, gap);
    } 

    if (gap == 2) {
      gap = 1;
    } else {
      gap = int(gap / 2.2);
    }
  } 
}


template<typename RI>
  void insert(RI first, RI next_pos, 
              int gap) {
  typename std::iterator_traits<RI>::value_type next_val = *next_pos;
while ((next_pos > first + gap - 1)
       && (next_val < *(next_pos - gap))) {
    *next_pos = *(next_pos - gap); 
    next_pos -= gap;    
  }
  *next_pos = next_val;
}

#endif
