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
void ret(TreeNode* root,vector<int>&v){
    if(root!=NULL){
        v.push_back(root->val);
        ret(root->left,v);
        ret(root->right,v);
    }
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>stack1;
        stack<TreeNode*>stack2;
        TreeNode* cur1=p;
        TreeNode* cur2=q;
        if(cur1==NULL && cur2==NULL){
            return true;
        }
        while(true){
            if(cur1!=NULL && cur2!=NULL){
                if(cur1->val!=cur2->val){
                    return false;
                }
            }
            
                if(cur1==NULL && cur2!=NULL || cur1!=NULL && cur2==NULL){
                    return false;
                }
                else{
                    if(cur1!=NULL){
                        stack1.push(cur1);
                        stack2.push(cur2);
                        cur1=cur1->left;
                        cur2=cur2->left;
                    }
                    else{
                        cur1=stack1.top();
                        cur2=stack2.top();
                        stack1.pop();
                        stack2.pop();
                        cur1=cur1->right;
                        cur2=cur2->right;
                    }
                }
                if(cur1==NULL && stack1.empty()){
                    if(cur2!=NULL || !stack2.empty()){
                        return false;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(cur2==NULL && stack2.empty()){
                        if(cur1!=NULL || !stack1.empty()){
                            return false;
                        }
                        else{
                            break;
                        }
                    }
                
            }
        }
        return true;
    }
};