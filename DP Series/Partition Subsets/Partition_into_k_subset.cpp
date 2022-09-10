#include<bits/stdc++.h>
using namespace std;

int cnt;
void solve(vector<int>& arr, int non_empty, int n, int k, int index, vector<vector<int>>list)
{

  if (index == n) 
  {

    //Check if it is an valid partition
    if (non_empty == k) {
      //YES Valid Partition- Let's Print it
      cout<<cnt<<". ";
      for(int i=0;i<k;i++){
          int s=list[i].size();
          cout<<"[";
          for(int j=0;j<s;j++){
              cout<<list[i][j];
              if(j!=s-1){
                  cout<<", ";
              }
          }
          cout<<"] ";
      }
      cout<<endl;
      cnt++;
    }
    return;
  }
  
  
  //Now Try to Put it into Subsets
  for(int i=0;i<k;i++){
      if(list[i].size()>0){
          list[i].push_back(arr[index]);
          solve(arr,non_empty,n,k,index+1,list);
          list[i].pop_back();
      }
      else if(list[i].size()==0){
          list[i].push_back(arr[index]);
          solve(arr,non_empty+1,n,k,index+1,list);
          list[i].pop_back();
          break;
          
      }
  }
  

}

int main() {
  int n, k;
  cin >> n >> k;
  cnt=1;
  vector<int>arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  vector<vector<int>>list(k);
  solve(arr, 0, n, k,0, list);

}
