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
    int minimumDeletions(string s) {
		int mi=s.size();
		int NA=0,NB=0;
		FORR(c,s) if(c=='a') NA++;
		mi=NA;
		int i;
		FOR(i,s.size()) {
			if(s[i]=='a') {
				NA--;
			}
			else {
				NB++;
			}
			mi=min(mi,NA+NB);
		}
        return mi;
    }
};
