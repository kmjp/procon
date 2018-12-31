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
	vector<int> ret;
	int K;
	void dfs(int cur,int pre,int lef) {
		if(lef==0) {
			ret.push_back(cur);
		}
		else {
			cur*=10;
			for(int i=0;i<=9;i++) if(abs(i-pre)==K) dfs(cur+i,i,lef-1);
		}
	}
    vector<int> numsSameConsecDiff(int N, int K) {
        ret.clear();
        this->K=K;
        for(int i=1;i<=9;i++) {
			dfs(i,i,N-1);
		}
		if(N==1) ret.push_back(0);
		return ret;
    }
};
