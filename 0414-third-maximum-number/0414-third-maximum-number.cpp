class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());
        sort(v.rbegin(),v.rend());
        int n=v.size();
        int count=1;
        for(int i=1;i<v.size();i++){
            if(v[i-1]!=v[i]){
                count++;
                if(count==3){
                    return v[i];
                }
            }
        }
        return v[0];
    }
};