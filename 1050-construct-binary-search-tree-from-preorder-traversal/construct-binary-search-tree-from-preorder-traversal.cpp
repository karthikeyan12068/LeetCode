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
TreeNode* ret(vector<int>& preorder,int l,int r){
    if(l>r){
        return NULL;
    }
    if(l==r){
        return new TreeNode(preorder[l]);
    }
    TreeNode* root=new TreeNode(preorder[l]);
    int l1=l+1,mid=l1;
    for(mid=l1;mid<=r;mid++){
        if(preorder[mid]>=preorder[l]){
            break;
        }
    }
    root->left=ret(preorder,l1,mid-1);
    root->right=ret(preorder,mid,r);
    return root;
}
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return ret(preorder,0,preorder.size()-1);
    }
};