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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        int c=0,level=1;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            vector<int>nodes;
            while(x--){
                auto node=q.front();
                nodes.push_back(node->val);
                q.pop();
                if(level%2==0 && node->val%2!=0 || level%2!=0 && node->val%2==0){
                    return false;
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            
            vector<int>copy=nodes;
            if(level%2!=0){
                sort(copy.begin(),copy.end());
            }
            else{
                sort(copy.rbegin(),copy.rend());
            }
            for(int i=1;i<copy.size();i++){
                if(copy[i]==copy[i-1]){
                    return false;
                }
            }
            if(copy!=nodes){
                return false;
            }
            level++;
        }
        return true;
    }
};