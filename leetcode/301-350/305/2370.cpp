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

int pre[26];

class Solution {
public:
    int longestIdealString(string s, int k) {
        ZERO(pre);
        int ret=0;
        FORR(c,s) {
			int ma=0;
			int i;
			FOR(i,26) if(abs(c-'a'-i)<=k) ma=max(ma,pre[i]);
			pre[c-'a']=ma+1;
			ret=max(ret,ma+1);
			
		}
        return ret;
    }
};
