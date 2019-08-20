#if (__GNUC__ == 7 || __GNUC__ == 4)
#include "common.h"
#endif

class BinaryTree {

  public:
    BinaryTree();
    ~BinaryTree();

    void createTree();

    void preOrder();
    void inOrder();
    void postOrder();

    void breadthFirstSearch();
    void depthFirstSearch();

  private:
    void preOrder(TreeNode *);
    void inOrder(TreeNode *);
    void postOrder(TreeNode *);

    TreeNode *root;
};

BinaryTree::BinaryTree() { root = new TreeNode(0); }

BinaryTree::~BinaryTree() { delete root; }

void BinaryTree::createTree() {

    root->val = 8;
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    left->left = new TreeNode(1);
    left->right = new TreeNode(6);

    right->left = nullptr;
    right->right = new TreeNode(14);

    right = left->right;
    right->left = new TreeNode(4);
    right->right = new TreeNode(7);

    right = root->right->right;
    right->left = new TreeNode(13);
}

void BinaryTree::preOrder() {
    preOrder(root);
    cout << endl;
}
void BinaryTree::inOrder() {
    inOrder(root);
    cout << endl;
}
void BinaryTree::postOrder() {
    postOrder(root);
    cout << endl;
}

void BinaryTree::preOrder(TreeNode *node) {

    if (node == nullptr)
        return;

    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void BinaryTree::inOrder(TreeNode *node) {
    if (node == nullptr)
        return;

    preOrder(node->left);
    cout << node->val << " ";
    preOrder(node->right);
}
void BinaryTree::postOrder(TreeNode *node) {
    if (node == nullptr)
        return;
    
    preOrder(node->left);
    preOrder(node->right);
    cout << node->val << " ";
}

void BinaryTree::breadthFirstSearch() {

    if (root == nullptr)
        return;

    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        auto &node = nodes.front();

        cout << node->val << " ";
        if (node->left != nullptr)
            nodes.push(node->left);
        if (node->right != nullptr)
            nodes.push(node->right);

        nodes.pop();
    }

    cout << endl;
}

#if (__GNUC__ == 7 || __GNUC__ == 4)
int main() {

    BinaryTree binaryTree;

    binaryTree.createTree();

    cout << "Binary Tree Pre Order: \n";
    binaryTree.preOrder();

    cout << "Binary Tree In Order: \n";
    binaryTree.inOrder();

    cout << "Binary Tree Post Order: \n";
    binaryTree.postOrder();

    cout << "Binary Tree BFS: \n";
    binaryTree.breadthFirstSearch();

    return 0;
}
#endif