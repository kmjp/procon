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
    int maxTurbulenceSize(vector<int>& A) {
		int cur=0,ma=0,i;
		FOR(i,A.size()-1) {
			if(i%2==0) {
				if(A[i]<A[i+1]) cur++;
				else cur=0;
				
			}
			else {
				if(A[i]>A[i+1]) cur++;
				else cur=0;
			}
			ma=max(ma,cur);
		}
		cur=0;
		FOR(i,A.size()-1) {
			if(i%2==1) {
				if(A[i]<A[i+1]) cur++;
				else cur=0;
				
			}
			else {
				if(A[i]>A[i+1]) cur++;
				else cur=0;
			}
			ma=max(ma,cur);
		}
		return ma+1;
        
    }
};
