 TreeNode<int>* solve(vector<int>&inorder,vector<int>&preorder,int start,int end,int &preindex,unordered_map<int,int>&mp)
    {
        if(start>end)return NULL;    
        TreeNode<int>* root=new TreeNode<int>(preorder[preindex++]);
        
        //Finding Breakindex
        int breakindex=mp[root->data];
//         for(int i=start;i<=end;i++){
//             if(inorder[i]==root->data){
//                 breakindex=i;
//                 break;
//             }
//         }
              
        root->left=solve(inorder,preorder,start,breakindex-1,preindex,mp);
        root->right=solve(inorder,preorder,breakindex+1,end,preindex,mp);
        
        return root;       
    }

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preindex=0;
    int n=preorder.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    return solve(inorder,preorder,0,preorder.size()-1,preindex,mp);
}
