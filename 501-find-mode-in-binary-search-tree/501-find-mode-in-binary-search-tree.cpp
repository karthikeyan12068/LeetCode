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
void pre(TreeNode* root,map<int,int>&m){
    if(root!=NULL){
        m[root->val]++;
        pre(root->left,m);
        pre(root->right,m);
    }
}
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int>m1;
        pre(root,m1);
        int x=-1;
        vector<int>v;
        for(auto it1:m1){
            x=max(x,it1.second);
        }
        for(auto it1:m1){
            if(it1.second==x){
                v.push_back(it1.first);
            }
        }
        return v;
    }
};