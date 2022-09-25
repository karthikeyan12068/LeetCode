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
void ret(TreeNode* root,int h,int &max1,int &ele){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            
                h++;
                if(max(max1,h)==h && max1!=h){
                    ele=root->val;
                    max1=max(max1,h);
                }
            
            return;
        }
        else{
            h++;
            ret(root->left,h,max1,ele);
            ret(root->right,h,max1,ele);
        }
    }
}
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int h=0,max1=-1,ele=-1;
        ret(root,h,max1,ele);
        return ele;
    }
};