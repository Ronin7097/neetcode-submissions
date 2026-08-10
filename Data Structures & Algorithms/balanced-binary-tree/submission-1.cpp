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
    pair<int,bool> helper(TreeNode *root)
    {
        if(root==NULL)
        return {0,true};
        auto p1=helper(root->left);
        auto p2=helper(root->right);
        pair<int,bool> ans;
        ans.first=max(p1.first,p2.first)+1;
        ans.second=(p1.second && p2.second);
        if(ans.second)
        {
            int diff=abs(p1.first-p2.first);
            if(diff>1)
            ans.second=false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).second;
    }
};
