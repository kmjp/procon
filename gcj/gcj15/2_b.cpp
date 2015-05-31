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

int N;
double V,X;
vector<pair<double,double>> P,P2;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	cin>>N>>V>>X;
	
	P.clear();
	P.resize(N);
	double VV[3]={};
	double VX[3]={};
	
	FOR(i,N) {
		cin>>P[i].second>>P[i].first;
		P[i].first -= X;
		if(P[i].first<0) VX[0]+=abs(P[i].second*P[i].first);
		if(P[i].first>0) VX[1]+=abs(P[i].second*P[i].first);
	}
	sort(P.begin(),P.end());
	
	VX[0]=VX[1]=min(VX[0],VX[1]);
	double vr=0,v;
	FOR(i,N) {
		if(P[i].first==0) vr+=P[i].second;
		if(P[i].first>0) {
			v=min(P[i].second,VX[1]*1.0/P[i].first);
			VX[1] -= v*P[i].first;
			vr += v;
		}
	}
	for(i=N-1;i>=0;i--) if(P[i].first<0) {
		v=min(P[i].second,-VX[0]*1.0/P[i].first);
		VX[0] += v*P[i].first;
		vr += v;
	}
	
	if(vr==0) _P("Case #%d: IMPOSSIBLE\n",_loop);
	else _P("Case #%d: %.12lf\n",_loop,V/vr);
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


