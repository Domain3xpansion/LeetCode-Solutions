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
    ListNode* oddEvenList(ListNode* head) {
        /*if(head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        vector<int> vec;
        while(temp != NULL && temp->next != NULL){
            vec.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp)
            vec.push_back(temp->val);
        temp = head->next;
        while(temp != NULL && temp->next != NULL){
            vec.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp)
            vec.push_back(temp->val);
        temp = head;
        int i=0;
        while(temp != NULL){
            temp->val = vec[i];
            temp = temp->next;
            i++;
        }
        return head;*/

        if(head == NULL || head->next == NULL)
            return head;
        ListNode* todd = head;
        ListNode* even = head->next;
        ListNode* teven = head->next;
        while(teven != NULL && teven->next != NULL){
            todd->next = todd->next->next;
            teven->next = teven->next->next;
            todd = todd->next;
            teven = teven->next;
        }
        todd->next = even;
        return head;
    }
};