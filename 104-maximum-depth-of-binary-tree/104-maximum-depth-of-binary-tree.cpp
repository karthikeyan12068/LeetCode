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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        int ht=1,max1=0;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,ht});
                max1=max(max1,ht);
                ht++;
                cur=cur->left;
            }
            else{
                cur=stack.top().first;
                ht=stack.top().second;
                stack.pop();
                cur=cur->right;
                ht++;
            }
        }
        return max1;
    }
};