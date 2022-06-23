// 138. Copy List with Random Pointer

// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        unordered_map<Node*,Node*> map;
        Node* curr=head;
        Node* newH=new Node(-1);
        Node *itr=newH;
        
        while(curr!=NULL){
            Node* temp=new Node(curr->val);
            map[curr]=temp;      
            itr->next=temp;
            itr=itr->next;
            curr=curr->next;
        }
        newH=newH->next;
        itr->next=NULL;
        curr=head;
        itr=newH;
        while(curr!=NULL){
            itr->random=(curr->random)?map[curr->random]:NULL;
            itr=itr->next;
            curr=curr->next;
        }
        return newH;
    }
};