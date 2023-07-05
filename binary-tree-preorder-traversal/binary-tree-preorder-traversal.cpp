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
void itr(TreeNode* root,vector<int>&ans){
    stack<TreeNode*>st;
    
    TreeNode* cur=root;
    while(!st.empty() || cur!=NULL){
        if(cur!=NULL){
            ans.push_back(cur->val);
            st.push(cur);
            cur=cur->left;
        }
        else{
            cur=st.top();
            st.pop();
            cur=cur->right;
        }
    }
}
 void ret(TreeNode* root,vector<int>&ans){
     if(root!=NULL){
         ans.push_back(root->val);
         ret(root->left,ans);
         ret(root->right,ans);
     }
 }
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        //ret(root,v);
        itr(root,v);
        return v;
    }
};