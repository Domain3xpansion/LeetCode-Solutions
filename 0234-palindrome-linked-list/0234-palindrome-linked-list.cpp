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
    ListNode* reverseList(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        /*ListNode* temp = head;                       
        stack<int> s;                            
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != s.top())
                return false;
            temp = temp->next;
            s.pop();
        }       
        return true;*/
        if(head == NULL || head->next == NULL)     
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){             
            slow = slow->next;                              
            fast = fast->next->next;
        }
        ListNode* newhead = reverseList(slow->next);         
        ListNode* first = head;
        ListNode* second = newhead;
        while(second != NULL){           
            if(first->val != second->val){
                reverseList(newhead);      
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newhead);           
        return true;
    }
};