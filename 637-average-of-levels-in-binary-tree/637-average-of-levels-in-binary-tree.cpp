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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v1;
        vector<int>v2;
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=root;
        int h=0;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                if(h+1<=v1.size()){
                    v1[h]+=cur->val;
                    v2[h]++;
                }
                else{
                    v1.push_back(cur->val);
                    v2.push_back(1);
                }
                cout<<h<<" ";
                h++;
                stack.push({cur,h});
                cur=cur->left;
            }
            else{
                cur=stack.top().first;
                h=stack.top().second;
                stack.pop();
                cur=cur->right;
            }
        }
        for(int i=0;i<v1.size();i++){
            v1[i]/=v2[i];
        }
        return v1;
    }
};