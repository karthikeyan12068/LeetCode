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
class BSTIterator {
public:
    list<int>l1;
    void ret(TreeNode* root){
        if(root!=NULL){
            ret(root->left);
            l1.push_back(root->val);
            ret(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        ret(root);
    }
    
    int next() {
        int x=l1.front();
        l1.pop_front();
        return x;
    }
    
    bool hasNext() {
        return !l1.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */