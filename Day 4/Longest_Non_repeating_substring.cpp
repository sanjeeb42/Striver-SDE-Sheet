int uniqueSubstrings(string input)
{
    //Write your code here
    
    int n = input.length();
    int ans = 0;
    int left = 0, right = 0;
    // Map to store the index of occurence of last appearance
    unordered_map<char, int> mp;
    // Set to find if the element is repeating or not
    while (right < n)
    {
        // It is not Present
        if (mp.find(input[right]) == mp.end())
        {
            // Do nothing+           
        }
        else
        {
            // It is present and in range of (left-right)
            if (mp[input[right]] >= left)
            {
                left = mp[input[right]] + 1;
            }
            // It is present but not in range of left-right
        }
        mp[input[right]] = right;

        ans = max(ans, right - left+1);
        right++;
    }
    
    return ans;
}
