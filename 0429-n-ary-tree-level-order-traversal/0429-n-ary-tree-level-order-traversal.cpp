/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v1;
        if(root==NULL){
            return v1;
        }
       list<Node*>temp_root_store={root};
        
        
        while(!temp_root_store.empty()){
            vector<int>temp_val_store;
            int x=temp_root_store.size();
            for(int i=0;i<x;i++){
                temp_val_store.push_back(temp_root_store.front()->val);
                Node* temp=temp_root_store.front();
                for(auto it:temp->children){
                    temp_root_store.push_back(it);
                }
                temp_root_store.pop_front();
            }
            v1.push_back(temp_val_store);
        }
        return v1;
    }
};