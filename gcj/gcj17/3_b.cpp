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

int F,P;
int A[2020],B[2020];
int mat[1010][1010];
int is[1010][1010];
map<int,int> E[2020];
int vis[1010];
int par[1010];
int D[1010];

void dfs(int cur,int pre) {
	vis[cur]=1;
	par[cur]=pre;
	D[cur]=(pre<0)?0:(D[pre]+1);
	
	FORR(r,E[cur]) {
		if(r.first==pre&&r.second==1) continue;
		if(vis[r.first]==0) {
			dfs(r.first,cur);
		}
		else if(D[r.first]<D[cur]) {
			mat[cur][r.first]++;
			int x=cur;
			while(x!=r.first) {
				mat[par[x]][x]++;
				x=par[x];
			}
		}
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>F>>P;
	ZERO(mat);
	ZERO(vis);
	ZERO(is);
	ZERO(D);
	FOR(i,F) E[i].clear();
	//cout<<F<<P<<endl;;
	FOR(i,P) {
		cin>>A[i]>>B[i];
		//cout<<A[i]<<B[i]<<endl;
		A[i]--,B[i]--;
		is[A[i]][B[i]]++;
		E[A[i]][B[i]]++;
		E[B[i]][A[i]]++;
	}
	
	FOR(i,F) if(vis[i]==0) dfs(i,-1);
	
	/*
	FOR(y,F) {
		FOR(x,F) _P("%2d ",mat[y][x]);
		_P("\n");
	}
	*/
	
	FOR(i,P) {
		if(is[B[i]][A[i]]) {
			if(mat[A[i]][B[i]]==0) {
				mat[A[i]][B[i]]++;
				mat[B[i]][A[i]]++;
			}
		}
		else {
			if(mat[A[i]][B[i]]==0) mat[A[i]][B[i]]=-mat[B[i]][A[i]];
			if(mat[A[i]][B[i]]==0) return _P("Case #%d: IMPOSSIBLE\n",_loop);
			
		}
	}
	
	_P("Case #%d:",_loop);
	FOR(i,P) _P(" %d",mat[A[i]][B[i]]);
	_P("\n");
	
	
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


