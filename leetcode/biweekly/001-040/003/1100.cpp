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
    int numKLenSubstrNoRepeats(string S, int K) {
		int ret=0;
		int i,j;
		FOR(i,S.size()) {
			int cnt[26]={};
			for(j=i;j<min(i+K,(int)S.size());j++) {
				if(cnt[S[j]-'a']) break;
				cnt[S[j]-'a']++;
			}
			if(j==i+K) ret++;
		}
        return ret;
    }
};

