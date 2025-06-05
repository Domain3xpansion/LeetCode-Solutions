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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;
        ListNode* prev = dummynode;
        int i=1;
        while(i<left){
            prev = prev->next;
            i++;
        }
        ListNode* curr = prev->next;
        i = 1;
        while(i<=right-left){
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            i++;
        }
        return dummynode->next;
    }
};