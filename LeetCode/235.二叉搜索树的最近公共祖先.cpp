/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */
 // Definition for a binary tree node.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if(!root) return ;
        int val1 = p->val;
        int val2 = q->val;
        if(val1 > root->val && val2 > root->val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(val1 < root->val && val2 < root->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        else  {
            return root;
        }
    }
};

