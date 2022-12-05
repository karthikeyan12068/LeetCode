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
void ht1(TreeNode* root,int &mht,int ht){
    if(root!=NULL){
        ht++;
        mht=max(mht,ht);
        ht1(root->left,mht,ht);
        ht1(root->right,mht,ht);
    }
}
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int maxht=-1,ht=0;
        ht1(root,maxht,ht);
        cout<<maxht;
        maxht--;
        vector<vector<string>>v1;
        int r1=maxht+1;
        int n=pow(2,maxht+1)-1;
        for(int i=0;i<r1;i++){
            vector<string>v;
            for(int j=0;j<n;j++){
                v.push_back("");
            }
            v1.push_back(v);
        }
        v1[0][(n-1)/2]=to_string(root->val);
        int r=0,c=(n-1)/2;
        stack<pair<TreeNode*,pair<int,int>>>stack1;
        TreeNode* cur=root;
        
        while(!stack1.empty() || cur!=NULL){
            if(cur!=NULL){
                stack1.push({cur,{r,c}});
                cur=cur->left;
                c=c-pow(2,maxht-r-1);
                r=r+1;
                if(cur!=NULL){
                    v1[r][c]=to_string(cur->val);
                }
            }
            else{
                cur=stack1.top().first;
                r=stack1.top().second.first;
                c=stack1.top().second.second;
                cur=cur->right;
                c=c+pow(2,maxht-r-1);
                r=r+1;
                if(cur!=NULL){
                    v1[r][c]=to_string(cur->val);
                }
                stack1.pop();
            }
        }
        return v1;
    }
};