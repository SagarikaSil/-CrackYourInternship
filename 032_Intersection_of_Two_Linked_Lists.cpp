// 160. Intersection of Two Linked Lists

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// The test cases are generated such that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode *head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        int c1=findLength(a);
        int c2=findLength(b);
        int d=abs(c1-c2);
        if(c1>c2)
        {
            while(d--)  a=a->next;
        }
        else
        {
            while(d--) b=b->next;
        }
        while(a&&b)
        {
            if(a==b) return a;
            else{
                a=a->next;
                b=b->next;
            }
        }
        return NULL;
    }
};