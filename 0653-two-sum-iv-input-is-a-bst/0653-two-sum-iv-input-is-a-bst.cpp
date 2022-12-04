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
void preorder(TreeNode* root,map<int,int>&m1){
    if(root!=NULL){
        m1[(int)root->val]++;
        preorder(root->left,m1);
        preorder(root->right,m1);
    }
}
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        map<int,int>m1;
        preorder(root,m1);
        for(auto it=m1.begin();it!=m1.end();it++){
            if(m1[it->first]!=0){
                if(m1[k-it->first]>0){
                    if(k-it->first==it->first){
                        if(m1[k-it->first]>=2){
                            return true;
                        }
                    }
                    else{
                        return true;
                    }
                }
            }
        }
        return false;
    }
};