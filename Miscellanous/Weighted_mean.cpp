https://leetcode.com/problems/minimum-cost-to-make-array-equal/submissions/

#define ll long long
class Solution {
public:
   
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //We will ue something as median
        
        int n=nums.size();
        vector<pair<int,int>>mypair;
        for(int i=0;i<n;i++)
        {
                mypair.push_back({nums[i],cost[i]});
        }
        
        sort(mypair.begin(),mypair.end());
        
        ll freq=accumulate(cost.begin(),cost.end(),0*1ll);
        freq=freq/2;
        int medianindex;
        for(medianindex=0;medianindex<n;medianindex++)
        {
            if(freq-mypair[medianindex].second<=0){
                break;
            }
            else freq=freq-mypair[medianindex].second;
        }
        
        long long ans=0;
        for(ll i=0;i<n;i++){
            ll times=abs(mypair[i].first-mypair[medianindex].first);
            ll val=times*mypair[i].second*1ll;
            ans=ans+val;
        }
        
        return ans;
    }
};
