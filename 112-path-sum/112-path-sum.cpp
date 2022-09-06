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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        int sum=0;
        while(!stack.empty() || cur!=NULL){
            
            if(cur!=NULL){
                
                sum+=cur->val;
                if(cur->left==NULL && cur->right==NULL){
                    if(sum==targetSum){
                        return true;
                    }
                }
                stack.push({cur,sum});
                cur=cur->left;
            }
            else{
                cur=stack.top().first;
                sum=stack.top().second;
                stack.pop();
                cur=cur->right;
            }
        }
        return false;
    }
};