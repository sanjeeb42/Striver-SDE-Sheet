void findLeftview(TreeNode<int>*root,int curr_level,int &max_level,vector<int>&ans)
{
    if(root==NULL)return;
    if(curr_level>max_level){
        ans.push_back(root->data);
        max_level=curr_level;
    }
    
    findLeftview(root->left,curr_level+1,max_level,ans);
    findLeftview(root->right,curr_level+1,max_level,ans);
 
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>ans;
    int maxlevel=-1;
    findLeftview(root,0,maxlevel,ans);
    return ans;
}
