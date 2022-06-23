// 143. Reorder List

// You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
    ListNode* findMid(ListNode* head){
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode *curr=head, *prev=NULL;
        while(curr!=NULL){
            ListNode* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* mid=findMid(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        head2=reverse(head2);
        
        ListNode* itr=head;
        ListNode* temp1=itr;
        ListNode* temp2=head2;
        while(temp1&&temp2){
            temp1=temp1->next;
            itr->next=temp2;
            itr=itr->next;
            temp2=temp2->next;
            itr->next=temp1;
            itr=itr->next;
        }
    }
};