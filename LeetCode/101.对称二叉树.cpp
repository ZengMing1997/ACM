/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

//  Definition for a binary tree node.
 /* struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(check(root->left,root->right)) return true;
        return false;
    }
    bool check(TreeNode* l,TreeNode* r)
    {
        if(l == nullptr && r == nullptr) return true;
        if(l == nullptr || r == nullptr) return false;
        if(l->val != r->val) return false;
        return check(l->left,r->right) && check(l->right,r->left);
    }
};

