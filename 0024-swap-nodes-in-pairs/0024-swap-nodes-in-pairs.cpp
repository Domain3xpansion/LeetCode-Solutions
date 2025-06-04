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
        ListNode* curr = head->next;     // this node will become the first node after swapping
        while(curr != NULL){
            prev->next = curr->next;    // make 1st node of pair point to whatever comes after 2nd node
            curr->next = prev;     // make 2nd node point to 1st node
            if(head == curr->next)    // for swapping the very first pair
                head = curr;     // make head to point to curr (the new 1st node of linked list)
            else   // for subsequent pairs, connect last node of previous pair point to curr (new first node of current pair)
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