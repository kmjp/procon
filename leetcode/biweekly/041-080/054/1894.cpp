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
    int chalkReplacer(vector<int>& chalk, int k) {
		ll S=0;
		FORR(c,chalk) S+=c;
		k%=S;
		int i;
		FOR(i,chalk.size()) {
			if(k<chalk[i]) return i;
			k-=chalk[i];
		}
		return 0;
    }
};
