typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int vis[50505];

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        ZERO(vis);
        queue<int> Q;
        Q.push(start);
        vis[start]=1;
        while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			if(arr[cur]==0) return 1;
			if(cur+arr[cur]<arr.size() && vis[cur+arr[cur]]==0) {
				vis[cur+arr[cur]]=1;
				Q.push(cur+arr[cur]);
			}
			if(cur-arr[cur]>=0 && vis[cur-arr[cur]]==0) {
				vis[cur-arr[cur]]=1;
				Q.push(cur-arr[cur]);
			}
		}
		return false;
    }
};


