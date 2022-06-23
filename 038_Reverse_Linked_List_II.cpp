// 92. Reverse Linked List II

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL||left==right)
            return head;
        
        ListNode *curr=head, *prev=NULL;
        for(int i=1; i<left;i++){
            prev=curr;
            curr=curr->next;
        }
        
        ListNode *start=curr;
        
        for(int i=1; i<=right-left;i++){
            curr=curr->next;
        }
        
        ListNode *rightNodes=curr->next;
        curr->next=NULL;
        
        ListNode* newStart=reverse(start);
        
        if(prev) prev->next=newStart;
        curr=newStart;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=rightNodes;
        
        if(left==1)
        return newStart;
        else return head;
    }
};