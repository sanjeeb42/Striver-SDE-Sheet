//https://leetcode.com/problems/longest-repeating-character-replacement/

#include<bits/stdc++.h>
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0;
        int ans = 0;
        int n = s.length();
        int result = 0;
        for(int end = 0; end < n; end++){
            counts[s[end]-'A']++;
            if(ans < counts[s[end]-'A']){
                ans = counts[s[end]-'A'];
            }
            while(end-start-ans+1 > k){
                counts[s[start]-'A']--;
                start++;
                for(int i = 0; i < 26; i++){
                    if(ans < counts[i]){
                        ans = counts[i];
                    }
                }
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};
