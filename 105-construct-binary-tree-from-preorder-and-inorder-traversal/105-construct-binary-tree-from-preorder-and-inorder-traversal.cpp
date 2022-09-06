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
template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
#define finds(cl,el) find((cl.begin()),(cl.end()),(el))
TreeNode* build(TreeNode *root,vector<int>&pre,vector<int>in){
    if(in.size()==0){
        return NULL;
    }
    if(in.size()==1){
        pop_front(pre);
        return new TreeNode(in[0]);
    }
    auto it=finds(in,pre[0]);
    root=new TreeNode(pre[0]);
    vector<int>pre1;
    if(it-in.begin()!=0){
        for(int i=0;i<it-in.begin();i++){
            pre1.push_back(in[i]);
        }
    }
    vector<int>pre2;
    if(it-in.begin()!=in.size()-1){
        for(int i=it-in.begin()+1;i<in.size();i++){
            pre2.push_back(in[i]);
        }
    }
    pop_front(pre);
    
    root->left=build(root->left,pre,pre1);
    root->right=build(root->right,pre,pre2);
    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL;
        root=build(root,preorder,inorder);
        return root;
    }
};