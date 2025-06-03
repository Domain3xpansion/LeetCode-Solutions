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
    ListNode* deleteDuplicates(ListNode* head) {
        /*if(head == NULL)
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
        return head2;*/
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;
        ListNode* current = head;
        ListNode* prev = dummynode;
        while(current != NULL){
            if(current->next != NULL && current->val == current->next->val){
                while(current->next != NULL && current->val == current->next->val){
                    current = current->next;
                }
                prev->next = current->next;
            }else{
                prev = prev->next;
            }
            current = current->next;
        }
        return dummynode->next;
    }
};