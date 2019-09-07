/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int ans = -0x3f3f3f3f;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = max(dfs(root->left),0);
        int right = max(dfs(root->right),0);
        ans = max(left + right + root->val, ans);
        return root->val + max(left,right);
    }
};

