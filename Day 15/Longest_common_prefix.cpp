#include <bits/stdc++.h>

string divide(vector<string> &s, int low, int high)
{
    if (low == high) return s[low];
    if (low > high) return "";
    int mid = low + (high - low) / 2;

    string left = divide(s, low, mid);
    string right = divide(s, mid + 1, high);

    string ans = "";

    int l1 = left.length();
    int l2 = right.length();

    int cnt = 0;
    while (cnt < min(l1, l2))
    {
        if (left[cnt] == right[cnt])
        {

            ans += left[cnt];
            cnt++;
        }
        else break;
    }

    return ans;
}

string longestCommonPrefix(vector<string> &s, int n)
{
    int low = 0, high = s.size() - 1;
    string ans = divide(s, low, high);
    return ans;
}
