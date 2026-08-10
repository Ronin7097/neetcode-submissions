/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    pair<int,int> helper(TreeNode*root)
    {
        if(root==NULL) return {0,0};
        pair<int,int> pl,pr;
        pl=helper(root->left);
        pr=helper(root->right);
        int max_height=max(pr.second,max(pl.second,(pl.first+pr.first)));
        return make_pair(max(pl.first,pr.first)+1,max_height);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};
