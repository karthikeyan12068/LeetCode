/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        if(root==NULL){
            return s;
        }
        while(!stack.empty() || cur!=NULL){
             if(cur!=NULL){
                 stack.push(cur);
                 s+=to_string(cur->val)+",";
                 cur=cur->left;
             }
            else{
                s+="-1001,";
                cur=stack.top();
                stack.pop();
                cur=cur->right;
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s1) {
        TreeNode* root=NULL;
        stringstream ss(s1);
        vector<int>s;
        int i;
        while (ss >> i) {
            s.push_back(i);
            ss.ignore(1);
        }
        TreeNode* cur=root;
        stack<pair<TreeNode*,int>>stack;
        int x=0;
        while(x!=s.size()){
           if(s[x]!=-1001){
               if(!stack.empty()){
                   stack.top().second++;
                   if(stack.top().second==1){
                       cur=stack.top().first;
                       cur->left=new TreeNode(s[x]);
                       cur=cur->left;
                       stack.push({cur,0});
                   }
                   else{
                       cur=stack.top().first;
                       cur->right=new TreeNode(s[x]);
                       cur=cur->right;
                       stack.pop();
                       stack.push({cur,0});
                   }
               }
               else{
                   cur=new TreeNode(s[x]);
                   if(root==NULL){
                       root=cur;
                   }
                   stack.push({cur,0});
               }
           }
            else{
                stack.top().second++;
                if(stack.top().second==2){
                    stack.pop();
                }
            }
            x++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;