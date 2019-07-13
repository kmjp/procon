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
    int numberOfDays(int Y, int M) {
        int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(Y%400==0 || (Y%4==0&&Y%100)) D[2]++;
        return D[M];
        
    }
    
};

