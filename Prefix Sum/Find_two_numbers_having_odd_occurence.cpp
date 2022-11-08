#define ll long long
class Solution{
    public:
    
    
    int firstsetbit(int n){
        int ans=0;
        while(n>0)
        {
            if(n&1==1)return ans;
            n=n>>1;
            ans++;
        }
        return -1;
    }
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        ll xorval=0;
        for(int i=0;i<n;i++){
            xorval=xorval xor arr[i];
        }
        
        ll ans1=0, ans2=0;
        ll pos=firstsetbit(xorval);
        for(int i=0;i<n;i++){
            if(1<<pos & arr[i]){
                ans1=ans1 xor arr[i];
            }else ans2=ans2 xor arr[i];
        }
        
        
        vector<ll>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        
       if(ans[0]<ans[1])swap(ans[0],ans[1]);
        
        return ans;
    }
};
