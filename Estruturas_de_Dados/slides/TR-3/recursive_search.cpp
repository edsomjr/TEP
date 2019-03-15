bool search(Node *node, const T& info)
{
    if (node == nullptr) return false;

    if (node->info == info) return true;

    return info < node->info ? search(node->left, info) :
        search(node->right, info);
}
