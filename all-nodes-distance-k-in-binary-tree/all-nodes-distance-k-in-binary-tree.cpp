/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>children;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    children[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    children[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
        vector<int>ans;
        unordered_map<TreeNode*,int>vis;
        q.push(target);
        vis[target]++;
        k++;
        while(!q.empty() && k--){
            int x=q.size();
            while(x--){
                TreeNode* temp=q.front();
                q.pop();
                if(k==0){
                    ans.push_back(temp->val);
                }
                if(temp->left!=NULL){
                    if(vis[temp->left]==NULL){
                        q.push(temp->left);
                        vis[temp->left]++;
                    }
                }
                if(temp->right!=NULL){
                    if(vis[temp->right]==NULL){
                        q.push(temp->right);
                        vis[temp->right]++;
                    }
                }
                if(children[temp]!=NULL){
                    if(vis[children[temp]]==NULL){
                        q.push(children[temp]);
                        vis[children[temp]]++;
                    }
                }
            }
        }
        return ans;
    }
};