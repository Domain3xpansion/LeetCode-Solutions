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
    ListNode* findkth(ListNode* temp, int k){
        k = k - 1;
        while(k > 0 && temp != nullptr){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reversell(ListNode* head){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kthnode = findkth(temp, k);
            if(kthnode == NULL){
                if(prev)
                    prev->next = temp;
                break;
            }
            ListNode* nexxt = kthnode->next;
            kthnode->next = NULL;
            reversell(temp);
            if(temp == head)
                head = kthnode;
            else
                prev->next = kthnode;
            prev = temp;
            temp = nexxt;
        }
        return head;
    }
};