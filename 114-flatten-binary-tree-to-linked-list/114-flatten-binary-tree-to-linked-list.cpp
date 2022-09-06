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
    void flatten(TreeNode* root) {
        if(root!=NULL){
            vector<int>v1,v2;
            stack<TreeNode*>stack;
            TreeNode* cur=root;
            int f=0;
            while(!stack.empty() || cur!=NULL){
                if(cur!=NULL){
                    stack.push(cur);
                    if(f==0){
                        if(cur!=root){
                            v1.push_back(cur->val);
                        }
                    }
                    else{
                        v2.push_back(cur->val);
                    }
                    cur=cur->left;
                }
                else{
                    cur=stack.top();
                    stack.pop();
                    cur=cur->right;
                    if(stack.empty()){
                        f=1;
                    }
                }
            }
            root->left=NULL;
            root->right=NULL;
            TreeNode* temp=root;
            for(int i=0;i<v1.size();i++){
                temp->right=new TreeNode(v1[i]);
                temp=temp->right;
            }
            for(int i=0;i<v2.size();i++){
                temp->right=new TreeNode(v2[i]);
                temp=temp->right;
            }
        }
    }
};