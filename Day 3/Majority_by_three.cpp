// naive approach -There is an efficinet approach Moore Voting algorithm

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
vector<int>ele;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int i=0;
    while(i<n)
    {
        int curr=arr[i], cnt=0; 
        bool insert=false;
        while(arr[i]==curr)
        {
            cnt++;
            i++;
            if(cnt>n/3)
            {
                if(!insert)
                {
                    
                    ele.push_back(curr);
                    insert=true;
                }
            }
        }
    }
    
return ele;
}



// Efficient Approach

The idea is to use a modification of Moore's voting algorithm to find candidate elements that may occur more than N/3 times in the given array. We will use the fact that if we remove 3 distinct elements from the array, the elements which occurred more than N/3 times do not change.

 

The steps are as follows:

We can prove using the pigeonhole principle that there are at most 2 elements possible that can occur more than N/3 times, we will use the variable ‘FIRST_CANDIDATE’ to store the first element that can possibly occur more than ‘N’/3 times and another variable ‘SECOND_CANDIDATE’ to store the second element that can possibly occur more than N/3 times. Also, we will use the variables ‘FIRST_COUNT’ and ‘SECOND_COUNT’, both of which will be initialized to 0, to store the frequency of the ‘FIRST_CANDIDATE’ and ‘SECOND_COUNT’ respectively.
Iterate through the array, let’s say our current element is ‘ARR[i]’.
If ‘ARR[i]’ is equal to ‘FIRST_CANDIDATE’ then increment ‘FIRST_COUNT’ by 1
If ‘ARR[i]’ is equal to ‘SECOND_CANDIDATE’ then increment ‘SECOND_COUNT’ by 1.
Otherwise, if ‘FIRST_COUNT’ is equal to 0, set ‘FIRST_CANDIDATE’ equal to ‘ARR[i]’ and increment ‘FIRST_COUNT’ by 1.
Else if ‘SECOND_COUNT’ is equal to 0, set ‘SECOND_CANDIDATE’ equal to ‘ARR[i]’ and increment ‘SECOND_COUNT’ by 1.
Else decrement both ‘FIRST_COUNT’ and ‘SECOND_COUNT’ by 1. By doing this, we are basically removing 3 distinct elements from our array which will not affect the answer.
Iterate through the array once again and count the number of occurrences of ‘FIRST_CANDIDATE’ and ‘SECOND_CANDIDATE’.
Store ‘FIRST_CANDIDATE’ in the answer if it occurs more than ‘N’/3 times in the given array/list, similarly add ‘SECOND_CANDIDATE’ to the answer if it occurs more than ‘N’/3 times in the given array/list.
Return the stored elements.
  
  
  /*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the number of elements in the given array/list
*/

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();

    // Array for storing final answer.
    vector<int> majorityElement;

    // Variables for storing the elements which may occur more than n/3 times.
    int firstCandidate = 0, secondCandidate = 0;

    // Variables for storing the frequency of the candidate elements.
    int firstCount = 0, secondCount = 0;

    // Iterate through the array.
    for (int i = 0; i < n; i++)
    {
        // Increment firstCount if the current element is equal to firstCandidate.
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        // Increment secondCount if the current element is equal to secondCandidate.
        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
        // Change value of the firstCandidate to the current element if firstCount is equal to 0.
        else if (firstCount == 0)
        {
            firstCandidate = arr[i];
            firstCount = 1;
        }

        // Change value of the secondCandidate to the current element if secondCount is equal to 0.
        else if (secondCount == 0)
        {
            secondCandidate = arr[i];
            secondCount = 1;
        }

        // Otherwise decrement firstCount and secondCount by 1.
        else
        {
            firstCount = firstCount - 1;
            secondCount = secondCount - 1;
        }
    }

    firstCount = 0;
    secondCount = 0;

    // Iterate through the array to find frequency of firstCandidate and secondCandidate.
    for (int i = 0; i < n; i++)
    {
        // Increment firstCount if the current element is equal to firstCandidate.
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        // Increment secondCount if the current element is equal to secondCandidate.
        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
    }

    // Include firstCandidate in the answer if its frequency is more than n/3.
    if (firstCount > n / 3)
    {
        majorityElement.push_back(firstCandidate);
    }

    // Include secondCandidate in the answer if its frequency is more than n/3.
    if (secondCount > n / 3)
    {
        majorityElement.push_back(secondCandidate);
    }

    // Return all stored majority elements.
    return majorityElement;
}
