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
    bool hasCycle(ListNode *head) {
        //Naive solution
        /*unordered_map<ListNode*, int> um;
        ListNode* temp = head;
        while(temp != NULL){
            auto it = um.find(temp);
            if(it != um.end()){      // if that node already exists in the hashmap, that means cycle is detected
                return true;
            }
            um[temp] = 1;
            temp = temp->next;
        }
        return false;*/
        // Tortoise and Hare Algo    TC = O(n)       SC = O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};