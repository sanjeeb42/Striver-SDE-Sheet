vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    
    if(root==NULL){
        return {};
    }
    map<int,int>mp;
    queue<pair<TreeNode<int>*,int>>q;
 //  Topview(root,mp,0);
   vector<int>ans;
    q.push({root,0});
    while(q.size()>0)
    {
        auto tmp=q.front();
        q.pop();
        TreeNode<int>*node=tmp.first;
        int distance=tmp.second;
        
       if(mp.find(distance)==mp.end())
       {
          mp[distance]=node->val;
        }
        
        if(node->left){
            q.push({node->left,distance-1});
        }
        
         if(node->right){
            q.push({node->right,distance+1});
        }
        
    }
    
    for(auto it: mp){
      ans.push_back(it.second);
    }
    
    return ans;
}
