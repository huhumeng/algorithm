/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.07%)
 * Total Accepted:    48.5K
 * Total Submissions: 100.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 *
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 * 说明:
 *
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#if (__GNUC__ == 7 || __GNUC__ == 4)
#include "common.h"
#endif

class Solution {
  public:
    bool isMirror(TreeNode *left, TreeNode *right){
        if(left == nullptr && right == nullptr)
            return true;
        
        if(left == nullptr || right == nullptr)
            return false;
        
        if(left->val != right->val)
            return false;
        
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;

        return isMirror(root->left, root->right);

        // queue<pair<TreeNode *, int>> nodes_with_pos;
        // vector<pair<int, int>> level_value_pos;

        // vector<int> num_nodes_level = {1, 0};

        // int depth = 0, n = 0;
        // int p = 1;
        // for (nodes_with_pos.push(make_pair(root, 0)); !nodes_with_pos.empty();
        //      nodes_with_pos.pop()) {

        //     auto node_with_pos = nodes_with_pos.front();
        //     TreeNode *node = node_with_pos.first;
        //     int pos = node_with_pos.second;
        //     level_value_pos.push_back(make_pair(node->val, pos));

        //     if (node->left != nullptr) {
        //         nodes_with_pos.push(make_pair(node->left, pos - p));
        //         num_nodes_level[depth + 1]++;
        //     }

        //     if (node->right != nullptr) {
        //         nodes_with_pos.push(make_pair(node->right, pos + p));
        //         num_nodes_level[depth + 1]++;
        //     }

        //     if (++n == num_nodes_level[depth]) {
        //         n = 0;
        //         depth++;
        //         num_nodes_level.push_back(0);

        //         p *= 2;

        //         if(level_value_pos.size() % 2 != 0 && depth != 1)
        //             return false;

        //         auto it1 = level_value_pos.begin();
        //         auto it2 = level_value_pos.end() - 1;

                
        //         for(auto it : level_value_pos){
        //             cout << it.first << "x" << it.second << " ";
        //         }
        //         cout << endl;
                


        //         while(it1 < it2)
        //         {
        //             if(it1->first != it2->first || it1->second + it2->second != 0){
        //                 return false;
        //             }

        //             ++it1;
        //             --it2;
        //         }
        //         level_value_pos.clear();
        //     }
        // }

        // return true;
    }
};

#if (__GNUC__ == 7 || __GNUC__ == 4) || (defined __APPLE__)
int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << "Result: " << Solution().isSymmetric(root) << endl;

    return 0;
}
#endif
