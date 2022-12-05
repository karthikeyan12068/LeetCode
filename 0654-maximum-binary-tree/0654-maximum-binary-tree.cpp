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
TreeNode* build(TreeNode* root,vector<int>&nums){
    if(nums.size()==0){
        return NULL;
    }
    auto it=find(nums.begin(),nums.end(),*max_element(nums.begin(),nums.end()));
    root=new TreeNode(nums[it-nums.begin()]);
    vector<int>left,right;
    for(int i=0;i<it-nums.begin();i++){
        left.push_back(nums[i]);
    }
    for(int i=it-nums.begin()+1;i<nums.size();i++){
        right.push_back(nums[i]);
    }
    root->left=build(root->left,left);
    root->right=build(root->right,right);
    return root;
}
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=NULL;
        root=build(root,nums);
        return root;
    }
};