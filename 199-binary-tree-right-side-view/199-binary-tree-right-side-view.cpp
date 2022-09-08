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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>m1;
        vector<int>v1;
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        int ht=1;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,ht});
                m1[ht]=cur->val;
                cur=cur->left;
                ht++;
            }
            else{
                cur=stack.top().first;
                ht=stack.top().second;
                stack.pop();
                ht++;
                cur=cur->right;
            }
        }
        for(auto it:m1){
            v1.push_back(it.second);
        }
        return v1;
    }
};