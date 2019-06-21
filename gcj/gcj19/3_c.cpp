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

int T;
int H,W;
string S[101];
char U[101][101];
template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<10101> uf;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	uf.reinit();
	FOR(y,H) FOR(x,W) {
		if(y && S[y][x]==S[y-1][x]) uf(y*100+x,(y-1)*100+x);
		if(x && S[y][x]==S[y][x-1]) uf(y*100+x,y*100+x-1);
	}
	ZERO(U);
	FOR(y,H-1) FOR(x,W-1) U[y][x]='.';
	FOR(y,H-1) FOR(x,W-1) if(S[y][x]==S[y+1][x+1] && S[y+1][x]!=S[y][x] && S[y][x+1]!=S[y][x]) {
		if(uf[y*100+x]!=uf[(y+1)*100+x+1]) {
			U[y][x]='\\';
			uf(y*100+x,(y+1)*100+x+1);
		}
		else if(uf[(y+1)*100+x]!=uf[y*100+x+1]) {
			U[y][x]='/';
			uf((y+1)*100+x,y*100+x+1);
		}
	}
	
	
	int num=0;
	FOR(y,H) FOR(x,W) if(uf[y*100+x]==y*100+x) num++;
	if(num==2) {
		_P("Case #%d: POSSIBLE\n",_loop);
		FOR(y,H-1) _P("%s\n",U[y]);
	}
	else {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
	}
	
	
	
	
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


