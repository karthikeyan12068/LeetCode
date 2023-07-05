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
    void ret(TreeNode* root,int ht,vector<vector<int>>&v1){
        if(root!=NULL){
            if(ht>v1.size()){
                vector<int>temp={root->val};
                v1.push_back(temp);
            }
            else{
                if(ht%2!=0){
                    v1[ht-1].push_back(root->val);
                }
                else{
                    v1[ht-1].insert(v1[ht-1].begin(),root->val);
                }
            }
            ret(root->left,ht+1,v1);
            ret(root->right,ht+1,v1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>v1;
       ret(root,1,v1);
       return v1;
    }
};