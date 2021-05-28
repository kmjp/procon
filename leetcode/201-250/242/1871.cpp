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

int ok[101011];

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        ZERO(ok);
        ok[0]=0;
        int i;
        set<int> S;
        S.insert(0);
        S.insert(1<<20);
        for(i=1;i<s.size();i++) if(s[i]=='0') {
			auto it=S.lower_bound(i-maxJump);
			if(*it<=i-minJump) {
				ok[i]=1;
				S.insert(i);
			}
			
		}
		return ok[s.size()-1];
        
    }
};
