void find_parent_plus_leaf(Node* root,Node*parent,unordered_map<Node*,Node*>&mp,vector<Node*>&leaf){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        leaf.push_back(root);
    }
    
    mp[root]=parent;
    
    if(root->left!=NULL){
        find_parent_plus_leaf(root->left,root,mp,leaf);
    }
    
    if(root->right!=NULL){
        find_parent_plus_leaf(root->right,root,mp,leaf);
    }
    
    
}
int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here.
	
	
	//Step 1: Find {arent Mapping 
	//Step 2: Find Leaf Node
	//Step 3: Traverse k distance up using parent & if node exist push into set
	//Step 4: Ans= set.size()
	
	unordered_map<Node*,Node*>mp;
	vector<Node*>leaf;
	find_parent_plus_leaf(root,NULL,mp,leaf);
	
	int n=leaf.size();
	
	unordered_set<Node*>ans;
	
	for(int i=0;i<n;i++){
	    
	    auto it=leaf[i];
	    int times=k;
	    while(times-- && it){
	        it=mp[it];
	    }
	    
	    if(it!=NULL){
	        ans.insert(it);
	    }
	    
	}
	
	return ans.size();
}
