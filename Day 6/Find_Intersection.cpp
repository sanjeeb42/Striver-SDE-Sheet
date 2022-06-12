int count(Node* head){
    Node* curr=head;
    int cnt=0;
    while(curr!=NULL){
        cnt++;
        curr=curr->next;
    }
    return cnt;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int cnt1=count(firstHead);
    int cnt2=count(secondHead);
    int diff=abs(cnt1-cnt2);
    if(cnt1>cnt2)
    {
        for(int i=0;i<diff;i++){
            firstHead=firstHead->next;
        }  
    }
    else{
        for(int i=0;i<diff;i++){
            secondHead=secondHead->next;
        }
    }
    
    while(firstHead!=NULL and secondHead!=NULL)
    {
        if(firstHead==secondHead){
            return firstHead->data;
        }
        firstHead=firstHead->next;
        secondHead=secondHead->next;

    }  
    return -1;
}
