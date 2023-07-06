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
void ret(TreeNode* root,int h,map<int,int>&m){
    if(root!=NULL){
        ret(root->left,h+1,m);
        ret(root->right,h+1,m);
        m[h]=root->val;
    }
}
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        map<int,int>m;
        ret(root,1,m);
        for(auto it:m){
            v.push_back(it.second);
        }
        return v;
    }
};