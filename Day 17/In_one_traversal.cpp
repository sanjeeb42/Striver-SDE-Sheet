// Case 1 : When num==1
// This means that we are visiting the node for the very first time, therefore we push the node value to our preorder list. Then we push the same node with num=2(for Case 2). After this, we want to visit the left child. Therefore we make a new pair Y(<val, num>) and push it to the stack (if there exists a left child). The val of Y is equal to the left child’s node value and num is equal to 1.

// Case 2 : When num==2
// This means that we are visiting the node for the second time, therefore on our second visit to the node, we push the node value to our inorder list. Then we push the same node with num=3( for Case 3). After this, we want to visit the right child. Therefore as in the first case, we check if there exists a right child or not. If there is, we push the right child and num value=1 as a pair to our stack.

// Case 3 When num==3
// This means that we are visiting the node for the third time. Therefore we will push that node’s value to our postorder list. Next, we simply want to return to the parent so we will not push anything else to the stack.


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    if(root==NULL) return {};
    stack<pair<BinaryTreeNode<int>*,int>>st;
    st.push({root,1});
    
    vector<int>preorder, inorder,postorder;
    while(st.size()>0){
        auto front=st.top();
        st.pop();
        if(front.second==1){
            preorder.push_back(front.first->data);
            st.push({front.first,front.second+1});
            if(front.first->left!=NULL){
                st.push({front.first->left,1});
            }
        }
        
        
        else if(front.second==2){
            inorder.push_back(front.first->data);
            st.push({front.first,front.second+1});
            if(front.first->right!=NULL){
                st.push({front.first->right,1});
            }
        }
        
        else if(front.second==3){
            postorder.push_back(front.first->data);
            
        }
    }
    
    return {inorder,preorder,postorder};
}
