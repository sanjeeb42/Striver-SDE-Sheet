vector <int> preorder(Node* root)
{
    // Write your code here.
    
     vector<int>ans;
     bool print=true;
        
        Node *curr=root;
        while(curr!=NULL)
        {
            
            // if(print)ans.push_back(curr->data);
            int val=curr->data;
            print=true;
            if(curr->left==NULL)
            {
               curr=curr->right; 
            }
            
            // if(curr->left==NULL)
            // {
            //     // We can print it as L root R and Left is NULL
            //     ans.push_back(curr->data);
            //     curr=curr->right;
            // }
            
            //If curr ka left exists
            else{
                //Find the last Node that will be visited before visited root
                //The last Node will be rightmost node of the leftsubtree
            
                Node *temp=curr->left;
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
                    // ans.push_back(curr->data);
                    print=false;
                    curr=curr->right;
                    
                }
                
            }
            
            if(print)ans.push_back(val);
            
            
        }
        return ans;
    }   
