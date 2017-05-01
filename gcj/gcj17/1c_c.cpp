#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
double U;
double P[101],Q[101];
double L[101][101],R[101][101],dp[101][101];
double A[101],B[101];



void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>N>>K>>U;
	FOR(i,N) cin>>P[i];
	sort(P,P+N);
	
	double ma=0;
	for(k=N-1;k>=0;k--) {
		FOR(i,N) {
			FOR(j,N) Q[j]=P[j];
			double l=0,r=1;
			FOR(j,100) {
				double m=(l+r)/2;
				double left=U;
				for(x=i;x<N;x++) left-=max(0.0,m-Q[x]);
				if(left<0) r=m;
				else l=m;
			}
			
			for(x=i;x<N;x++) Q[x]=max(Q[x],l);
			ZERO(L);
			L[0][0]=1;
			FOR(x,N) {
				FOR(y,N) {
					L[x+1][min(K,y+1)] += L[x][y]*Q[x];
					L[x+1][y] += L[x][y]*(1-Q[x]);
				}
			}
			ma=max(ma,L[N][K]);
		}
		
		double a=min(1-P[k],U);
		P[k]+=a;
		U-=a;
	}
	if(U>0) ma=1;
	
	_P("Case #%d: %.12lf\n",_loop,ma);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


