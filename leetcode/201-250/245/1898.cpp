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
    int maximumRemovals(string s, string p, vector<int>& removable) {
		int L=0;
		int N=removable.size();
		int i,j;
		for(int i=20;i>=0;i--) if(L+(1<<i)<=N) {
			string T=s;
			FOR(j,(L+(1<<i))) T[removable[j]]='_';
			int x=0;
			FORR(c,T) if(x<p.size() && c==p[x]) x++;
			if(x==p.size()) L+=1<<i;
			
		}
		return L;
    }
};
