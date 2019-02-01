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

ll cnt[1<<16];

class Solution {
public:
    int countTriplets(vector<int>& A) {
		ZERO(cnt);
		int i,j;
		FORR(a,A) FORR(b,A) cnt[a&b]++;
		ll ret=0;
		FORR(a,A) FOR(i,1<<16) if((a&i)==0) ret+=cnt[i];
		return ret;
    }
};
