// Multiply two linked lists

// Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 
// Note: The output could be large take modulo 109+7.

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long mod=1000000007;
    Node* temp=l1;
    long long num1=0,num2=0;
    while(temp){
        num1=(num1*10)%mod+temp->data;
        temp=temp->next;
    }
    temp=l2;
    while(temp){
        num2=(num2*10)%mod+temp->data;
        temp=temp->next;
    }
    return (num1*num2)%mod;
}