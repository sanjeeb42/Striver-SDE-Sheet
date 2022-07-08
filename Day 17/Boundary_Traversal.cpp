class Solution {
public:

void leftView(Node* root,vector<int>&ans){
    if((root==NULL) or (root->left==NULL && root->right==NULL))return;
    
    ans.push_back(root->data);
    if(root->left)leftView(root->left,ans);
    else
    {
        leftView(root->right,ans);
    }
}
void bottomview(Node *root,vector<int>&ans)
{
    if(root==NULL)return;
    
    if(root->left==NULL and root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    
    bottomview(root->left,ans);
    bottomview(root->right,ans);
}

void rightView(Node* root,vector<int>&ans){
    if((root==NULL)or (root->left==NULL && root->right==NULL))return;
    
    
    if(root->right)rightView(root->right,ans);
    else{
        rightView(root->left,ans);
    }
    
    ans.push_back(root->data);
}

    vector<int>boundary(Node *root)
    {
        //Your code here
        //left View + bottom view + right view
        
        //For a child : root->left=NULL and root->right=NULL
        
        vector<int>ans;
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        
        leftView(root->left,ans);
        bottomview(root->left,ans);
        bottomview(root->right,ans);
        // bottomview(root,ans);// This will not work since if only one node present in tree, It will
        //be printed twice
        
        rightView(root->right,ans);
        
        
        // for(auto it: ans){
        //     cout<<it<<" ";
        // }
        
        // for(auto it: rev){
        //     cout<<it<<" ";
        // }
        
        return ans;
        
    }
};
