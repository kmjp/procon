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
int P[1010];
int ma;
int inloop[1010];
int tar[1010],D[1010];
int ma2[1010];

void dfs(int cur,int st,int step) {
	if(step>1000) return;
	if(P[cur]==st) {
		tar[cur]=inloop[cur]=cur;
		sz[cur]=step;
		ma=max(ma,step);
	}
	else {
		dfs(P[cur],st,step+1);
		if(inloop[st]>=0) {
			tar[cur]=inloop[cur]=cur;
			sz[cur]=sz[st];
		}
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>P[i], P[i]--, V[i]=i;
	ma=0;
	MINUS(inloop);
	FOR(i,N) dfs(i,i,1);
	MINUS(tar);
	MINUS(D);
	ZERO(ma2);
	FOR(y,N) FOR(x,y) if(P[x]==y && P[y]==x) {
		inloop[x]=y,inloop[y]=x;
		tar[x]=x;
		tar[y]=y;
		D[x]=D[y]=1;
		ma2[x]=ma2[y]=1;
	}
	
	FOR(i,1010) {
		FOR(x,N) if(D[P[x]]>=0 && inloop[x]==-1) D[x]=D[P[x]]+1, tar[x]=tar[P[x]], ma2[tar[x]]=max(ma2[tar[x]],D[x]);
	}
	
	int tot=0;
	FOR(x,N) if(tar[x]==x) tot+=ma2[x];
	ma=max(ma,tot);
	
	_P("Case #%d: %d\n",_loop,ma);
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


