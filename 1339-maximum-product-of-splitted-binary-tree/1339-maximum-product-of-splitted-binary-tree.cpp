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

void pre(TreeNode* root,long long &sum){
    if(root!=NULL){
        sum+=root->val;
        pre(root->left,sum);
        pre(root->right,sum);
    }
}
int ret(TreeNode* root,long long &max1,long long sum){
    if(root==NULL){
        return 0;
    }
    long long cur=root->val;
    long long left=ret(root->left,max1,sum);
    long long right=ret(root->right,max1,sum);
    long long sum1=cur+left+right;
    long long sum2=abs(sum-sum1);
    long long t=sum1*sum2;
    max1=max((long long)max1,(long long)t);
    return left+right+cur;
}
class Solution {
public:
    long long maxProduct(TreeNode* root) {
        long long int max1=-1;
        long long sum=0;
        pre(root,sum);
        long long t=ret(root,max1,sum);
        return max1%1000000007;
    }
};