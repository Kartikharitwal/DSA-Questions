class Solution {
public:
    bool check1(string temp){
        int n=temp.length();
        int i=1;
        while(i<n ){
            if(temp[i-1]=='1' &&temp[i-1]==temp[i]){
                return false;
            }
            i++;
        }
        return true;
    }
    bool check2(string temp,int k){
        int sum=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='1'){
                sum+=i;
            }
        }
        return sum<=k;
    }
    void helper(vector<string>&ans,string &curr,int i,int n){
        if(i>n){
            return ;
        }
        ans.push_back(curr);
        for(int j=i;j<curr.length();j++){
            curr[j]='1';
            helper(ans,curr,j+1,n);
            curr[j]='0';
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        int i=0;
        vector<string>ans;
        string s(n,'0');
        helper(ans,s,i,n);
        vector<string>result;
        for(int i=0;i<ans.size();i++){
            string temp=ans[i];
            if(check1(temp) && check2(temp,k)){
                result.push_back(temp);
            }
        }
        return result;
    }
};