int findCeil(BinaryTreeNode<int> *root, int input){
    // Write your code here.

    if (root == NULL) return -1;
    // Your code here
    int ans=-1;
    while(root!=NULL)
    {    
        if(root->data==input)return input;
        else if(root->data<input)
        {
            root=root->right;
        }
        else if(root->data>input)
        {
            ans=root->data;
            root=root->left;
            
        }
    }
    
    return ans;

}
