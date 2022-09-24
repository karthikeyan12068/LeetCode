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
void ret(TreeNode* root,int s,int &c,vector<long long>&v1){
    if(root==NULL){
        return;
    }
    v1.push_back(root->val);
    ret(root->left,s,c,v1);
    ret(root->right,s,c,v1);
    long long t=0;
    for(int i=v1.size()-1;i>=0;i--){
        t+=v1[i];
        if(t==s){
            c++;
        }
    }
    v1.pop_back();
}
class Solution {
public:
    int pathSum(TreeNode* root, int s) {
        int c=0;
        vector<long long>v1;
        ret(root,s,c,v1);
       return c;
    }
};