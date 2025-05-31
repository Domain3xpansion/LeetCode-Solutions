/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> um;
        ListNode* temp = head;
        while(temp != NULL){
            auto it = um.find(temp);
            if(it != um.end()){      
                return temp;
            }
            um[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};