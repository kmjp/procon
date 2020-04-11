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

int H,W;

struct node {
	int L,R;
	int U,D;
	int val;
	int alive;
};
vector<node> V[101010];
vector<pair<int,int>> cand,cand2;

int ng(int y,int x) {
	int num=1;
	int sum=V[y][x].val;
	if(V[y][x].L>=0) num++,sum+=V[y][V[y][x].L].val;
	if(V[y][x].R<W) num++,sum+=V[y][V[y][x].R].val;
	if(V[y][x].U>=0) num++,sum+=V[V[y][x].U][x].val;
	if(V[y][x].D<H) num++,sum+=V[V[y][x].D][x].val;
	return V[y][x].val*num<sum;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	ll sum=0,ret=0;
	FOR(y,H) {
		V[y].resize(W);
		FOR(x,W) {
			cin>>V[y][x].val;
			V[y][x].L=x-1;
			V[y][x].R=x+1;
			V[y][x].U=y-1;
			V[y][x].D=y+1;
			V[y][x].alive=1;
			sum+=V[y][x].val;
		}
	}
	
	FOR(y,H) FOR(x,W) {
		if(ng(y,x)) cand.push_back({y,x});
	}
	ret=sum;
	while(cand.size()) {
		cand2.clear();
		FORR(c,cand) {
			x=c.second;
			y=c.first;
			sum-=V[y][x].val;
			V[y][x].alive=0;
			if(V[y][x].L>=0) {
				cand2.push_back({y,V[y][x].L});
				V[y][V[y][x].L].R=V[y][x].R;
			}
			if(V[y][x].R<W) {
				cand2.push_back({y,V[y][x].R});
				V[y][V[y][x].R].L=V[y][x].L;
			}
			if(V[y][x].U>=0) {
				cand2.push_back({V[y][x].U,x});
				V[V[y][x].U][x].D=V[y][x].D;
			}
			if(V[y][x].D<H) {
				cand2.push_back({V[y][x].D,x});
				V[V[y][x].D][x].U=V[y][x].U;
			}
		}
		cand.clear();
		sort(ALL(cand2));
		cand2.erase(unique(ALL(cand2)),cand2.end());
		FORR(c,cand2) if(V[c.first][c.second].alive && ng(c.first,c.second)) cand.push_back(c);
		ret+=sum;
	}
	
	
	_P("Case #%d: %lld\n",_loop,ret);
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


