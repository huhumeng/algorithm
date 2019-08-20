/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (70.47%)
 * Total Accepted:    67K
 * Total Submissions: 95.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
        
        queue<TreeNode *> nodes_with_pos;
        
        vector<int> num_nodes_level = {1, 0};
        int depth = 0, n = 0;
        
        for (nodes_with_pos.push(root); !nodes_with_pos.empty();
             nodes_with_pos.pop()) {
            
            TreeNode *node = nodes_with_pos.front();

            if (node->left != nullptr) {
                nodes_with_pos.push(node->left);
                num_nodes_level[depth + 1]++;
            }

            if (node->right != nullptr) {
                nodes_with_pos.push(node->right);
                num_nodes_level[depth + 1]++;
            }

            if (++n == num_nodes_level[depth]) {
                n = 0;
                depth++;
                num_nodes_level.push_back(0);
            }
        }

        return depth;
    }
};

