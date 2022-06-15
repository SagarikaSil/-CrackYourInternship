// 1290. Convert Binary Number in a Linked List to Integer

// Given head which is a reference node to a singly-linked list. 
// The value of each node in the linked list is either 0 or 1. 
// The linked list holds the binary representation of a number.
// Return the decimal value of the number in the linked list.

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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        while(temp->next!=NULL){
            temp=temp->next;
            c++;
        }
        temp=head; int sum=0;
        while(temp!=NULL){
            sum+=temp->val*pow(2,c);
            c--;
            temp=temp->next;
        }
        return sum;
    }
};