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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int h=1,min_ht=INT_MAX;
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,h});
                if(cur->left==NULL && cur->right==NULL){
                    min_ht=min(min_ht,h);
                }
                cur=cur->left;
                h++;
            }
            else{
                cur=stack.top().first;
                h=stack.top().second;
                h++;
                stack.pop();
                cur=cur->right;
            }
        }
        return min_ht;
    }
};