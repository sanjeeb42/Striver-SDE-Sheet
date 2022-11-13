https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/


class Solution {
public:
    
    int minSwaps(vector<int>&nums, int n)
{
     //   cout<<"Entred"<<endl;
    int len = n;
    map<int, int> map;
    for (int i = 0; i < len; i++)
        map[nums[i]] = i;
 
    sort(nums.begin(), nums.end());
 
    
    // bool visited[len] = { 0 };
        vector<bool>visited(n,0);
 
    
    int ans = 0;
    for (int i = 0; i < len; i++) {
 
        // already swapped and corrected or
        // already present at correct pos
        if (visited[i] || map[nums[i]] == i)
            continue;
 
        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;
 
            // move to next node
            j = map[nums[j]];
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
      //  cout<<ans<<endl;
    return ans;
}
    
    
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*>q;
        if(root==NULL)return 0;
        q.push(root);
        int ans=0;
        
        while(q.size()>0)
        {
            int n=q.size();
            vector<int>tmp;
            
            for(int i=0;i<n;i++){
                auto top=q.front();
                q.pop();
                if(top->left){
                    q.push(top->left);
                    tmp.push_back(top->left->val);
                }
                if(top->right){
                    q.push(top->right);
                    tmp.push_back(top->right->val);
                }
            }
            
            //Now time to sort the array
            ans+=minSwaps(tmp,tmp.size());
            
        }
        return ans;
        
    }
};
