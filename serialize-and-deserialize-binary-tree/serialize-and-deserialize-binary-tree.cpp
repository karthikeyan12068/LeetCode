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
    int x=1;
    void ret(TreeNode* root,string &p,int c,unordered_map<TreeNode*,int>&m){
        if(c==0){
            if(root!=NULL){
                p+='[';
                m[root]=x;
                p+=to_string(root->val);
                p+=',';
                p+=to_string(x);
                x++;
                p+=']';
                ret(root->left,p,c,m);
                ret(root->right,p,c,m);
            }
        }
        else{
            if(root!=NULL){
                ret(root->left,p,c,m);
                p+='[';
                p+=to_string(root->val);
                p+=',';
                p+=to_string(m[root]);
                p+=']';
                ret(root->right,p,c,m);
            }
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        x=0;
        string s="";
        unordered_map<TreeNode*,int>m;
        ret(root,s,0,m);
        s+='+';
        ret(root,s,1,m);
        return s;
    }
    TreeNode* build(vector<pair<int,int>>& preorder, vector<pair<int,int>>& inorder){
        if(inorder.size()==0){
            return NULL;
        }
        if(inorder.size()==1){
            preorder.erase(preorder.begin());
            return new TreeNode(inorder[0].first);
        }
        int ind=-1;
        for(int i=0;i<inorder.size();i++){
            if(preorder[0].second==inorder[i].second){
                ind=i;
                break;
            }
        }
        vector<pair<int,int>>left,right;
        for(int i=0;i<ind;i++){
            left.push_back({inorder[i].first,inorder[i].second});
        }
        for(int i=ind+1;i<inorder.size();i++){
            right.push_back({inorder[i].first,inorder[i].second});
        }
        TreeNode* root=new TreeNode(preorder[0].first);
        preorder.erase(preorder.begin());
        root->left=build(preorder,left);
        root->right=build(preorder,right);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<pair<int,int>>pre,in;
        int f=0;
        string temp="";
        pair<int,int>p;
        for(int i=0;i<data.length();i++){
            if(f==0){
                if(data[i]=='+'){
                    f=1;
                    continue;
                }
                if(data[i]=='['){
                    continue;
                }
                if(data[i]==']'){
                    int x=stoi(temp);
                    p.second=x;
                    pre.push_back(p);
                    temp="";   
                }
                else{
                    if(data[i]==','){
                        int x=stoi(temp);
                        p.first=x;
                        temp="";
                        continue;
                    }
                    temp+=data[i];
                    
                }
            }
            else{
                if(data[i]=='['){
                    continue;
                }
                if(data[i]==']'){
                    int x=stoi(temp);
                    p.second=x;
                    in.push_back(p);
                    temp="";   
                }
                else{
                    if(data[i]==','){
                        int x=stoi(temp);
                        p.first=x;
                        temp="";
                        continue;
                    }
                    temp+=data[i];
                }
            }
        }
        
        TreeNode* root=build(pre,in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));