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
    int countConsistentStrings(string allowed, vector<string>& words) {
		set<char> S;
		FORR(c,allowed) S.insert(c);
		int ret=0;
		FORR(w,words) {
			int ok=0;
			FORR(c,w) ok+=S.count(c);
			if(ok==w.size()) ret++;
		}
        return ret;
    }
};
