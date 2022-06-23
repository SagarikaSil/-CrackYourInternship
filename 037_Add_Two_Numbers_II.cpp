// 445. Add Two Numbers II

// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* reverse(ListNode* head){
        ListNode *curr=head, *prev=NULL;
        while(curr!=NULL){
            ListNode *forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL||l2==NULL){
            return l1!=NULL?l1:l2;
        }
        ListNode *head1=reverse(l1);
        ListNode *head2=reverse(l2);
        ListNode *c1=head1;
        ListNode *c2=head2;
        ListNode *head=new ListNode(-1);
        ListNode *itr=head;
        int carry=0;
        while(c1!=NULL||c2!=NULL||carry!=0){
            int sum=(c1?c1->val:0)+(c2?c2->val:0)+carry;
            int ld=sum%10;
            carry=sum/10;
            ListNode *newNode=new ListNode(ld);
            itr->next=newNode;
            itr=itr->next;
            if(c1) c1=c1->next;
            if(c2) c2=c2->next;
        }
        l1=reverse(head1);
        l2=reverse(head2);
        return reverse(head->next);
    }
};