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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        ans.push_back(root->val);
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if( curr==NULL){
              if(!q.empty()){
                q.push(NULL);
                ans.push_back(q.front()->val);
              }}else{
            if(curr->right)q.push(curr->right);
            if(curr->left)q.push(curr->left);
        }
            }
        return ans;
        
    }
};
