/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:/*
    ListNode *Intersecthelper(ListNode* small, ListNode* large, int diff){
        while(diff){                     // making the pointer of the larger ll cover some ground so that we can start
            large = large->next;         // comparing the nodes from an equal footing
            diff--;
        }
        while(small != large){     // they can be equal at an intersecting node or at NULL
            small = small->next;
            large = large->next;
        }
        return small;
    }*/

    // T.C = O(nA) + O(nB) + O(nB-nA) + O(nA) = O(nA + 2nB)       S.C = O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        /*ListNode* tempA = headA;
        ListNode* tempB = headB;
        int nA = 0, nB = 0;
        while(tempA != NULL){
            nA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            nB++;
            tempB = tempB->next;
        }
        if(nA<nB)
            return Intersecthelper(headA, headB, nB-nA);   // 1st param pointer which has travelled less no of nodes and 
        else                                                   // 2nd param pointer which has travelled more
            return Intersecthelper(headB, headA, nA-nB);*/
    
        if(headA == NULL || headB == NULL)     // T.C = O(nA + nB)(because both tempA and tempB are traversing the same no of nodes i.e. nA+nB)      
            return NULL;                         // S.C = O(1)
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB){   // what if there is only a SLL and both the heads are pointing to the first node of the SLL
            tempA = tempA->next;
            tempB = tempB->next;
            if(tempA == tempB)  // this if check will be true if both the pointers collide or don't collide at all(because both of them will be pointing to NULL)
                return tempA;
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
        }
        return tempA;
    }
};