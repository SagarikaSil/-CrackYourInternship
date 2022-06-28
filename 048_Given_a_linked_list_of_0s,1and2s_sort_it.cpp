// Given a linked list of 0s, 1s and 2s, sort it.

// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

class Solution
{
    public:
    Node* segregate(Node *head) {
        int c1=0,c2=0,c3=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0) c1++;
            else if(temp->data==1) c2++;
            else c3++;
            temp=temp->next;
        }
        temp=head; int i=0;
        while(c1){
            temp->data=0;
            temp=temp->next;
            c1--;
        }
        while(c2){
            temp->data=1;
            temp=temp->next;
            c2--;
        }
        while(c3){
            temp->data=2;
            temp=temp->next;
            c3--;
        }
        return head;
    }
};