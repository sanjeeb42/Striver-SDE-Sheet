void inorder_t(TreeNode<int> *root,vector<int>&inorder){
    if(root==NULL)return;
    inorder_t(root->left,inorder);
    inorder.push_back(root->data);
    inorder_t(root->right,inorder);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int>inorder;
    inorder_t(root,inorder);
    if(k>inorder.size())return -1;
    return inorder[inorder.size()-1-(k-1)];
    
}
