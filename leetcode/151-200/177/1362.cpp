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
    vector<int> closestDivisors(int num) {
		int L=1,R=num+2;
		int i,j;
		for(i=1;i*i<=num+2;i++) {
			if((num+1)%i==0) {
				if((num+1)/i-i>=0 && (num+1)/i-i<R-L) R=(num+1)/i, L=i;
			}
			if((num+2)%i==0) {
				if((num+2)/i-i>=0 && (num+2)/i-i<R-L) R=(num+2)/i, L=i;
			}
		}
		return {L,R};
        
    }
};
