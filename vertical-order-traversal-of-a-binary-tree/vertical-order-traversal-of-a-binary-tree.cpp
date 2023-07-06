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
    void ret(TreeNode* root,int l,int h, priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>&q){
        if(root!=NULL){
            ret(root->left,l-1,h+1,q);
            q.push({l,{h,root->val}});
            ret(root->right,l+1,h+1,q);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        ret(root,0,0,q);
        vector<vector<int>>ans;
        int move=q.top().first;
        int f=0;
        while(!q.empty()){
            vector<int>v;
            while(!q.empty() && q.top().first==move){
                v.push_back(q.top().second.second);
                q.pop();
            }
            ans.push_back(v);
            if(!q.empty()){
                move=q.top().first;
            }
        }
        return ans;
    }
};