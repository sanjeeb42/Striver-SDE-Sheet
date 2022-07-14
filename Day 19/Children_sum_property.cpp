int solve(BinaryTreeNode <int>* root){
    if(root==NULL) return 0;
    
    if(root->left==NULL && root->right==NULL) return root->data;
    
    int parent=root->data;
    int lchild=root->left!=NULL?root->left->data:0;
    int rchild=root->right!=NULL?root->right->data:0;
    
    if(lchild+rchild<parent)
    {
        // we need to modify only if lchild + rchild is less than parent value 
        // Change it  to parent value of each left & right child
        
            if(root->left!=NULL)
            {
                root->left->data=(root->data);
            }
            if(root->right!=NULL)
            {
                root->right->data=(root->data);
            }   
    }
    
    lchild=solve(root->left);
    rchild=solve(root->right);
    
    // Once solved , check if property is followed or not
    root->data=lchild+rchild;
    
    return root->data;
}
void print(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    
    int ans=solve(root);
  //  print(root);
    return;
}  
