void inorder_t(BinaryTreeNode<int> *root,vector<int>&inorder){
    if(root==NULL)return;
    inorder_t(root->left,inorder);
    inorder.push_back(root->data);
    inorder_t(root->right,inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here.
    vector<int>inorder;
    inorder_t(root,inorder);
    
    int low=0, high=inorder.size()-1;
    while(low<high){
        int tmp_ans=inorder[low]+inorder[high];
        if(tmp_ans==k){
            return true;
        }
        else if(tmp_ans>k){
            high--;
        }
        else low++;
    }
return false;
    
}
