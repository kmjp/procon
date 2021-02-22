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
    vector<int> minOperations(string boxes) {
		int N=boxes.size();
		vector<int> V(N,0);
		int i,j;
		FOR(i,N) {
			FOR(j,N) if(boxes[j]=='1') V[i]+=abs(i-j);
		}
        return V;
    }
};
