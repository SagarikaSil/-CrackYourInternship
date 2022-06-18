// 203. Remove Linked List Elements

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        
        head->next=removeElements(head->next,val);
        
        return head->val==val? head->next: head;
    }
};

// Method2
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nextNode;
        while ((head != NULL) && (head->val == val)) {
            nextNode = head->next;
            delete head;
            head = nextNode;
        }
        ListNode* curr = head;
        while (curr != NULL) {
            if ((curr->next != NULL) && (curr->next->val == val)) {
                ListNode* nextNode = curr->next->next;
                delete curr->next;
                curr->next = nextNode;
            } else {
                curr = curr->next; 
            }
        }
        return head;
    }
};