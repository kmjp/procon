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
	int S;
	vector<int> B;
	int ok(int t) {
		int cur=0;
		int num=1;
		FORR(b,B) {
			if(b>t) return 0;
			int st=t-b;
			while(st/S>cur/S) {
				cur+=S;
				num=min(num*2,1<<20);
			}
			if(num==0) return 0;
			num--;
		}
		
		return 1;
		
	}
    int minBuildTime(vector<int>& blocks, int split) {
		sort(ALL(blocks));
		reverse(ALL(blocks));
		B=blocks;
		S=split;
		
		int ret=1<<26;
		for(int i=25;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		return ret;
        
    }
};


