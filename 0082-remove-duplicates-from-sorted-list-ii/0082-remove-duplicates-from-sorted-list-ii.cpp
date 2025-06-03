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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        map<int, int> um;
        ListNode* temp = head;
        while(temp != NULL){
            um[temp->val]++;
            temp = temp->next;
        }
        ListNode* head2 = nullptr;
        ListNode* tail = nullptr;
        for(auto &it:um){
            if(it.second == 1){
                ListNode* newNode = new ListNode(it.first);
                if(head2 == nullptr){
                    head2 = newNode;
                    tail = newNode;
                }else{
                    tail->next = newNode;  
                    tail = tail->next;
                }
            }
        }
        return head2;
        //return reverseList(head2);
    }
};