/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.03%)
 * Total Accepted:    22.4K
 * Total Submissions: 36.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr)
            return {};
        
        vector<TreeNode *> nodes;
        nodes.push_back(root);

        vector<vector<int>> result;
        
        while(!nodes.empty())
        {
            vector<TreeNode *> next_level;
            vector<int> value_level;

            for(auto node : nodes){
                
                value_level.push_back(node->val);

                if(node->left != nullptr){
                    next_level.push_back(node->left);
                }

                if(node->right != nullptr){
                    next_level.push_back(node->right);
                }
            }

            nodes = next_level;
            result.push_back(value_level);
        }

        vector<vector<int>> re(result.size(), vector<int>());
        auto it1 = result.end() - 1;
        auto it2 = re.begin();
        
        while(it1 >= result.begin()){
            *it2 = *it1;

            --it1;
            ++it2;
        }

        return re;
    }
};

