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
    ListNode* deleteMiddle(ListNode* head) {
        /*if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        count = (count/2) - 1;
        while(count){
            temp = temp->next;
            count--;
        }
        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete middle;
        return head;*/
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }             
        ListNode* middle2 = slow->next;          
        slow->next = slow->next->next;       
        delete middle2; 
        return head;
    }
};