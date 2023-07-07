/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ans3;
bool ret(TreeNode* root,int v1,int v2){
    if(root==NULL){
        return false;
    }
    if(root->val==v1 || root->val==v2){
        //cout<<root->val<<'\n';
        ans3=root;
        //cout<<ans->val<<'\n';
        return true;
    }
    bool ans1=ret(root->left,v1,v2);
    bool ans2=ret(root->right,v1,v2);
    
    if(ans1==true && ans2==true){
        ans3=root;
    }
    if(ans1==false && ans2==false){
        return false;
    }
    return true;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        ret(root,p->val,q->val);
        return ans3;
    }
};