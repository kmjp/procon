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

int P,Q;
int R[503][2];
int C[503][2];
int X[501],Y[501],T[505];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	string s;
	cin>>P>>Q;
	vector<int> Xs,Ys;
	
	FOR(i,P) {
		cin>>X[i]>>Y[i]>>s;
		if(s=="W") T[i]=3,X[i]--;
		if(s=="E") T[i]=1,X[i]++;
		if(s=="N") T[i]=0,Y[i]++;
		if(s=="S") T[i]=2,Y[i]--;
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
	}
	Xs.push_back(0);
	Xs.push_back(Q);
	Ys.push_back(0);
	Ys.push_back(Q);
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	ZERO(R);
	ZERO(C);
	
	FOR(i,P) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		if(T[i]==3) C[X[i]][0]++;
		if(T[i]==1) C[X[i]][1]++;
		if(T[i]==0) R[Y[i]][1]++;
		if(T[i]==2) R[Y[i]][0]++;
	}
	int H=Ys.size();
	int W=Xs.size();
	
	for(y=1;y<H;y++) R[y][1]+=R[y-1][1];
	for(y=H-1;y>=0;y--) R[y][0]+=R[y+1][0];
	for(x=1;x<W;x++) C[x][1]+=C[x-1][1];
	for(x=W-1;x>=0;x--) C[x][0]+=C[x+1][0];
	
	int ma=0,ty=0,tx=0;
	FOR(x,W) FOR(y,H) {
		if(R[y][0]+R[y][1]+C[x][0]+C[x][1]>ma) {
			ma=R[y][0]+R[y][1]+C[x][0]+C[x][1];
			ty=y;
			tx=x;
		}
	}
	
	
	_P("Case #%d: %d %d\n",_loop,Xs[tx],Ys[ty]);
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


