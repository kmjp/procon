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
    int findTheLongestSubstring(string s) {
		int mi[32]={};
		int cur=0;
		int i,ret=0;
		mi[0]=0;
		FOR(i,32) mi[i]=1010101;
		mi[0]=0;
		FOR(i,s.size()) {
			if(s[i]=='a') cur^=1;
			if(s[i]=='i') cur^=2;
			if(s[i]=='u') cur^=4;
			if(s[i]=='e') cur^=8;
			if(s[i]=='o') cur^=16;
			ret=max(ret,(i+1)-mi[cur]);
			mi[cur]=min(mi[cur],(i+1));
		}
        return ret;
    }
};
