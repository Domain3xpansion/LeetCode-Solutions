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
    ListNode* reverseList(ListNode* head) {
        // It is a recursive solution
        /*if(head == NULL || head->next == NULL) return head;      
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;      
        front->next = head;            
        head->next = NULL;             
        return newhead;*/
        // It is a iterative solution
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* nexxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nexxt;
        }
        return prev;
    }
};