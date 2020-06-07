#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K,N;
int X[101];
int T[101];

int num[101];
int cand[101];
int L[101],R[101];
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>K>>N;
	FOR(i,N) cin>>X[i];
	X[N]=X[0]+K;
	FOR(i,N) cin>>T[i];
	vector<int> V;
	V.push_back(X[1]-X[0]);
	for(i=1;i<N;i++) {
		if(T[i]!=T[i-1]) V.push_back(0);
		V.back()+=X[i+1]-X[i];
	}
	
	if(V.size()>1 && T[0]==T[N-1]) {
		V[0]+=V.back();
		V.pop_back();
	}
	
	if(V.size()==1) {
		_P("Case #%d: 1\n",_loop);
		return;
	}
	
	FORR(v,V) v*=2;
	MINUS(num);
	ZERO(cand);
	int am=0;
	int sum=0;
	FOR(i,V.size()) {
		int f=sum,t=sum+V[i];
		for(j=f+1;j<t;j++) num[j]=i, cand[j] |= 1<<j, am|=1<<j;
		sum+=V[i];
		
	}
	int mi=10101;
	int mask;
	FOR(mask,1<<(sum+1)) {
		if((mask&am)!=mask) continue;
		int p=0;
		FOR(i,V.size()) L[i]=1<<30,R[i]=-1;
		FOR(i,sum+1) if(mask&(1<<i)) {
			L[num[i]]=min(L[num[i]],i);
			R[num[i]]=i;
			p++;
		}
		if(p>=mi) continue;
		
		int ng=0;
		L[V.size()]=L[0]+sum;
		int tsum=0;
		FOR(i,V.size()) {
			if(L[i]>=1<<30) ng=1;
			tsum+=V[i];
			if(R[i]+L[i+1]!=2*tsum) ng=1;
		}
		
		if(ng==0) mi=p;
		
	}
	
	
	
	_P("Case #%d: %d\n",_loop,mi);
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


