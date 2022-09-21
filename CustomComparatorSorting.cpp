const bool comp(const vector<int>& v1, const vector<int>& v2){
    int x1=-v1[0];
    int x2=-v1[0]+v1[1]-v2[0];
    int y1=-v2[0];
    int y2=-v2[0]+v2[1]-v1[0];
    if(min(x1,x2)<min(y1,y2)){
        return true;
    }
    if(min(y1,y2)<min(x1,x2)){
        return false;
    }
    return v1[0]>v2[0];
}
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(),transactions.end(),comp);
        long long running=0;
        long long ans=0;
        for(int i=0;i<transactions.size();i++){
            running=running-transactions[i][0];
            ans=min(ans,running);
            running=running+transactions[i][1];
        }
        return -ans;
    }
};
