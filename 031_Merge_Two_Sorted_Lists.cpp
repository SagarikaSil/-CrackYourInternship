// 21. Merge Two Sorted Lists

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL&&list2==NULL)
            return NULL;
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        ListNode *head1=list1;
        ListNode *head2=list2;
        ListNode *fh=NULL, *ft=NULL;
        
        if(head1->val<=head2->val){
            fh=head1; ft=head1;
            head1=head1->next;
        }
        else{
            fh=head2, ft=head2;
            head2=head2->next;
        }
        while(head1!=NULL&&head2!=NULL){
            if(head1->val<=head2->val){
                ft->next=head1;
                head1=head1->next;
                ft=ft->next;
            }
            else{
                ft->next=head2;
                head2=head2->next;
                ft=ft->next;
            }
        }
        if(head1==NULL&&head2!=NULL){
            ft->next=head2;
        }
        else if(head2==NULL&&head1!=NULL){
            ft->next=head1;
        }
        return fh;
    }
};