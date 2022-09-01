class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class cmp{
    public: 
    bool operator()(Node* a,Node *b){
        return a->data>b->data;
    }
};


class Solution
{
    
	public:
	
	    void traverse(Node *root,vector<string>&ans,string curr){
	        if(root->left==NULL && root->right==NULL)
	        {
	            ans.push_back(curr);
	            return;
	        }
	        
	       traverse(root->left,ans,curr+'0');
	       traverse(root->right,ans,curr+'1');
	    }
	    
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,cmp>pq;
		    
		    for(int i=0;i<f.size();i++)
		    {
		        Node *tmp=new Node(f[i]);
		        pq.push(tmp);
		    }
		    
		    //Now time to build the tree
		    
		    while(pq.size()>1)
		    {
		        
		        Node* l=pq.top();pq.pop();
		        Node* r=pq.top();pq.pop();

		        Node * tmp=new Node(l->data+r->data);
		        
		        tmp->left=l;
		        tmp->right=r;
		        pq.push(tmp);
		        
		    }
		    
		    Node* root=pq.top();
		    vector<string>ans;
		    string curr="";
		    traverse(root,ans,curr);
		    
		    return ans;  
		    
		}
};
