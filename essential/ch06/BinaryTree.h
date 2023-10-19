#include <iostream>
using namespace std;

template <typename valType>
class BinaryTree;

template <typename elemType>
class BTnode;

template <typename valType>
class BTnode
{
    friend class BinaryTree<valType>;
public:
    BTnode(const valType &val);

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;

    void insert_value(const valType &);
    void remove_value(const valType &, BTnode *&);

    void preorder(BTnode<valType> *, ostream & = cout) const;
    void inorder(BTnode<valType> *, ostream &  = cout) const;
    void postorder(BTnode<valType> *, ostream &  = cout) const;
    void display_val(BTnode<valType> *pt, ostream &os) const;

    static void lchild_leaf(BTnode *, BTnode *);
};

template <typename elemType>
class BinaryTree
{
    friend class BTnode<elemType>;
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();

    BinaryTree &operator=(const BinaryTree &);

    bool empty() { return _root == nullptr; }
    void insert(const elemType &elem);
    void remove(const elemType &elem);
    void clear() { if (_root) { clear(_root); _root = nullptr;} }

    void inorder( ostream &os = cout )   const { _root->inorder( _root, os ); }
    void postorder( ostream &os = cout ) const { _root->postorder( _root, os ); }
    void preorder( ostream &os = cout )  const { _root->preorder( _root, os ); }

private:
    BTnode<elemType> *_root;

    void remove_root();
    void clear(BTnode<elemType> *pt);
    void copy(BTnode<elemType> *&tar, BTnode<elemType> *src);

};

template <typename valType>
inline BTnode<valType>::
BTnode(const valType &val)
    : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = nullptr;
}

template <typename valType>
void BTnode<valType>::
insert_value(const valType &val)
{
    if (val == _val)
        ++_cnt;
    else if (val < _val) {
        if (!_lchild)
            _lchild = new BTnode(val);
        else
            _lchild->insert_value(val);
    } else {
        if (!_rchild)
            _rchild = new BTnode(val);
        else
            _rchild->insert_value(val);
    }
}

template <typename valType>
void BTnode<valType>::
remove_value(const valType &val, BTnode *&prev)
{
    if (val < _val) {
        if (!_lchild)
            return;
        else
            _lchild->remove_value(val, _lchild);
    } else if (val > _val) {
        if (!_rchild)
            return;
        else
            _rchild->remove_value(val, _rchild);
    } else {
        if (_rchild) {
            prev = _rchild;
            if (_lchild)
                if (!prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
        } else
            prev = _lchild;
        delete this;
    }
}

/*
* arguments leaf: node's lchild, subtree: node's rchild
* find subtree's leftest node and make lchild become eftest node's lchild
*/
template <typename valType>
void BTnode<valType>::
lchild_leaf(BTnode *leaf, BTnode *subtree)
{
    while (subtree->_lchild)
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;
}

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree()
    : _root(nullptr)
{ }

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &rhs)
{
    copy(_root, rhs._root);
}

template <typename elemType>
inline BinaryTree<elemType>::
~BinaryTree()
{
    clear();
}

template <typename elemType>
inline void BinaryTree<elemType>::
insert(const elemType &elem)
{
    if (!_root)
        _root = new BTnode<elemType>(elem);
    else
        _root->insert_value(elem);
}

template <typename elemType>
inline BinaryTree<elemType> &
BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
    if (this != &rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

template<typename elemType>
inline void
BinaryTree<elemType>::
remove(const elemType &elem)
{
    if (_root) {
        if (_root->_val == elem)
            remove_root();
        else
            _root->remove_value(elem, _root);
    }
}

template<typename elemType>
void
BinaryTree<elemType>::
remove_root()
{
    if (!_root)
        return;
    BTnode<elemType> *tmp = _root;
    if (_root->_rchild) {
        _root = _root->_rchild;
        if (tmp->_lchild) {
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if (!newlc)
                _root->_lchild = lc;
            else
                BTnode<elemType>::lchild_leaf(lc, newlc);
        }
    }
    else
        _root = _root->_lchild;
    delete tmp;
}

template <typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt)
{
    if (pt) {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
}

template <typename elemType>
void BinaryTree<elemType>::
copy(BTnode<elemType> *&tar, BTnode<elemType> *src)
{
    if ( src ) {
        tar = new BTnode<elemType>( src->_val );
        if ( src->_lchild )
            copy( tar->_lchild, src->_lchild );
        if ( src->_rchild )
            copy( tar->_rchild, src->_rchild );
	}
}

template <typename elemType>
void BTnode<elemType>::
preorder(BTnode<elemType> *pt, ostream &os) const
{
    if (pt) {
        display_val(pt, os);
        if (pt->_lchild)
            preorder(pt->_lchild, os);
        if (pt->_rchild)
            preorder(pt->_rchild, os);
    }
}

template <typename elemType>
void BTnode<elemType>::
inorder(BTnode<elemType> *pt, ostream &os) const
{
    if (pt) {
        if (pt->_lchild)
            inorder(pt->_lchild, os);
        display_val(pt, os);
        if (pt->_rchild)
            inorder(pt->_rchild, os);
    }
}

template <typename elemType>
void BTnode<elemType>::
postorder(BTnode<elemType> *pt, ostream &os) const
{
    if (pt) {
        if (pt->_lchild)
            postorder(pt->_lchild, os);
        if (pt->_rchild)
            postorder(pt->_rchild, os);
        display_val(pt, os);
    }
}


template <typename elemType>
void BTnode<elemType>::
display_val(BTnode<elemType> *pt, ostream &os) const
{
    os << pt->_val << ' ';
}