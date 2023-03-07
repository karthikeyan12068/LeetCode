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
    void ret(TreeNode* root1,TreeNode* root2,int &chk){
        if(chk==1){
            return;
        }
        if(root1!=NULL && root2!=NULL){
            if(root1->val!=root2->val){
                chk=1;
                return;
            }
            if(root1->left!=NULL && root2->left!=NULL && root1->left->val!=root2->left->val || root1->right!=NULL && root2->right!=NULL && root1->right->val!=root2->right->val || root1->left==NULL && root2->left!=NULL || root1->right!=NULL && root2->right==NULL || root1->left!=NULL && root2->left==NULL || root1->right==NULL && root2->right!=NULL){
               swap(root1->left,root1->right); 
            }
            
            ret(root1->left,root2->left,chk);
            ret(root1->right,root2->right,chk);
        }
        else{
            if(root1==NULL && root2==NULL){
                return;
            }
            else{
                chk=1;
                return;
            }
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        int chk=0;
        ret(root1,root2,chk);
        if(chk==0){
            return true;
        }
        return false;
    }
};