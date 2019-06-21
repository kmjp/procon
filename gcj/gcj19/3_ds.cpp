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
int X[1010],Y[1010];
ll AX,AY,BX,BY;
map<pair<int,int>,int> S;

pair<int,int> mirror(int x,int y,int AX,int AY,int BX,int BY) {
	double dx=BX-AX;
	double dy=BY-AY;
	double d=hypot(BX-AX,BY-AY);
	dx=dx/d;
	dy=dy/d;
	double r=dx*(x-AX)+dy*(y-AY);
	double tx=AX+r*dx;
	double ty=AY+r*dy;
	double gx=x+2*(tx-x);
	double gy=y+2*(ty-y);
	int rx=round(gx);
	int ry=round(gy);
	
	if(abs(rx-gx)>1e-8) return {-101010,0};
	if(abs(ry-gy)>1e-8) return {-101010,0};
	return {rx,ry};
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	S.clear();
	cin>>N>>K;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]*=2;
		Y[i]*=2;
		S[{X[i],Y[i]}]=i;
	}
	X[N]=X[0];
	Y[N]=Y[0];
	
	assert(K==2);
	FOR(x,N) {
		y=x+N;
		if(x%2==0) AX=X[x/2], AY=Y[x/2];
		else AX=(X[x/2]+X[x/2+1])/2, AY=(Y[x/2]+Y[x/2+1])/2;
		if(y%2==0) BX=X[y/2], BY=Y[y/2];
		else BX=(X[y/2]+X[y/2+1])/2, BY=(Y[y/2]+Y[y/2+1])/2;
		
		if(AX==BX && AY==BY) continue;
		
		vector<int> V;
		FOR(i,N) {
			auto p=mirror(X[i],Y[i],AX,AY,BX,BY);
			if(S.count(p)==0) break;
			V.push_back(S[p]);
		}
		if(V.size()!=N) continue;
		int ok=0;
		FOR(i,N) if(V[i]==N-1) {
			FOR(j,N) if(V[(i+j)%N]!=N-1-j) break;
			if(j==N) ok=1;
		}
		if(ok) {
			_P("Case #%d: POSSIBLE\n",_loop);
			if(AX%2==0) _P("%lld/1 ",AX/2);
			else _P("%lld/2 ",AX);
			if(AY%2==0) _P("%lld/1 ",AY/2);
			else _P("%lld/2 ",AY);
			if(BX%2==0) _P("%lld/1 ",BX/2);
			else _P("%lld/2 ",BX);
			if(BY%2==0) _P("%lld/1\n",BY/2);
			else _P("%lld/2\n",BY);
			return;
		}
	}
	
	_P("Case #%d: IMPOSSIBLE\n",_loop);
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


