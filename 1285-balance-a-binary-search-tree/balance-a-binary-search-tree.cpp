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
void ret(TreeNode* root,vector<int>&ord){
    if(root!=NULL){
        ret(root->left,ord);
        ord.push_back(root->val);
        ret(root->right,ord);
    }
}
TreeNode* build(vector<int>&v,int l,int r){
    if(l>r){
        return NULL;
    }
    if(l==r){
        return new TreeNode(v[l]);
    }
    int mid=(l+r)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=build(v,l,mid-1);
    root->right=build(v,mid+1,r);
    return root;
}
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        ret(root,v);
        return build(v,0,v.size()-1);
    }
};