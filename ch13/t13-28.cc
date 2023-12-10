// 暂时无法解决

// #include <memory>
// #include <string>

// using std::make_shared;
// using std::shared_ptr;
// using std::string;

// class TreeNode
// {
// public:
// 	TreeNode() : value(), count(1), left(nullptr), right(nullptr) {}
// 	TreeNode(const string &s, TreeNode *lchild = nullptr, TreeNode *rchild = nullptr)
// 	 : value(s), count(1), left(lchild), right(rchild) {}
// 	TreeNode(const TreeNode &orig);
// 	~TreeNode();

// 	void copyTree(void);
// 	int releaseTree();

// private:
// 	string value;
// 	int count;
// 	TreeNode *left;
// 	TreeNode *right;
// };

// class BinStrTree
// {
// public:
// 	BinStrTree() : root(nullptr) {}
// 	BinStrTree(TreeNode *t) : root(t) {}
// 	BinStrTree(const BinStrTree &orig);

// private:
// 	TreeNode *root;
// };

// TreeNode::TreeNode(const TreeNode &orig)
// 	: value(orig.value), count(1), left(orig.left), right(orig.right)
// {
// 	if (left)
// 		left->copyTree();
// 	if (right)
// 		right->copyTree();
// }

// TreeNode::~TreeNode()
// {
// 	if (!count)
// 		releaseTree();
// }

// void TreeNode::copyTree(void)
// {
// 	if (left)
// 		left->copyTree();
// 	if (right)
// 		right->copyTree();
// 	++count;
// }

// int TreeNode::releaseTree(void)
// {
// 	if (left)
// 		if (!left->copyTree())
// 			delete left;

// }

// BinStrTree::BinStrTree(const BinStrTree &orig) : root(orig.root)
// {
// 	root->copyTree();
// }