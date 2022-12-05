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
void in(TreeNode* root,vector<int>&v1){
    if(root!=NULL){
        in(root->left,v1);
        v1.push_back(root->val);
        in(root->right,v1);
    }
}
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL){
            return -1;
        }
        vector<int>v1;
        in(root,v1);
        sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size();i++){
            
            if(v1[i]!=v1[0]){
                return v1[i];
            }
        }
        return -1;
    }
};