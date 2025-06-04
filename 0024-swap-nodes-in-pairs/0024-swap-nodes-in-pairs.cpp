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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev2 = NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            prev->next = curr->next;
            curr->next = prev;
            if(head == curr->next)
                head = curr;
            else
                prev2->next = curr;
            prev2 = prev;
            prev = prev->next;
            if(prev != NULL)
                curr = prev->next;
            else
                curr = NULL;
        }
        return head;
    }
};