int diameter(TreeNode<int>*root,int &ans){
    
    //Base case
    if(root==NULL)return 0;
    
    //Hypothesis Recursive call
    int l=diameter(root->left,ans);
    int r=diameter(root->right,ans);
    
    //Induction
 
   // If it wants to be the root Then ans=max(ans,1+l+r)
    //If it doesn't want to be the ans ,Then it will pass 1+max(l,r) to parent
    //else it will update ans=max(ans,1+l+r)
    
    int topass=1+max(l,r);
//     int res=max(topass,1+l+r);
    ans=max(ans,1+l+r);
    return topass;
  
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    
    //best part about diameter is that I can/can't pass through origin
    int ans=0;
    int fans=diameter(root,ans);
    
    return ans-1;
    
}
