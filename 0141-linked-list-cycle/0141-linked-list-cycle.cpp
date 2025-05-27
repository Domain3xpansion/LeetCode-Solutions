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
        unordered_map<ListNode*, int> um;
        ListNode* temp = head;
        while(temp != NULL){
            auto it = um.find(temp);
            if(it != um.end()){      // if that node already exists in the hashmap, that means cycle is detected
                return true;
            }
            um[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};