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
    int ans=0;
    pair<int,int> ret(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto l=ret(root->left);
        auto r=ret(root->right);
        pair<int,int>p={l.first+r.first+root->val,l.second+r.second+1};
        if((p.first/p.second)==root->val){
            ans++;
        }
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        
        ret(root);
        return ans;
    }
};