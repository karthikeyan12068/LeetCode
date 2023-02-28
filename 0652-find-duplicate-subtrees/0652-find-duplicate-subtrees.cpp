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
    string ret(TreeNode* root,unordered_map<string,int>&m1,vector<TreeNode*>&ans){
        if(root==NULL){
            return {"-201$"};
        }
        string leftSubtree=ret(root->left,m1,ans);
        string rightSubtree=ret(root->right,m1,ans);
        leftSubtree+=rightSubtree+to_string(root->val)+"$";
        m1[leftSubtree]++;
        if(m1[leftSubtree]==2){
            ans.push_back(root);
        }
        return leftSubtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>m1;
        ret(root,m1,ans);
        return ans;
    }
};