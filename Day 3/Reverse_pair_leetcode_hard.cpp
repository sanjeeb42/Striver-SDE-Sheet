class Solution
{
    public:

        void merge_funcn(int low, int high, int &ans, vector<int> &arr)
        {
            if (low >= high)
                return;
            int mid = (high + low) / 2;
            int temp[high + 1];
            int i = low, j = mid + 1, k = 0;

            while (i <= mid && j <= high)
            {
                long long tmp = (long long)(2) *arr[j];
                if (arr[i] > tmp)
                {
                    ans += (mid - i + 1);
                    j++;
                }
                else
                {
                    i++;
                }
            }

            i = low, j = mid + 1;

            while (i <= mid && j <= high)
            {
                if (arr[i] > arr[j])
                {
                    temp[low + k] = arr[j];
                    j++;
                    k++;
                }
                else
                {
                    temp[low + k] = arr[i];
                    i++;
                    k++;
                }
            }

            while (i <= mid)
            {
                temp[low + k] = arr[i++];
                k++;
            }

            while (j <= high)
            {
                temp[low + k] = arr[j++];
                k++;
            }

            for (int l = low; l <= high; l++)
            {
                arr[l] = temp[l];
            }

           	//  sort(arr.begin() + low, arr.begin() + high + 1);
        }

    void merge_sort(vector<int> &arr, int low, int high, int &ans)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        merge_sort(arr, low, mid, ans);
        merge_sort(arr, mid + 1, high, ans);
        merge_funcn(low, high, ans, arr);
    }

    int reversePairs(vector<int> &arr)
    {
        int ans = 0, n = arr.size();
        merge_sort(arr, 0, n - 1, ans);
        return ans;
    }
};
