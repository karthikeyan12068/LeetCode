/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ans=NULL;
void ret(TreeNode* root,int p,int q){
    if(root!=NULL){
        if(root->val==p || root->val==q){
            if(ans==NULL){
                ans=root;
                return;
            }
        }
        if(ans==NULL){
            if(root->val>p && root->val<q || root->val<p && root->val>q){
                ans=root;
                return;
            }
        }
        ret(root->left,p,q);
        ret(root->right,p,q);
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=NULL;
        ret(root,p->val,q->val);
        return ans;
    }
};