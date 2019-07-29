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
    int largestUniqueNumber(vector<int>& A) {
		map<int,int> M;
		FORR(a,A) M[a]++;
		int ret=-1;
		FORR(m,M) {
			if(m.second==1) ret=m.first;
		}
		return ret;
		
        
    }
};

