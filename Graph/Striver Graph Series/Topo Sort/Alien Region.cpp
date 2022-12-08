//https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

class Solution{
    public:
    string findOrder(string dict[], int n, int K) {
        //code here
        
        //Declare the Directed Graph
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(K,0);
       
        for(int i=1;i<n;i++)
        {
            string a=dict[i-1],b=dict[i];
            for(int j=0;j<min(a.length(),b.length());j++){
                if(a[j]!=b[j]){
                    // cout<<a[j]<<" and "<<b[j]<<endl;
                    int u=a[j]-'a',v=b[j]-'a';
                    mp[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }
        
        
        // for(int i=0;i<mp.size();i++){
        //     cout<<i<<" -> ";
        //     for(auto it:mp[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //Now do toposort
        
        queue<int>q;
       // vector<int>topo;
        for(int i=0;i<K;i++){
            if(indegree[i]==0)q.push(i);
        }
        string ans="";
        while(q.size()>0){
            auto front=q.front();
            q.pop();
            
           // topo.push_back(front);
            ans+=('a'+front);
            for(auto it: mp[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        //Now we have the toposort done
        // for(auto it: topo)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
       
        
        
        return ans;
        
    }
};
