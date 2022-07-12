TreeNode<int>* solve(TreeNode<int>*root,int x,int y,TreeNode<int>*ans){
    if(root==NULL) return NULL;
    if(root->data==x or root->data==y)return root;
    
    TreeNode<int>* l=solve(root->left,x,y,ans);
    TreeNode<int>* r=solve(root->right,x,y,ans);
    
    if(l && r)
    {
        ans=root;
    }
    else if(l && !r)
    {
        return l;
    }
     else if(!l && r)
    {
        return r;
    }
    else return NULL;
    
}


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int>*ans=solve(root,x,y,ans);
    return ans->data;
    
}
