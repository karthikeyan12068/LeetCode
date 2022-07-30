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

TreeNode* insert(TreeNode* root,int data){
    TreeNode* n=new TreeNode(data);
    if(root==NULL){
        root=n;
        return root;
    }
    TreeNode* temp=root;
    TreeNode* cur=temp;
    while(temp!=NULL){
        cur=temp;
        if(data<temp->val){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    if(data<cur->val){
        cur->left=n;
    }
    else{
        cur->right=n;
    }
    return root;
}
void preorder(TreeNode* root,vector<int>&v3){
    if(root!=NULL){
        v3.push_back(root->val);
        preorder(root->left,v3);
        preorder(root->right,v3);
    }
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        int arr[n];
        vector<TreeNode*>v2;
        for(int i=0;i<n;i++){
            arr[i]=(i+1);
        }
        int c=0;
        map<vector<int>,int>m1;
        do{
            TreeNode* root=NULL;
            for(int i=0;i<n;i++){
                root=insert(root,arr[i]);
            }
            vector<int>v3;
            preorder(root,v3);
            if(m1[v3]==0){
                v2.push_back(root);
                m1[v3]++;
            }
            
        }while(next_permutation(arr, arr + n));
        return v2;
    }
};