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
template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
void preorder(TreeNode* root,vector<int>&v,int low,int high){
    if(root!=NULL){
        if(root->val>=low && root->val<=high){
            v.push_back(root->val);
        }
        preorder(root->left,v,low,high);
        preorder(root->right,v,low,high);
    }
}
void inorder(TreeNode* root,vector<int>&v,int low,int high){
    if(root!=NULL){
        
        inorder(root->left,v,low,high);
        if(root->val>=low && root->val<=high){
            v.push_back(root->val);
        }
        inorder(root->right,v,low,high);
    }
}
TreeNode* build(TreeNode* newt,vector<int>&pre,vector<int>in){
    if(in.empty()){
        return NULL;
    }
    newt=new TreeNode(pre[0]);
    auto it=find(in.begin(),in.end(),pre[0]);
    pop_front(pre);
    vector<int>left,right;
    for(int i=0;i<it-in.begin();i++){
        left.push_back(in[i]);
    }
    for(int i=it-in.begin()+1;i<in.size();i++){
        right.push_back(in[i]);
    }
    newt->left=build(newt->left,pre,left);
    newt->right=build(newt->right,pre,right);
    return newt;
}
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int>pre,in;
        preorder(root,pre,low,high);
        inorder(root,in,low,high);
        TreeNode* newt=NULL;
        newt=build(newt,pre,in);
        return newt;
    }
};