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
void ret(TreeNode* root,vector<int>&v,int h){
    if(root!=NULL){
        h++;
        if(v.empty() || h>v.size()){
            v.push_back(root->val);
        }
        else{
            v[h-1]=max(v[h-1],root->val);
        }
        ret(root->left,v,h);
        ret(root->right,v,h);
    }
}
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        int h=0;
        ret(root,v,h);
        return v;
    }
};