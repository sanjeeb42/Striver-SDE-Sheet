https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1



int primesum[10005]={0};
    bool entered=false;
    
    
    void generate()
    {
        entered=true;
        // cout<<primesum[100]<<endl;
        vector<bool>isPrime(10005,true);
        
        for(int i=2;i*i<=10000;i++){
            if(isPrime[i]==true)
            {
                for(int j=2;j*i<=10000;j++){
                    isPrime[j*i]=false;
                }
            }
        }
        
        primesum[1]=1;
        
        for(int i=2;i<=1e4;i++)
        {
            int cnt=0;
            if(isPrime[i]){
                primesum[i]=primesum[i-1]+i;
                continue;
            }
            for(int j=2;j<=i;j++)
            {
                if(isPrime[j] && i%j==0)
                {
                    cnt+=j;
                }
            }
            primesum[i]=primesum[i-1]+cnt;
        }
    }


class Solution {
  public:
   
  
    int sumOfAll(int l, int r){
        // code here
        //Generate all the prime factors of a anumber
        
        if(entered==false)
        {
            generate();
        }

        int ans=primesum[r]-primesum[l-1];
        return ans;
    }
    
    
 //Aliter Solution

void primeFactor(int n, unordered_map<int, int>& ans, vector<int> &storeFactors)
{
    if (n == 1) 
        storeFactors.push_back(n);
    
    else
    {
        // algo to find all prime factors of n
        int c = 2;
        while (n > 1)
        {
            if (n % c == 0)
            {
                if (ans[c] < 1) // for storing non repeating prime factors
                    ans[c]++;
                n /= c;
            }
            else
                c++;
        }
    
        for (auto i : ans)
            storeFactors.push_back(i.first);
    }      
}
int sumOfAll(int l, int r){
    // code here
    int sum = 0;
    vector<int> factors;
    for (int i = l; i <= r; i++)
    {
        unordered_map<int, int> list;
        primeFactor(i, list, factors);
    }
        
    for (int i : factors)
        sum += i;
         
    return sum;
}
