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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();       // it is a dummy node
        ListNode *temp1 = l1, *temp2 = l2, *temp3 = res;    // temp3 pointer will link the digits in the resultant sum of the two numbers
        int carry = 0;
        while(temp1 || temp2){
            int sum = 0;
            if(temp1)
                sum += temp1->val;
            if(temp2)
                sum += temp2->val;
            if(carry)
                sum += carry;
            ListNode* new_node = new ListNode(sum%10);    // for every addition of digits in unit's place, tenth's place etc, a new node is being created
            carry = sum/10;
            temp3->next = new_node;
            temp3 = temp3->next;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next; 
        }
        if(carry){
            ListNode* new_node = new ListNode(carry);
            temp3->next = new_node;
        }
        ListNode* summation = res->next;
        delete res;      // deleting the dummy node
        return summation;
    }
};