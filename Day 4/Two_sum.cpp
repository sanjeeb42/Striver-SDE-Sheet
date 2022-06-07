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
