class Solution {
public:
    int preindex=0;
    
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end){
        if(start>end)return NULL;
        
        TreeNode* root=new TreeNode(preorder[preindex++]);
        
        //Finding Breakindex
        int breakindex;
        for(int i=start;i<=end;i++){
            if(inorder[i]==root->val){
                breakindex=i;
                break;
            }
        }
        
        
        root->left=solve(preorder,inorder,start,breakindex-1);
        root->right=solve(preorder,inorder,breakindex+1,end);
        
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1);
    }
};
