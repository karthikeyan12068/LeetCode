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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v1;
        vector<int>v,v2={};
        stack<pair<pair<TreeNode*,int>,vector<int>>>stack;
        int sum=0;
        TreeNode* cur=root;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                sum+=cur->val;
                if(v.size()!=0){
                    stack.push({{cur,sum},v});
                    stack.top().second.push_back(cur->val);
                    v.clear();
                }
                else{
                    if(!stack.empty()){
                        stack.push({{cur,sum},stack.top().second});
                        stack.top().second.push_back(cur->val);
                    }
                    else{
                        if(cur==root){
                            stack.push({{cur,sum},{cur->val}});
                        }
                        else{
                            stack.push({{cur,sum},{root->val}});
                            stack.top().second.push_back(cur->val);
                        }
                    }
                }
                if(cur->left==NULL && cur->right==NULL && sum==targetSum){
                    v1.push_back(stack.top().second);
                }
                
                cur=cur->left;
            }
            else{
                cur=stack.top().first.first;
                sum=stack.top().first.second;
                v=stack.top().second;
                stack.pop();
                cur=cur->right;
            }
        }
        return v1;
    }
};