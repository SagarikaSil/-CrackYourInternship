// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nHead = new ListNode(-1);
        nHead->next=head;
        ListNode* left = nHead;
        ListNode* right = nHead;
    
        while(right->next!=NULL){
            if(n>0){
                right=right->next;
                n--;
                continue;
            }
            left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return nHead->next;
    }
};