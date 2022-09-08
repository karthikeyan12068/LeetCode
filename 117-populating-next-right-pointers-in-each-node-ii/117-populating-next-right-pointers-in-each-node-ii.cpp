/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        map<int,Node*>m1;
        Node* cur=root;
        int h=1;
        stack<pair<Node*,int>>stack;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push({cur,h});
                if(m1[h]==NULL){
                    m1[h]=cur;
                }
                else{
                    m1[h]->next=cur;
                    m1[h]=cur;
                }
                h++;
                cur=cur->left;
            }
            else{
                cur=stack.top().first;
                h=stack.top().second;
                h++;
                stack.pop();
                cur=cur->right;
            }
        }
        return root;
    }
};