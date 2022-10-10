template<
    class Key, 
    class Hash = std::hash<Key>, 
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
> class unordered_set;
