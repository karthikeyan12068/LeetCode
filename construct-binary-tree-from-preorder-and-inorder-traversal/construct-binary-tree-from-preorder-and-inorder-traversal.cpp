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
TreeNode* build(vector<int>& preorder, vector<int>& inorder){
    if(inorder.size()==0){
        return NULL;
    }
    if(inorder.size()==1){
        preorder.erase(preorder.begin());
        return new TreeNode(inorder[0]);
    }
    int ind=find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
    vector<int>left,right;
    for(int i=0;i<ind;i++){
        left.push_back(inorder[i]);
    }
    for(int i=ind+1;i<inorder.size();i++){
        right.push_back(inorder[i]);
    }
    TreeNode* root=new TreeNode(preorder[0]);
    preorder.erase(preorder.begin());
    root->left=build(preorder,left);
    root->right=build(preorder,right);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder);
    }
};