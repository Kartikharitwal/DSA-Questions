class Solution {
public:
    const int mod=1e9+7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size()+1;
        vector<pair<int,int>>dp[n+1];
        for(auto &conversion:conversions) dp[conversion[0]].push_back({conversion[1],conversion[2]});
        vector<int>ans(n,0);
        ans[0]=1;
        queue<int>q;
        q.push(0);
        while(q.size()){
            auto u = q.front();
            q.pop();
            long long currentWeight = ans[u]%mod;
            for(auto &[v,w]:dp[u]){
                ans[v]=((currentWeight)*(w%mod))%mod;
                q.push(v);
            }
        }
        return ans;
    }
};