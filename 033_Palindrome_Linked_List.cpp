// 234. Palindrome Linked List

// Given the head of a singly linked list, return true if it is a palindrome.

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
    ListNode* reverseHalf(ListNode* newH){
        if(newH==NULL||newH->next==NULL)
            return newH;
        ListNode* curr=newH, *prev=NULL, *nextNode=NULL;
        
        while(curr!=NULL){
            nextNode=curr->next;;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL&&head->next==NULL){
            return true;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newH=slow->next;
        slow->next=NULL;
        newH=reverseHalf(newH);
        
        bool res=true;
        ListNode* c1=head;
        ListNode* c2=newH;
        
        while(c1!=NULL&&c2!=NULL){
            if(c1->val!=c2->val){
                res=false;
                break;
            }
            c1=c1->next;
            c2=c2->next;
        }
        slow->next=reverseHalf(newH);
        return res;
    }
};

// recursion
class Solution {
    
ListNode* start;
int matchCount = 0;
    
public:
    bool isPalindrome(ListNode* head) {
        int ln = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            ln++;
            curr = curr->next;
        }
        
        start = head;
        
        findMatchCount(head);
        
        if(matchCount == ln){
            return true;
        }else{
            return false;
        }
    }
    
public:
    void findMatchCount(ListNode* head) {
        if(head == nullptr){
            return;
        }
        
        findMatchCount(head->next);
        
        if(start->val == head->val){
            matchCount++;
        }  
        
        start = start->next;
    }
};