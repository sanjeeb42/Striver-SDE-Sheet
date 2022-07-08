//chill maro ..itna tough bhi nhi hai
//refernce -Love babbar lec 68
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    
     vector<int>ans;
        
        TreeNode *curr=root;
        while(curr!=NULL)
        {
            
            if(curr->left==NULL)
            {
                // We can print it as L root R and Left is NULL
                ans.push_back(curr->data);
                curr=curr->right;
            }
            
            //If curr ka left exists
            else{
                //Find the last Node that will be visited before visited root
                //The last Node will be rightmost node of the leftsubtree
                TreeNode *temp=curr->left;
                while(temp->right!=NULL and temp->right!=curr){
                    temp=temp->right;
                }
                
                //Create a link of the rightnmost node of left subtree with root
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                
                //Delete link if it exists and print it as all leftsubtree visisted
                else if(temp->right==curr)
                {
                    temp->right==NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
                
            }
        }
        
        return ans;
}
