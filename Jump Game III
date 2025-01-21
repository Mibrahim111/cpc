//LeetCode Medium


#include<vector>
#include <queue>
using std::vector;
using std::queue;

class Solution {
    bool hasZero(int idx,queue<int>&q, vector<int>& arr, vector<bool>& vis) {
        if (idx<0 || idx>arr.size() || vis[idx])
            return 0;

        if (arr[idx] == 0)
            return 1;

        else {
            q.push(idx);
            vis[idx] = 1;
            return 0;
        }

    }

public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
            return 1;

        queue<int> q;
        vector<bool> vis(arr.size());
        q.push(start);
        vis[start] = 1;

        for (int level = 0, sz = 1; !q.empty(); sz = (int)q.size(), level++) {
            while (sz--) {
                int current = q.front();
                q.pop();

                if (this->hasZero(current - arr[current], q, arr, vis) || this->hasZero(current + arr[current], q, arr, vis)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};
