https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1

long long jumpingNums(long long X) {
        // code here
        if(X<=10) return X;
        return solve(X);
    }
    
    int solve(int x)
    {
        queue<int> q;
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        int ans = INT_MIN;
        while(!q.empty())
        {
            int curr = q.front();
            ans=max(ans,curr);
            q.pop();
            int last = curr%10;
            int num1 = curr*10 + last + 1;
            int num2 = curr*10 + last - 1;
            if(last==0)
            {
                if(num1<=x) q.push(num1);
            }
            else if(last==9)
            {
                if(num2<=x) q.push(num2);
            }
            
            else{
                if(num2<=x) q.push(num2);
                if(num1<=x) q.push(num1);
            }
        }
        return ans;
    }
