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


int L[201010],R[201010];

class Solution {
public:
    int minimumTime(string s) {
        int pre=0;
        int N=s.size();
        int i;
		int mi=0;
        for(i=1;i<=N;i++) {
			if(s[i-1]=='1') {
				L[i]=min(i,L[pre]+2);
				mi=L[i];
				pre=i;
			}
		}
		if(pre==0) mi=0;
		R[N+1]=0;
		pre=N+1;
		int a=0;
		for(i=N;i>=1;i--) {
			if(s[i-1]=='1') {
				mi=min(mi,L[i]+R[pre]);
				R[i]=min(N+1-i,R[pre]+2);
				a=R[i];
				pre=i;
			}
		}
		mi=min(mi,a);
		return mi;
    }
};
