// 83. Remove Duplicates from Sorted List

// Given the head of a sorted linked list, delete all duplicates such 
// that each element appears only once. Return the linked list sorted as well.

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

// method1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        if(head->next->next == NULL && head->val == head->next->val)            return head->next;
        
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};

// method2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* curr=head->next;
        ListNode* prev=head;
        while(curr!=NULL){
            if(prev->val==curr->val){
                ListNode* temp=curr;
                prev->next=curr->next;
                curr=prev->next;
                temp->next=NULL;
                delete temp;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};