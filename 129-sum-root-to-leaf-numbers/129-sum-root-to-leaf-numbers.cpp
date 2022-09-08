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
int str_to_in(string s)
{
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<string>v1;
        string s="";
        stack<pair<TreeNode*,string>>stack;
        TreeNode* cur=root;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                s+=to_string(cur->val);
                if(cur->left==NULL && cur->right==NULL){
                    v1.push_back(s);
                }
                stack.push({cur,s});
                cur=cur->left;
            }
            else{
                cur=stack.top().first;
                s=stack.top().second;
                stack.pop();
                cur=cur->right;
            }
        }
        int sum=0;
        for(auto it:v1){
            sum+=str_to_in(it);
        }
        return sum;
    }
};