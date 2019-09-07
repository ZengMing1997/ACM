/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root->left) {
            int left = kthSmallest(root->left,k);
            if(left != -1) return left;
        }
        k--;
        if(!k) return root->val;
        if(root->right) {
            int right = kthSmallest(root->right,k);
            if(right != -1) return right;
        }
        return -1;
    }
};

