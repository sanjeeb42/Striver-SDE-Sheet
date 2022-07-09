vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int,vector<int>>mp;
    queue<pair<TreeNode<int>*,int>>q;
    
    if(root==NULL) return {};   
    q.push({root,0});   
    while(q.size()>0)
    {
        TreeNode<int>* node=q.front().first;
        int hd=q.front().second;
        q.pop();
        
        mp[hd].push_back(node->data);
        if(node->left){
            q.push({node->left,hd-1});
        }
        
        if(node->right){
            q.push({node->right,hd+1});
        }
        
    }   
    vector<int>ans;
    for(auto it: mp){
        for(auto pq:it.second){
            ans.push_back(pq);
        }
    }
    
    return ans;
}
