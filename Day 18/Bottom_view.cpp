vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    
    //Play game of Horizontal distances
    //Lmao
    map<int,int>mp;
   // inorder(root,0,mp);
    vector<int>ans;   
    queue<pair<BinaryTreeNode<int>*, int>>q;
    q.push({root,0});
    while(q.empty()==false)
    {
        int size=q.size();
        for(int i=0;i<size;i++){
            auto node=q.front().first;
            auto hd=q.front().second;
            q.pop();
            mp[hd]=node->data;
            if(node->left)q.push({node->left,hd-1});
            if(node->right)q.push({node->right,hd+1});
        }
    } 
    
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
    
  
}
