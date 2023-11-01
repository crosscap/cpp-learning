#include <iostream>

using namespace std;

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
    friend ostream& operator<<(ostream&, const BinaryTree<elemType> &);
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();

    BinaryTree &operator=(const BinaryTree &);

    bool empty() { return _root == nullptr; }
    void insert(const elemType &elem);
    void remove(const elemType &elem);
    void clear() { if (_root) { clear(_root); _root = nullptr;} }

    void inorder(ostream &os = cout)   const { _root->inorder(_root, os); }
    void postorder(ostream &os = cout) const { _root->postorder(_root, os); }
    void preorder(ostream &os = cout)  const { _root->preorder(_root, os); }

private:
    BTnode<elemType> *_root;

    void remove_root();
    void clear(BTnode<elemType> *pt);
    void copy(BTnode<elemType> *&tar, BTnode<elemType> *src);
    ostream& print( ostream &os = *_current_os,
                    void (BinaryTree<elemType>::*traversal)( ostream& ) const =
                          &BinaryTree<elemType>::inorder ) const;
};
