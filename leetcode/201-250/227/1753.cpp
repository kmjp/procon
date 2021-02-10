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
    int maximumScore(int a, int b, int c) {
        int C[3]={a,b,c};
        int num=0;
        while(1) {
			sort(C,C+3);
			if(C[1]==0) break;
			C[1]--;
			C[2]--;
			num++;
		}
		return num;
    }
};
