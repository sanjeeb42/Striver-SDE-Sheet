 vector<int> ans;
    
        for (int times = 1; times <= n; times++)
        {
            int t = times;
            int low = 0, high = times - 1;
            while (t--)
            {
                ans.push_back(arr[low++][high--]);
            }
        }
        for (int times = n-1; times > 0; times--)
        {
            int t = times;
            int high = n - 1, low =n-times;
            while (t--)
            {
                ans.push_back(arr[low++][high--]);
            }
        }
    return ans;
