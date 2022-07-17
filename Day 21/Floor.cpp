int floorInBST(TreeNode<int> * root, int input)
{
    // Write your code here.
    if (root == NULL) return -1;
    // Your code here
    int ans=-1;
    while(root!=NULL)
    {    
        if(root->val==input)return input;
        else if(root->val<input)
        {
             ans=root->val;
            root=root->right;
        }
        else if(root->val>input)
        {          
            root=root->left;          
        }
    }    
    return ans;
}
