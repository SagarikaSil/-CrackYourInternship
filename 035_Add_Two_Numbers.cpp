// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)
            return l1!=NULL?l1:l2;
        
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* head=new ListNode(-1);
        ListNode* itr=head;
        int carry=0;
        while(head1!=NULL||head2!=NULL||carry!=0){
            int sum=(head1?head1->val:0)+(head2?head2->val:0)+carry;
            int ld=sum%10;
            carry=sum/10;
            itr->next=new ListNode(ld);
            itr=itr->next;
            if(head1)
                head1=head1->next;
            if(head2)
                head2=head2->next;
        }        
        return head->next;
    }
};