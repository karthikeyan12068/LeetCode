/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* build(TreeNode* root,ListNode* head){
    int len=0;
    ListNode* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(len==0){
        return NULL;
    }
    if(len==1){
        return new TreeNode(head->val);
    }
    ListNode* lt=NULL;
    ListNode* t_lt=NULL;
    ListNode* rt=NULL;
    ListNode* t_rt=NULL;
    int counter=0;
    while(counter!=len){
        if(counter==len/2){
            root=new TreeNode(head->val);
        }
        if(counter<len/2){
            if(lt==NULL){
                lt=new ListNode(head->val);
                t_lt=lt;
            }
            else{
                t_lt->next=new ListNode(head->val);
                t_lt=t_lt->next;
            }
        }
        if(counter>len/2){
            if(rt==NULL){
                rt=new ListNode(head->val);
                t_rt=rt;
            }
            else{
                t_rt->next=new ListNode(head->val);
                t_rt=t_rt->next;
            }
        }
        head=head->next;
        counter++;
    }
    root->left=build(root->left,lt);
    root->right=build(root->right,rt);
    return root;
}
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root=NULL;
        root=build(root,head);
        return root;
    }
};