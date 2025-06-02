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
    ListNode* deleteDuplicates(ListNode* head){
        if(head == NULL)
            return head;
        unordered_map<int, int> um;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            if(um[temp->val]==0){
                um[temp->val]++;
                prev = temp;
                temp = temp->next;
            }else{
                temp = temp->next;
                prev->next = temp;
            }
        }
        return head;
    }
};