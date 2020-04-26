template <class RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
    RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
    RandomAccessIterator last, Compare comp);

