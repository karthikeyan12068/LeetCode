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
void in1(TreeNode* root,vector<int>&v){
    if(root!=NULL){
        in1(root->left,v);
        v.push_back(root->val);
        in1(root->right,v);
    }
}
void pre1(TreeNode* root,list<int>&v){
    if(root!=NULL){
        v.push_back(root->val);
        pre1(root->left,v);
        pre1(root->right,v);
    }
}
void helper(vector<int>in,list<int>&pre,int ans,int &max1){
    if(in.empty()){
        return;
    }
    int val=pre.front();
    vector<int>left,right;
    auto it=find(in.begin(),in.end(),val);
    int ind=it-in.begin();
    for(int i=0;i<=ind-1;i++){
        left.push_back(in[i]);
    }
    for(int i=ind+1;i<in.size();i++){
        right.push_back(in[i]);
    }
    ans=pre.front();
    pre.pop_front();
    int leftmin=INT_MAX,rightmin=INT_MAX,leftmax=INT_MIN,rightmax=INT_MIN;
    if(!left.empty()){
        leftmin=*min_element(left.begin(),left.end());
        leftmax=*max_element(left.begin(),left.end());
    }
    if(!right.empty()){
        rightmin=*min_element(right.begin(),right.end());
        rightmax=*max_element(right.begin(),right.end());
    }
    if(leftmin!=INT_MAX){
        max1=max(max1,abs(ans-leftmin));
    }
    if(leftmax!=INT_MIN){
        max1=max(max1,abs(ans-leftmax));
    }
    if(rightmin!=INT_MAX){
        max1=max(max1,abs(ans-rightmin));
    }
    if(rightmax!=INT_MIN){
        max1=max(max1,abs(ans-rightmax));
    }
    helper(left,pre,ans,max1);
    helper(right,pre,ans,max1);
    return;
}
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int>in;
        list<int>pre;
        in1(root,in);
        pre1(root,pre);
        int max1=-1;
        helper(in,pre,-1,max1);
        return max1;
    }
};