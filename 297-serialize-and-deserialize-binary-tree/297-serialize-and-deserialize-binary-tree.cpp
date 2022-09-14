/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
TreeNode* build(TreeNode* root,vector<int>&trav,list<int>&l1){
    if(trav.front()==-1001){
        pop_front(trav);
        if(trav.front()==-1001){
            pop_front(trav);
            l1.pop_front();
        }
        return NULL;
    }
    root=new TreeNode(l1.front());
    l1.pop_front();
    if(trav.front()!=-1001){
        l1.push_back(trav.front());
        pop_front(trav);
        if(trav.front()!=-1001){
            l1.push_back(trav.front());
            pop_front(trav);
        }
    }
    root->left=build(root,trav,l1);
    root->right=build(root,trav,l1);
    return root;
}
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s1="";
        if(root==NULL){
            return s1;
        }
        
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push(cur);
                s1+=to_string(cur->val)+",";
                cur=cur->left;
                
            }
            else{
                s1+="-1001,";
                cur=stack.top();
                stack.pop();
                cur=cur->right;
            }
        }
        
        return s1;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<int>trav;
        if(data.empty()){
            return NULL;
        }
        int i;
        stringstream ss(data);
        while (ss >> i) {
            trav.push_back(i);
            ss.ignore(1);
        }
        TreeNode* r=new TreeNode(trav.front());
        stack<pair<TreeNode*,int>>stack;
        TreeNode* cur=r;
        stack.push({cur,0});
        trav.pop_front();
        while(!trav.empty()){
            cur=stack.top().first;
            if(trav.front()==-1001){
                if(stack.top().second==0){
                    stack.top().second++;
                }
                else{
                    stack.pop();
                }
            }
            else{
                if(stack.top().second==0){
                   cur->left=new TreeNode(trav.front());
                    stack.top().second++;
                    cur=cur->left;
                    stack.push({cur,0});
                }
                else{
                     cur->right=new TreeNode(trav.front());
                    cur=cur->right;
                    stack.pop();
                    stack.push({cur,0});
                }
            }
            trav.pop_front(); 
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));