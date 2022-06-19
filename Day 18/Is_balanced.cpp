//My accepted Solution

int isTree(BinaryTreeNode<int>*root,bool &ans){
    if(root==NULL){
        return 0;
    }
   // if(root->left==NULL or root->right==NULL){return 1;}
    int left=isTree(root->left,ans);
    int right=isTree(root->right,ans);
    if(abs(left-right)>1){
        ans=false;
    }
    return 1+max(left,right);
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool ans=true;
    int ans1=isTree(root, ans);
    return ans;
}

//Slight optimisation;



int isTree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int left=isTree(root->left);
    if(left==-1)return -1;
    int right=isTree(root->right);
    if(right==-1)return -1;
    if(abs(left-right)>1)
    {
        return -1;
    }
   else return 1+max(left,right);
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool ans=true;
    int ans1=isTree(root);
    if(ans1==-1) ans=false;
    return ans;
}
