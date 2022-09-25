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
void ret(TreeNode* root,priority_queue<int>&q){
    if(root!=NULL){
        q.push(root->val);
        ret(root->left,q);
        ret(root->right,q);
    }
}
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        priority_queue<int>q;
        ret(root,q);
        int x=0,y=0,ans=INT_MAX;
        while(!q.empty()){
            int temp=x;
            x=0;
            y=temp;
            x=q.top();
            q.pop();
            ans=min(ans,abs(x-y));
        }
        return ans;
    }
};