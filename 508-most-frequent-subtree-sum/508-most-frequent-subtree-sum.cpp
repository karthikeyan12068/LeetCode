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
int build(TreeNode* root,map<int,int>&m1){
    if(root==NULL){
        return 0;
    }
    int sum=root->val+build(root->left,m1)+build(root->right,m1);
    m1[sum]++;
    return sum;
}
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m1;
        build(root,m1);
        int x=-1;
        for(auto it:m1){
            x=max(x,it.second);
        }
        vector<int>v1;
        for(auto it:m1){
            if(it.second==x){
                v1.push_back(it.first);
            }
        }
        return v1;
    }
};