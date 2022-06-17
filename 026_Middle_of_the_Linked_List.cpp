// 876. Middle of the Linked List

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Method 1
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

// Method1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int c=0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        temp=head;
        for(int i=0; i<c/2; i++){
            temp=temp->next;
        }
        return temp;
    }
};

// Method 2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};