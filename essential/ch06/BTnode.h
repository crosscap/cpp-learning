template <typename valType>
class BTnode {
    friend class BinaryTree<valType>;
public:
    BTnode(const valType &val);

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();

    BinaryTree& operator=(const BinaryTree&);

    bool empty() { return _root == nullptr; }
    void clear();

private:
    BTnode<elemType> *_root;

    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
};

template <typename valType>
inline BTnode<valType>::BTnode(const valType &val)
    : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = nullptr;
}

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree()
    : _root(0)
{ }

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs)
{
    copy(_root, rhs._root);
}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree()
{
    clear();
}

template <typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::operator=(const BinaryTree &rhs)
{
    if (this != &rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}