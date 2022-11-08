https://leetcode.com/problems/largest-time-for-given-digits/submissions/

class Solution
{
    public:
        string largestTimeFromDigits(vector<int> &arr)
        {
            sort(arr.begin(), arr.end());
            int ans = -1;
            do {
                int hour = arr[0] *10 + arr[1];
                int min = arr[2] *10 + arr[3];

                if (hour < 24 && min < 60)
                {
                    ans = max(ans, hour *60 + min);
                }
            } while (next_permutation(arr.begin(), arr.end()));

            if (ans == -1) return "";
            cout << ans << endl;
            int hours = ans / 60, minutes = ans % 60;
            int firstdigit = hours / 10, seconddigit = hours % 10, thirddigit = minutes / 10, fourthdigit = minutes % 10;
            string fans = to_string(firstdigit) + to_string(seconddigit) + ":" + to_string(thirddigit) + to_string(fourthdigit);

            return fans;
        }
};
