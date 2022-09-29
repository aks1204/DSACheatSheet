vector<int> glob;
class cmp {
public:
	bool operator()(int x1, int x2) {
		if(glob[x1]<=glob[x2]){
            return false;
        }
        return true;
	}
};
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        glob=time;
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            vector<int> help;
            adj.push_back(help);
        }
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }
        vector<int> in;
        for(int i=0;i<n;i++){
            in.push_back(0);
        }
        for(int i=0;i<relations.size();i++){
            in[relations[i][1]-1]++;
        }
        priority_queue<int,vector<int>,cmp> q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int src=q.top();
            q.pop();
            for(int i=0;i<adj[src].size();i++){
                in[adj[src][i]]--;
                if(in[adj[src][i]]==0){
                    q.push(adj[src][i]);
                    time[adj[src][i]]=time[adj[src][i]]+time[src];
                }
            }
        }
        for(int i=0;i<time.size();i++){
            ans=max(ans,time[i]);
        }
        return ans;
    }
};
