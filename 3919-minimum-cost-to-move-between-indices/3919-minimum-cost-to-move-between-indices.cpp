class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                closest[i] = 1;
            } 
            else if (i == n - 1) {
                closest[i] = n - 2;
            } 
            else {
                int left = nums[i] - nums[i - 1];
                int right = nums[i + 1] - nums[i];

                if (left <= right)
                    closest[i] = i - 1;
                else
                    closest[i] = i + 1;
            }
        }
        vector<long long> forward(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (closest[i] == i + 1)
                forward[i + 1] = forward[i] + 1;
            else
                forward[i + 1] = forward[i] + (nums[i + 1] - nums[i]);
        }
        vector<long long> backward(n, 0);
        for (int i = n - 1; i > 0; i--) {
            if (closest[i] == i - 1)
                backward[i - 1] = backward[i] + 1;
            else
                backward[i - 1] = backward[i] + (nums[i] - nums[i - 1]);
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];

            if (l <= r)
                ans.push_back(forward[r] - forward[l]);
            else
                ans.push_back(backward[r] - backward[l]);
        }
        return ans;
    }
};