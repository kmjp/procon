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
    int minimumSum(int num) {
		int A[4];
		A[0]=num/1000;
		A[1]=num/100%10;
		A[2]=num/10%10;
		A[3]=num%10;
		sort(A,A+4);
		return (A[0]+A[1])*10+A[2]+A[3];
		
        
    }
};
