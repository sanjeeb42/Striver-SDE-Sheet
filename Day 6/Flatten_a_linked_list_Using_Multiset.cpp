Node *flatten(Node *root)
{
   // Your code here
    Node *head=new Node(-1);
   Node *ans=head;
   
   
  multiset<pair<int,Node*>>pq;
  
  while(root!=NULL){
      pq.insert({root->data,root});
      root=root->next;
  }
  
  
//   cout<<"Exit"<<endl;
  while(pq.size()>0){
   
      auto front=*pq.begin();
      pq.erase(pq.begin());
      
      int val=front.first;
      Node* curr_node=front.second;

      head->bottom=curr_node;
      head=curr_node;
      
      if(curr_node->bottom!=NULL)pq.insert({curr_node->bottom->data,curr_node->bottom});
  
  }
  return ans->bottom;
}
