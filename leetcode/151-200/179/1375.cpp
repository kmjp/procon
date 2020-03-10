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
    int numTimesAllBlue(vector<int>& light) {
		set<int> S;
		int N=light.size();
		int i;
		for(i=1;i<=N+1;i++) S.insert(i);
		int ret=0;
		int cnt=0;
		FORR(l,light) {
			S.erase(l);
			cnt++;
			if(*S.begin()>cnt) ret++;
		}
        return ret;
    }
};
