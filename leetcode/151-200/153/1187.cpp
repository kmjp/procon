
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

int ok[4020];
int dp[2020][4020];

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<int> V;
        V.push_back(-1);
        FORR(v,arr1) V.push_back(v);
        FORR(v,arr2) V.push_back(v);
        sort(ALL(V));
        V.erase(unique(ALL(V)),V.end());
        FORR(v,arr1) v=lower_bound(ALL(V),v)-V.begin();
        ZERO(ok);
        FORR(v,arr2) ok[lower_bound(ALL(V),v)-V.begin()]=1;
        int x,y;
        FOR(x,2010) FOR(y,4010) dp[x][y]=1010101;
        dp[0][0]=0;
        FOR(x,arr1.size()) {
			int mi=1010101;
			FOR(y,4010) {
				if(arr1[x]==y) dp[x+1][y]=min(dp[x+1][y],mi);
				if(ok[y]) dp[x+1][y]=min(dp[x+1][y],mi+1);
				mi=min(mi,dp[x][y]);
			}
		}
		
		int ret=101010;
		FOR(y,4010) ret=min(ret,dp[arr1.size()][y]);
		if(ret>101000) ret=-1;
		return ret;
        
    }
};


