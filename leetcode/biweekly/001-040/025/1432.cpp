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
    int maxDiff(int num) {
        
        int x1,y1,x2,y2;
        int ret=0;
        set<int> R;
        FOR(x1,10) FOR(y1,10) {
			string S=to_string(num);
			FORR(c,S) {
				if(c=='0'+x1) c=y1+'0';
			}
			if(S[0]=='0') continue;
			R.insert(atoi(S.c_str()));
		}
        return *R.rbegin()-*R.begin();
        
    }
};

