class cmp{
    public:
    bool operator()(pair<double,int>&a,pair<double,int>&b){
        return a.first<b.first;
    }
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        priority_queue<pair<double,int>,vector<pair<double,int>>,cmp>pq;
        for(int i=0;i<n;i++){
            int val=arr[i].value;
            int weight=arr[i].weight;
            
            pq.push({val/(weight*1.0), weight});
        }
        
        
        double ans=0;
        
        while(W>0 && pq.size()>0)
        {
            
            auto front=pq.top();
            pq.pop();
            
            int maxweight=front.second;
            double ratio=front.first;
            
           // cout<<maxweight<<" "<<ratio<<endl;
            
            ans+= (min(W,maxweight)*ratio);
            
            W-=min(W,maxweight);
            
        }
        
        return ans;
    }
        
};
