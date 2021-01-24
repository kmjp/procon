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
    vector<int> decode(vector<int>& encoded) {
		int C[2][20]={};
		int N=encoded.size()+1;
		vector<int> R(N);
		int i,j;
		for(i=1;i<=N;i++) {
			FOR(j,20) C[(i>>j)&1][j]++;
		}
		
		FOR(j,20) {
			int x=1<<j;
			int cur=0;
			int num0=1;
			FOR(i,N-1) {
				if(encoded[i]&x) cur^=x;
				if(cur==0) num0++;
			}
			
			if(C[0][j]!=num0) cur=x;
			else cur=0;
			R[0]^=cur;
			FOR(i,N-1) {
				if(encoded[i]&x) cur^=x;
				R[i+1]^= cur;
			}
		}
		return R;
		
        
    }
};


