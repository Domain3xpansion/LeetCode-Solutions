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
    ListNode* convertarrtoll(vector<int> arr){
        if(arr.empty()) return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* linker = head;
        for(int i=1; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            linker->next = temp;
            linker = linker->next;      
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        vector<int> vec;
        while(temp1 != NULL){
            vec.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            vec.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(vec.begin(), vec.end());
        ListNode* res = convertarrtoll(vec);
        return res;*/
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) 
            temp->next = list1;
        else 
            temp->next = list2;
        return dummyNode->next;
    }
};