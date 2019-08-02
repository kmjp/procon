
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
    int tribonacci(int n) {
		ll T[50]={};
		T[0]=0;
		T[1]=T[2]=1;
		int i;
		for(i=3;i<=40;i++) T[i]=T[i-1]+T[i-2]+T[i-3];
		return T[n];
		
        
    }



};

