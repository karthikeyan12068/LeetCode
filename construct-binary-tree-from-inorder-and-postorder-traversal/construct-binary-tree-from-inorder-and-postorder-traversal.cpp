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
TreeNode* build(vector<int>& inorder, vector<int>& postorder){
    if(postorder.size()==0){
        return NULL;
    }
    if(postorder.size()==1){
        
        return new TreeNode(postorder.back());
    }
    vector<int>left,l,right,r;
    int ind=find(inorder.begin(),inorder.end(),postorder.back())-inorder.begin();
    for(int i=0;i<ind;i++){
        l.push_back(inorder[i]);
    }
    int j;
    for(j=0;j<l.size();j++){
        left.push_back(postorder[j]);
    }
    for(int i=ind+1;i<inorder.size();i++){
        r.push_back(inorder[i]);
    }
    while(right.size()<r.size()){
        right.push_back(postorder[j]);
        j++;
    }
    TreeNode* root=new TreeNode(inorder[ind]);
    root->left=build(l,left);
    root->right=build(r,right);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder);
    }
};