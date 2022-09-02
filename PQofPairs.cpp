struct myComp {
    bool operator()(pair<string, int> const& a, pair<string, int> const& b)const noexcept
    {
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            priority_queue<pair<string,int>,vector<pair<string,int>>,myComp> pq;
            int k=queries[i][0];
            int trim=queries[i][1];
            for(int j=0;j<nums.size();j++){
                string help=nums[j].substr(nums[j].size()-trim);
                if(pq.size()<k){
                    pair<string,int> p;
                    p.first=help;
                    p.second=j;
                    pq.push(p);
                }else if(help<pq.top().first){
                    pair<string,int> p;
                    p.first=help;
                    p.second=j;
                    pq.push(p);
                    pq.pop();
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};
