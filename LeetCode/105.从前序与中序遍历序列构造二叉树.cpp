//62 重建二叉树
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie) {
        if(ps > pe) return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        int te;
        for(int i = is ; i <= ie ; i++)
        {
            if(node->val == inorder[i])
            {
                te = i;
                break;
            }
        }
        node->left = create(preorder , inorder,ps + 1, ps + te - is, is , te - 1);
        node->right = create(preorder , inorder,pe + te - ie + 1, pe , te + 1 , ie);
        return node;
    }
};

