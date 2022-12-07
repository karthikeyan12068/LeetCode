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
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        stack<pair<Node*,int>>stack1;
        stack1.push({root,1});
        int maxht=0,ht=0;
        while(!stack1.empty()){
            ht=stack1.top().second;
            maxht=max(maxht,ht);
            Node* temp=stack1.top().first;
            stack1.pop();
            for(auto it:temp->children){
                stack1.push({it,ht+1});
            }
        }
        return maxht;
    }
};