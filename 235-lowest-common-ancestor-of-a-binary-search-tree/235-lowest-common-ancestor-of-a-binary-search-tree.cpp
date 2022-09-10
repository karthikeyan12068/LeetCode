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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* p1=root;
        TreeNode* q1=root;
        while(true){
            if(p1->val<=p->val && q1->val>=q->val || p1->val>=p->val && q1->val<=q->val){
                return p1;
            }
            if(p1->val<p->val){
                p1=p1->right;
            }
            else{
                p1=p1->left;
            }
            if(q1->val<q->val){
                q1=q1->right;
            }
            else{
                q1=q1->left;
            }
            
        }
    }
};