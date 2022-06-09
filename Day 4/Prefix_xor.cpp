// Here we use the factor that a^b=c then a^c=b


// We need to traverse the array while we maintain variables for current_perfix_xor,
// counter, and also a map to keep track of visited xors. 
// This map will maintain the frequency count of all previous visited current_prefix_xor values.
// If for any index current_prefix_xor is equal to B, we increment the counter. 
// If for any index we find that Z is present in the visited map, we increment the counter by visited[Z] (Z=current_prefi_xor^B).
// At every index, we insert the current_prefix_xor into the visited map with its frequency.


int subarraysXor(vector<int> &arr, int target)
{
    //    Write your code here.
    int n=arr.size();
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] xor arr[i];
    }

    unordered_map<int, int> mp;
    mp[0]=1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xor_val = prefixSum[i] xor target;
        if (mp.find(xor_val) != mp.end())
        {
            count += mp[xor_val];
        }
        mp[prefixSum[i]]++;
    }

    return count;
}
