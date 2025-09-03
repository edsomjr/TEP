    template<
	    typename Key,
	    typename Mapped,
	    typename Cmp_Fn = std::less<Key>,
	    typename Tag = rb_tree_tag,
	    template<
            typename Const_Node_Iterator,
            typename Node_Iterator,
            typename Cmp_Fn_,
            typename Allocator_>
	    class Node_Update = null_node_update,
	    typename Allocator = std::allocator<char> >
    class tree;
