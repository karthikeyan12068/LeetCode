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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<pair<TreeNode*,int>>stack;
        TreeNode *cur=root;
        int h=1;
        map<int,vector<int>>m1;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,h});
                m1[h].push_back(cur->val);
                cur=cur->left;
                h++;
            }
            else{
                cur=stack.top().first;
                h=stack.top().second;
                stack.pop();
                cur=cur->right;
                h++;
            }
        }
        vector<vector<int>>v1;
        for(auto it:m1){
            v1.push_back(it.second);
        }
        reverse(v1.begin(),v1.end());
        return v1;
    }
};