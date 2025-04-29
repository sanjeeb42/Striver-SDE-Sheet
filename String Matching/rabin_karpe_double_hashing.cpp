typedef long long ll;

class Solution {
public:
    const int base1 = 911;
    const int base2 = 3571;
    const int mod1 = 1e9 + 7;
    const int mod2 = 1e9 + 9;

    int rabinKarpDoubleHashing(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();

        ll h1 = 1, h2 = 1;

        for (int i = m - 2; i >= 0; i--) {
            h1 = (h1 * base1) % mod1;
            h2 = (h2 * base2) % mod2;
        }

        ll ph1 = 0, ph2 = 0; 
        ll th1 = 0, th2 = 0; 

        for (int i = 0; i < m; i++) {
            ph1 = (ph1 * base1 + pattern[i]) % mod1;
            ph2 = (ph2 * base2 + pattern[i]) % mod2;

            th1 = (th1 * base1 + text[i]) % mod1;
            th2 = (th2 * base2 + text[i]) % mod2;
        }

        for (int i = 0; i <= n - m; i++) {
            if (ph1 == th1 && ph2 == th2) {
                return i;
            }

            if (i < n - m) {
                th1 =
                    (base1 * (th1 - text[i] * h1 % mod1 + mod1) + text[i + m]) %
                    mod1;
                th2 =
                    (base2 * (th2 - text[i] * h2 % mod2 + mod2) + text[i + m]) %
                    mod2;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        return rabinKarpDoubleHashing(haystack,needle);
    }
};
