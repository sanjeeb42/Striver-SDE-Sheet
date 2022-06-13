    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
       if((p==NULL and q!=NULL) or(q==NULL and p!=NULL)){
            return false;
        }
        if(p==NULL and q==NULL){
            return true;
        }
        if(p->val!=q->val){
            return false;
        }
        
        return isSameTree(p->left,q->left)and isSameTree(p->right,q->right);
        
    }
