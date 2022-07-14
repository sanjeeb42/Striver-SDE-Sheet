TreeNode<int>* solve(vector<int>&inorder,vector<int>&preorder,int start,int end,int &preindex,unordered_map<int,int>&mp)
    {
        if(start>end)return NULL;    
        TreeNode<int>* root=new TreeNode<int>(preorder[preindex--]);
        
        //Finding Breakindex
        int breakindex=mp[root->data];
//         for(int i=start;i<=end;i++){
//             if(inorder[i]==root->data){
//                 breakindex=i;
//                 break;
//             }
//         }
        root->right=solve(inorder,preorder,breakindex+1,end,preindex,mp);
        root->left=solve(inorder,preorder,start,breakindex-1,preindex,mp);
        
        
        return root;       
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
    //    Write your code here
    
    int n=postorder.size();
    int preindex=n-1;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    return solve(inorder,postorder,0,postorder.size()-1,preindex,mp);
}
