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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v1;
        map<int,vector<int>>m1;
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        int ht=1;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,ht});
                if(ht%2!=0){
                    m1[ht].push_back(cur->val);
                }
                else{
                    m1[ht].insert(m1[ht].begin(),cur->val);
                }
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
        for(auto it:m1){
            v1.push_back(it.second);
        }
        return v1;
    }
};