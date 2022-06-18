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


//Aliter using map, Horizontal distance and verticak distance

void inorder(BinaryTreeNode<int> * root,int hd,map<int,pair<int,int>>&mp,int height)
{
    
    if(root==NULL)return;
    inorder(root->left,hd-1,mp,height+1); 
    int curr_height=mp[hd].second;
    if(height>=curr_height){
        mp[hd]=make_pair(root->data,height);
    }
    
    inorder(root->right,hd+1,mp,height+1); 
   
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.     
    //Play game of Horizontal distances
    //Lmao To store Node and then the hd and the height in the node
    map<int,pair<int,int>>mp;
    inorder(root,0,mp,0);
    vector<int>ans;    
    for(auto it:mp){
        ans.push_back(it.second.first);
    }
    return ans;

}
