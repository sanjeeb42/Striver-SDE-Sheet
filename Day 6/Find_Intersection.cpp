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


//Naive Hashmap

// Hashing Approach
// Traverse the first list and store the address/reference to each node in a hash set/map/dictionary.
// Then check every node in the second list:
// If the address of the node of the second list appears in the hash set/map/dictionary, then the node is the intersection node
// If we do not find any address of the second list node in the hash set/map/dictionary then return -1

int findIntersection(Node *firstHead, Node *secondHead)
{
    
    Node *firstHeadTmp = firstHead;

    // Set to store reference of first list.
    unordered_set<Node *> referenceSet;

    // Traverse the first list and store the reference in the set.
    while (firstHeadTmp != NULL)
    {
        referenceSet.insert(firstHeadTmp);
        firstHeadTmp = firstHeadTmp->next;
    }

    Node *secondHeadTmp = secondHead;

    // Traverse second list, check if the reference of current node is present or not.
    // If it is present then return the data of that node.
    while (secondHeadTmp != NULL)
    {
        if (referenceSet.find(secondHeadTmp) != referenceSet.end())
        {
            return secondHeadTmp->data;
        }
        secondHeadTmp = secondHeadTmp->next;
    }

    return -1;
}
