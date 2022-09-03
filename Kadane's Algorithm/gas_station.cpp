class Solution
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
        {
            int n = gas.size();
            // vector<int>arr(n);
            
            // for(int i=0;i<n;i++){
            //     arr[i]=gas[i]-cost[i];
            // }
            
            int avail=accumulate(gas.begin(),gas.end(),0);
            int reqd=accumulate(cost.begin(),cost.end(),0);
            if(avail-reqd<0)return -1;
            
            int curr_sum=0;
            int s_index=0;
            for(int i=0;i<n;i++){
                if(curr_sum<0){
                    curr_sum=0;
                    s_index=i;
                }
                curr_sum+=gas[i]-cost[i];    
            }
            
            return s_index;
        }
};
