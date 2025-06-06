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
class Solution {
public:
    ListNode* partition(ListNode* head, int x){
        ListNode *left = new ListNode(-1), *right = new ListNode(-1);
        ListNode *lefttail = left, *righttail = right, *temp = head;
        while(temp != NULL){
            if(temp->val < x){
                lefttail->next = temp;
                lefttail = lefttail->next;
            }
            else{
                righttail->next = temp;
                righttail = righttail->next;
            }
            temp = temp->next;
        }
        lefttail->next = right->next;
        righttail->next = NULL;
        return left->next;
    }
};