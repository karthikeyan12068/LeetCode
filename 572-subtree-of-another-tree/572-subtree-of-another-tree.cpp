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
void serialize(TreeNode* root,vector<int>&v){
    stack<TreeNode*>stack;
    TreeNode* cur=root;
    while(!stack.empty() || cur!=NULL){
        if(cur!=NULL){
            v.push_back(cur->val);
            stack.push(cur);
            cur=cur->left;
        }
        else{
            v.push_back(-1001);
            cur=stack.top();
            stack.pop();
            cur=cur->right;
        }
    }
    v.push_back(-1001);
}
class Solution {
public:
    bool isSubtree(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        serialize(root1,v1);
        serialize(root2,v2);
        if(v1.size()<v2.size()){
            return false;
        }
        for(int i=0;i<v1.size()-v2.size()+1;i++){
            if(v1[i]==v2[0]){
                int c=0,st=0;
                int j=-1;
                    for(j=i;j<i+v2.size();j++){
                        if(v2[st]==v1[j]){
                            c++;
                        }
                        st++;
                    }
                    if(c==v2.size()){
                        return true;
                    }
                }
            }
        return false;
        
    }
};