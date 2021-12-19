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


vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	if(v.empty()) return {};
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //‚±‚¤‚·‚é‚Æ“¯‚¶’l‚à‹–—e‚·‚é
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
		int num=0;
		int i,j;
		FOR(i,k) {
			vector<int> V;
			for(j=i;j<arr.size();j+=k) {
				V.push_back(arr[j]);
			}
			num+=V.size()-LIS(V).size();
		}
		return num;
        
    }
};
