void inorder_t(BinaryTreeNode<int>* root,vector<int>&inorder){
    if(root==NULL)return;
    
    //Go left
    inorder_t(root->left,inorder);
    inorder.push_back(root->data);
    inorder_t(root->right,inorder);
    
}


void postorder_t(BinaryTreeNode<int>* root,vector<int>&postorder){
    if(root==NULL)return;
    
    //Go right
    postorder_t(root->right,postorder);
    postorder.push_back(root->data);
    postorder_t(root->left,postorder);
   
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    vector<int>inorder;
    vector<int>postorder;
    inorder_t(root,inorder);
    postorder_t(root,postorder);
    
    return inorder==postorder;
}
