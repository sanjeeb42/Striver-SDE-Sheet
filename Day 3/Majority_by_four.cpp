void majorityElementIV(vector<int> &arr)
{
    vector<int> ans;
    int first_candidate = 0, second_candidate = 0, third_candidate = 0;
    int first_count = 0, second_count = 0, third_count = 0;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first_candidate)
            first_count++;
        else if (arr[i] == second_candidate)
            second_count++;
        else if (arr[i] == third_candidate)
            third_count++;

        else if (first_count == 0)
        {
            first_candidate = arr[i];
            first_count++;
        }
        else if (second_count == 0)
        {
            second_candidate = arr[i];
            second_count++;
        }
        else if (third_count == 0)
        {
            third_candidate = arr[i];
            third_count++;
        }
        else
        {
            first_count--;
            second_count--;
            third_count--;
        }
    }

    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first_candidate)
        {
            count1++;
        }
        if (arr[i] == second_candidate)
            count2++;
        if (arr[i] == third_candidate)
            count3++;
    }
    if (count1 > n / 3)
    {
        ans.push_back(first_candidate);
    }
    if (count2 > n / 3)
    {
        ans.push_back(second_candidate);
    }
    if (count3 > n / 3)
    {
        ans.push_back(third_candidate);
    }

    for (auto it : ans)
    {
        cout << it << endl;
    }
}
