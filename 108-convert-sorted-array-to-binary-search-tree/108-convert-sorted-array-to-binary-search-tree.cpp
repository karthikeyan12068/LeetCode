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
TreeNode* build(TreeNode* root,vector<int>tr){
    if(tr.size()==1){
        return new TreeNode(tr[0]);
    }
    if(tr.size()==0){
        return NULL;
    }
    root=new TreeNode(tr[tr.size()/2]);
    vector<int>lt;
    for(int i=0;i<tr.size()/2;i++){
        lt.push_back(tr[i]);
    }
    vector<int>rt;
    for(int i=tr.size()/2+1;i<tr.size();i++){
        rt.push_back(tr[i]);
    }
    root->left=build(root->left,lt);
    root->right=build(root->right,rt);
    return root;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        root=build(root,nums);
        return root;
    }
};