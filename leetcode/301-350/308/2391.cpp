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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		ll A[3]={};
		ll S[3]={};
		ll a=0;
		int i;
		
		FOR(i,garbage.size()) {
			FORR(c,garbage[i]) {
				
				if(c=='M') {
					S[0]++;
					A[0]=max(A[0],a);
				}
				if(c=='G') {
					S[1]++;
					A[1]=max(A[1],a);
				}
				if(c=='P') {
					S[2]++;
					A[2]=max(A[2],a);
				}
			}
			
			
			if(i<garbage.size()-1) a+=travel[i];
		}
		
		return A[0]+S[0]+A[1]+S[1]+A[2]+S[2];
		
    }
};
