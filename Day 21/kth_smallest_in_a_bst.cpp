void inorder_t(TreeNode<int> *root,vector<int>&inorder){
    if(root==NULL)return;
    inorder_t(root->left,inorder);
    inorder.push_back(root->data);
    inorder_t(root->right,inorder);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int>inorder;
    inorder_t(root,inorder);
    return inorder[k-1];
}
