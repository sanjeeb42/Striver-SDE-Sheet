int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    
   int ans=0;
   if(root==NULL)return 0;
  queue<TreeNode<int>*> q;
   q.push(root);
   q.push(NULL);
   if(root==NULL)
   {
       return ans;
   }

   while(q.size()>1)
   {
       TreeNode<int>* temp = q.front();
       q.pop();
       
       if(temp==NULL){
           int size=q.size();
           ans=max(ans,size);
           q.push(NULL);
           continue;
       }
      
       if(temp->left)
           q.push(temp->left);
       if(temp->right)
           q.push(temp->right);
   }
   return ans;
}
