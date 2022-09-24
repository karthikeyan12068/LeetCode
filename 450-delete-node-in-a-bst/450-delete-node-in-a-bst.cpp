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
void pre(TreeNode* root,vector<int>&v,int k){
    if(root!=NULL){
        if(root->val!=k){
            v.push_back(root->val);
        }
        pre(root->left,v,k);
        pre(root->right,v,k);
    }
}
TreeNode* build(TreeNode* root,vector<int>v){
    if(v.size()==0){
        return NULL;
    }
    root=new TreeNode(v[v.size()/2]);
    vector<int>left,right;
    for(int i=0;i<v.size()/2;i++){
        left.push_back(v[i]);
    }
    for(int i=v.size()/2+1;i<v.size();i++){
        right.push_back(v[i]);
    }
    root->left=build(root,left);
    root->right=build(root,right);
    return root;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int>v;
        pre(root,v,key);
        sort(v.begin(),v.end());
        root=NULL;
        root=build(root,v);
        return root;
    }
};