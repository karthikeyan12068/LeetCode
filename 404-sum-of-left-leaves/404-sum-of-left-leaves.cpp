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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        int sum=0;
        int f=1;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push(cur);
                if(cur->left==NULL && cur->right==NULL && f==0){
                    sum+=cur->val;
                }
                cur=cur->left;
                f=0;
            }
            else{
                cur=stack.top();
                stack.pop();
                cur=cur->right;
                f=1;
            }
        }
        return sum;
    }
};