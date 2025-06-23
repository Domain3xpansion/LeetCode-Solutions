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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*if(head == NULL || n <= 0) return head;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        if(count == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int result = count - n;
        temp = head;
        while(result>1){
            temp = temp->next;
            result--;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;*/

        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++){           
            if(fast == NULL) 
                return head;         
            fast = fast->next;
        }
        if(fast == NULL){                   
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(fast->next != NULL){        
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;         
        slow->next = slow->next->next;
        delete nodeToDelete;
        return head;
    }
};