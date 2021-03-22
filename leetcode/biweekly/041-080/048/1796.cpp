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
    int secondHighest(string s) {
		set<int> S;
		FORR(c,s) if(c>='0'&&c<='9') S.insert(c-'0');
		
		if(S.size()>1) {
			S.erase(*S.rbegin());
			return *S.rbegin();
		}
		return -1;
        
    }
};

