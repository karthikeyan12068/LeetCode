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
    TreeNode* prev=NULL,*val1=NULL,*val2=NULL;
    void ret(TreeNode* root){
        if(root!=NULL){
            ret(root->left);
            if(prev==NULL){
                prev=root;
            }
            else{
                if(root->val<prev->val){
                    if(val1==NULL){
                        val1=prev;
                        val2=root;
                    }
                    else{
                        val2=root;
                    }
                    
                }
                prev=root;
            }
            ret(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        ret(root);
        if(val1!=NULL && val2!=NULL){
            
            swap(val1->val,val2->val);
        }
        else{
            //cout<<val1->val;
            swap(val1->val,root->val);
        }
    }
};