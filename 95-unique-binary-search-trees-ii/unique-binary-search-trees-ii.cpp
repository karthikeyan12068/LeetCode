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
    vector<TreeNode*> build(int l,int r){
        if(l>r){
            return {NULL};
        }
        if(l==r){
            return {new TreeNode(l)};
        }
        
        vector<TreeNode*>ans;
        for(int i=l;i<=r;i++){
            
            vector<TreeNode*>left1,right1;
            left1=build(l,i-1);
            right1=build(i+1,r);
            if(left1.size()>0 && right1.size()>0){
                for(int j=0;j<left1.size();j++){
                    for(int k=0;k<right1.size();k++){
                        TreeNode* root=new TreeNode(i);
                        root->left=left1[j];
                        root->right=right1[k];
                        ans.push_back(root);
                    }
                }
            }
            else{
                if(left1.size()>0){
                    for(int j=0;j<left1.size();j++){
                        TreeNode* root=new TreeNode(i);
                        root->left=left1[j];
                        ans.push_back(root);
                    }
                }
                else{
                    for(int j=0;j<right1.size();j++){
                        TreeNode* root=new TreeNode(i);
                        root->right=right1[j];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return build(1,n);
    }
};