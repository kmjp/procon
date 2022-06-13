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
	int ret;
	void dfs(vector<int>& V,int cur,vector<int>& C) {
		if(cur==C.size()) {
			int ma=*max_element(ALL(V));
			ret=min(ret,ma);
			return;
		}
		int i;
		FOR(i,V.size()) {
			V[i]+=C[cur];
			dfs(V,cur+1,C);
			V[i]-=C[cur];
		}
	}
    int distributeCookies(vector<int>& cookies, int k) {
		ret=1LL<<30;
		vector<int> V(k);
		dfs(V,0,cookies);
		
		return ret;
		
        
    }
};
