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
    vector<int> diStringMatch(string S) {
		int N=S.size(),i;
		vector<int> R,R2;
		R.push_back(0);
		FOR(i,N) {
			if(S[i]=='I') R.push_back(i+1);
			else R.push_back(-(i+1));
		}
		R2=R;
		sort(ALL(R2));
		FORR(c,R) c=lower_bound(ALL(R2),c)-R2.begin();
		return R;
        
    }
};
