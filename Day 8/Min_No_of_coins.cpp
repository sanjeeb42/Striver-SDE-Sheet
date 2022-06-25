int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>coins={1000,500,100,50,20,10,5,2,1};
    int coins_cnt=0;
    for(int i=0;i<coins.size();i++){
        int tmp=amount/coins[i];
        coins_cnt+=tmp;
        amount=amount-tmp*coins[i];
    }
    
    return coins_cnt;
}
