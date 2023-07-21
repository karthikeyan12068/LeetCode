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
void ret(TreeNode* root,vector<int>&val){
    if(root!=NULL){
        ret(root->left,val);
        val.push_back(root->val);
        ret(root->right,val);
    }
}
TreeNode* build(TreeNode* root,int l,int r,vector<int>&v){
    if(l==r){
        return new TreeNode(v[l]);
    }
    if(l>r){
        return NULL;
    }
    int mid=(l+r)/2;
    root=new TreeNode(v[mid]);
    root->left=build(root,l,mid-1,v);
    root->right=build(root,mid+1,r,v);
    return root;
}
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int>v;
        ret(root,v);
        v.push_back(val);
        sort(v.begin(),v.end());
        return build(root,0,v.size()-1,v);
    }
};