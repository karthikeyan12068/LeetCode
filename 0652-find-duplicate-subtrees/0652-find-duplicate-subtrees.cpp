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
    vector<int> ret(TreeNode* root,map<vector<int>,int>&m1,vector<TreeNode*>&ans){
        if(root==NULL){
            return {-201};
        }
        vector<int>leftSubtree=ret(root->left,m1,ans);
        vector<int>rightSubtree=ret(root->right,m1,ans);
        for(auto it:rightSubtree){
            leftSubtree.push_back(it);
        }
        leftSubtree.push_back(root->val);
        
        m1[leftSubtree]++;
        if(m1[leftSubtree]==2){
            ans.push_back(root);
        }
        return leftSubtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        map<vector<int>,int>m1;
        ret(root,m1,ans);
        return ans;
    }
};