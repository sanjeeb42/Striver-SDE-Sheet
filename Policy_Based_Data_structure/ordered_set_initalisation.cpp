#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    vector<int> nums = {5, 2, 6, 1}; 
    ordered_set<pair<int, int>> st1;
    st1.insert({nums[0], 0});

    cout << "0th smallest element: " << st1.find_by_order(0)->first << endl;

    for (int i = 2; i < nums.size(); i++) {
        int curr = nums[i];
        int x1 = st1.size() - st1.order_of_key({curr + 1, INT_MIN});
        st1.insert({nums[i], i});
        cout << "Elements greater than " << curr << ": " << x1 << endl;
    }

    return 0;
}
