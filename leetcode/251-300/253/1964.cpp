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


class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
		int i,N=v.size();
		vector<int> dp(N,1<<30),id(N);
		FOR(i,v.size()) {
			id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //こうすると同じ値も許容する
			dp[id[i]] = v[i];
			id[i]++;
		}
		return id;
    }
};
