#if (__GNUC__ == 7 || __GNUC__ == 4) || (defined __APPLE__)
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

    void showTree();

    void preTravel();
    void inTravel();
    void postTravel();

    void breadthFirstSearch();
    void depthFirstSearch();

  private:
    void preOrder(TreeNode *);
    void inOrder(TreeNode *);
    void postOrder(TreeNode *);

    void destroyTree(TreeNode *);

    void showTree(TreeNode *, int);

    TreeNode *root;
};

BinaryTree::BinaryTree() { root = new TreeNode(0); }

BinaryTree::~BinaryTree() {
    destroyTree(root);
    root = nullptr;
}

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

void BinaryTree::showTree() { showTree(root, 1); }

void BinaryTree::showTree(TreeNode *node, int n) {
    if (node == nullptr)
        return;

    showTree(node->left, n + 1);

    for (int i = 0; i < n; ++i)
        cout << " ";

    cout << node->val << endl;

    showTree(node->right, n + 1);
}

void BinaryTree::destroyTree(TreeNode *node) {
    if (node == nullptr)
        return;

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
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

    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}
void BinaryTree::postOrder(TreeNode *node) {
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

void BinaryTree::preTravel() {

    if (root == nullptr)
        return;

    TreeNode *curr = root;

    stack<TreeNode *> node_stack;

    while (!node_stack.empty() || curr != nullptr) {

        while (curr != nullptr) {
            cout << curr->val << " ";
            node_stack.push(curr);
            curr = curr->left;
        }

        if (!node_stack.empty()) {
            curr = node_stack.top();
            node_stack.pop();
            curr = curr->right;
        }
    }

    cout << endl;
}
void BinaryTree::inTravel() {
    if (root == nullptr)
        return;

    TreeNode *curr = root;

    stack<TreeNode *> node_stack;

    while (!node_stack.empty() || curr != nullptr) {
        while (curr != nullptr) {
            node_stack.push(curr);
            curr = curr->left;
        }

        if (!node_stack.empty()) {
            curr = node_stack.top();
            node_stack.pop();

            cout << curr->val << " ";
            curr = curr->right;
        }
    }
    cout << endl;
}
void BinaryTree::postTravel() {
    if (root == nullptr)
        return;

    TreeNode *curr = root;

    stack<TreeNode *> node_stack;

    while (!node_stack.empty() || curr != nullptr) {
        while (curr != nullptr) {
        }
    }

    cout << endl;
}

void BinaryTree::breadthFirstSearch() {

    if (root == nullptr)
        return;

    queue<TreeNode *> nodes;
    vector<int> num_nodes_level = {1, 0};

    int depth = 0, n = 0;

    for(nodes.push(root); !nodes.empty(); nodes.pop()){

        TreeNode *curr = nodes.front();

        cout << curr->val << " ";

        if(curr->left != nullptr){
            nodes.push(curr->left);
            num_nodes_level[depth + 1]++;
        }

        if(curr->right != nullptr){
            nodes.push(curr->right);
            num_nodes_level[depth + 1]++;
        }

        if(++n == num_nodes_level[depth]){
            n = 0;
            depth++;
            num_nodes_level.push_back(0);
            cout << endl;
        }
    }

    cout << endl;
}

#if (__GNUC__ == 7 || __GNUC__ == 4) || (defined __APPLE__)
int main() {

    BinaryTree binaryTree;

    binaryTree.createTree();

    cout << "Binary Tree Pre Order: \n";
    binaryTree.preOrder();
    binaryTree.preTravel();

    cout << "Binary Tree In Order: \n";
    binaryTree.inOrder();
    binaryTree.inTravel();

    cout << "Binary Tree Post Order: \n";
    binaryTree.postOrder();
    // binaryTree.postTravel();

    cout << "Binary Tree BFS: \n";
    binaryTree.breadthFirstSearch();

    // binaryTree.showTree();

    return 0;
}
#endif