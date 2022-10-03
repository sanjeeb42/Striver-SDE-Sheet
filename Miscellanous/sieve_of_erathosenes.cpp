https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1


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
