bool solve1(TreeNode<int>* root,int B,vector<int>&ans)
{
    //Base case
    if(root==NULL)return false;
    if(root->left==NULL and root->right==NULL && root->data!=B){
         return false;
    }
    if(root->data==B)
    {
            ans.push_back(root->data);
            return true;
    }
    
    //Recursive call
    bool l=solve1(root->left,B,ans);
    bool r=solve1(root->right,B,ans);
    
    //Induction
    
    if(l or r){
        ans.push_back(root->data);
    }
    
    return l or r;
    
} 

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
     vector<int>ans; 
    bool fans=solve1(root,x,ans);   
    reverse(ans.begin(),ans.end());
    
    return ans;
}
