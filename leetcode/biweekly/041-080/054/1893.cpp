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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		int ok[51]={};
		FORR(v,ranges) {
			for(int a=v[0];a<=v[1];a++) ok[a]=1;
		}
		int i;
		for(i=left;i<=right;i++) if(ok[i]==0) return 0;
		return 1;
        
    }
};
