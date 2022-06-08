//Two Pointer approach works well
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    int low = 0, high = n - 1;
    while (low < high)
    {
        int curr = arr[low] + arr[high];
        if (curr > s)
        {
            high--;
        }
        else if (curr < s)
        {
            low++;
        }
        else
        {
            int isequal = arr[low] == arr[high];
          //  cout << "Isequal : " << isequal << endl;
            int low_val = arr[low], high_val = arr[high];
            int count_low = 0, count_high = 0;
            for (int i = low; i < n; i++)
            {
                if (arr[i] == low_val)
                {
                    // cout << "arr[i]: " << arr[i] << " and i : " << i << endl;
                    count_low++;
                    low++;
                }
                else
                    break;
            }

            for (int i = high; i > 0; i--)
            {
                if (arr[i] == high_val)
                {
                    //  cout << "arr[i]: " << arr[i] << " and i : " << i << endl;
                    count_high++;
                    high--;
                }
                else
                    break;
            }
            int total_count = count_low * count_high;
            if (isequal)
            {
                total_count = ((count_high) * (count_high - 1)) / 2;
            }

          //  cout << count_low << " and " << count_high << endl;

            for (int i = 0; i < total_count; i++)
            {
                vector<int> temp;
                temp.push_back(low_val);
                temp.push_back(high_val);
                ans.push_back(temp);
            }
        }
    }
    return ans; 
    
}







bool binarysearch(vector<int> arr, int i, int target, int n)
{
    int low = i + 1, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}


vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        mp[arr[i]]--;
        if (binarysearch(arr, i, s - arr[i], n))
        {
            int count = mp[s - arr[i]];
            while (count--)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(s - arr[i]);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
