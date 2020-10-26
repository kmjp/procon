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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		int C[256]={};
		int pre=0;
		int i;
		FOR(i,releaseTimes.size()) {
			C[keysPressed[i]]=max(releaseTimes[i]-pre,C[keysPressed[i]]);
			pre=releaseTimes[i];
		}
		
		int tar=0;
		FOR(i,256) if(C[i]>=C[tar]) tar=i;
		return tar;
		
        
    }
};

