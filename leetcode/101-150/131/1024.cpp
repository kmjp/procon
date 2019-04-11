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
    int videoStitching(vector<vector<int>>& clips, int T) {
		int ev[101];
		MINUS(ev);
		
		FORR(c,clips) ev[c[0]]=max(ev[c[0]],c[1]);
		
		int ret=0;
		int cur=0;
		int i;
		FOR(i,T) {
			if(i<cur) ev[i+1]=max(ev[i+1],ev[i]);
			else {
				ret++;
				if(ev[i]<i) return -1;
				cur=ev[i];
			}
		}
		return ret;
        
    }
};

