/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// * Definition for a binary tree node.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || !root) return root;
        struct TreeNode *left = lowestCommonAncestor(root->left,p, q);
        struct TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(!left && !right) return nullptr;
        if(left && !right) return left;
        if(!left && right) return right;
        return root;
    }
};

