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

set<ll> S[7];
template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

bool fail(ll mask,int H,int W,int X) {
	int h=0,w=0,y,x,ty,tx;
	int did[25][25];
	while(mask&(255LL<<(h*8))) h++;
	while(mask&((0x0101010101010101LL)<<w)) w++;
	
	for(y=0;y+h-1<H;y++) for(x=0;x+w-1<W;x++) {
		ZERO(did);
		UF<900> uf;
		FOR(ty,h) FOR(tx,w) if(mask & (1LL<<(ty*8+tx))) did[y+ty][x+tx]=1;
		FOR(ty,H) FOR(tx,W) {
			if(ty<H-1 && did[ty][tx]==did[ty+1][tx]) uf(ty*W+tx,(ty+1)*W+tx);
			if(tx<W-1 && did[ty][tx]==did[ty][tx+1]) uf(ty*W+tx,ty*W+tx+1);
		}
		int ok=1;
		FOR(ty,H) FOR(tx,W) if(uf.count(ty*W+tx)%X) ok=0;
		if(ok) return false;
	}
	return true;
}

bool win(int X,int R,int C) {
	if(X>=7) return true;
	if(X>max(R,C)) return true;
	if(R*C%X) return true;
	if(min(R,C)>=X+2) return false;
	
	ITR(it,S[X]) {
		if(fail(*it,R,C,X) && fail(*it,C,R,X)) return true;
	}
	return false;
	
}

void solve(int _loop) {
	int X,R,C;
	cin>>X>>R>>C;
	
	if(win(X,R,C)) _P("Case #%d: RICHARD\n",_loop);
	else _P("Case #%d: GABRIEL\n",_loop);
}


void getnext(set<ll>& F, set<ll>& T) {
	int y,x;
	
	ITR(it,F) {
		ll c=*it;
		FOR(y,7) FOR(x,7) if(c&(1LL<<(y*8+x))) {
			if(x && ((c&(1LL<<(y*8+x-1)))==0)) T.insert(c | (1LL<<(y*8+x-1)));
			if(y && ((c&(1LL<<((y-1)*8+x)))==0)) T.insert(c | (1LL<<((y-1)*8+x)));
			if((c&(1LL<<(y*8+x+1)))==0) T.insert(c | (1LL<<(y*8+x+1)));
			if((c&(1LL<<((y+1)*8+x)))==0) T.insert(c | (1LL<<((y+1)*8+x)));
			if(x==0) T.insert((c<<1) | (1LL<<(y*8)));
			if(y==0) T.insert((c<<8) | (1LL<<x));
		}
	}
}

void init() {
	int i;
	S[1].insert(1);
	for(i=1;i<=5;i++) getnext(S[i],S[i+1]);
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


