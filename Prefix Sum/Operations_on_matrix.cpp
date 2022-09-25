https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

vector<vector<int>> solveQueries(int n, vector<vector<int>> queries) {
        // Code here
        vector<vector<int>>tmp(n,vector<int>(n+1,0));
        
        
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0],b=queries[i][1];
            int c=queries[i][2],d=queries[i][3];
            
            
            for(int j=a;j<=c;j++){
                tmp[j][b]+=1;
                tmp[j][d+1]-=1;
            }
            
        }
        
        
        vector<vector<int>>fans(n,vector<int>(n,0));
        int curr=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                curr+=tmp[i][j];
                if(j<n){
                    fans[i][j]=curr;
                }
            }
        }
        return fans;
    }
