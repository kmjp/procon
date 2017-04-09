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

int N,M;
string S[101],T[101];
int mask[101][101];

void solve(int _loop) {
	int f,i,j,k,l,x,y; char c;
	
	cin>>N>>M;
	FOR(y,N) S[y]=string(N,'.');
	FOR(y,N) FOR(x,N) mask[y][x]=3;
	FOR(i,M) {
		cin>>c>>y>>x;
		y--,x--;
		S[y][x]=c;
		
		if(c=='x' || c=='o') {
			FOR(j,N) mask[y][j] &= 1;
			FOR(j,N) mask[j][x] &= 1;
		}
		if(c=='+' || c=='o') {
			for(j=-N;j<=N;j++) {
				if((y+j)>=0 && (y+j)<N && (x+j)>=0 && (x+j)<N) mask[y+j][x+j] &= 2;
				if((y+j)>=0 && (y+j)<N && (x-j)>=0 && (x-j)<N) mask[y+j][x-j] &= 2;
			}
		}
	}
	FOR(y,N) T[y]=S[y];
	
	retry:
	int mi=10100,cy,cx;
	FOR(y,N) FOR(x,N) if(mask[y][x]&1) {
		int sc=0;
		for(j=-N;j<=N;j++) if(j) {
			if((y+j)>=0 && (y+j)<N && (x+j)>=0 && (x+j)<N && (mask[y+j][x+j]&1)) sc++;
			if((y+j)>=0 && (y+j)<N && (x-j)>=0 && (x-j)<N && (mask[y+j][x-j]&1)) sc++;
		}
		if(sc<mi) mi=sc,cy=y,cx=x;
	}
	if(mi<10100) {
		y=cy, x=cx;
		if(S[y][x]=='.') S[y][x]='+';
		else S[y][x]='o';
		for(j=-N;j<=N;j++) {
			if((y+j)>=0 && (y+j)<N && (x+j)>=0 && (x+j)<N) mask[y+j][x+j] &= 2;
			if((y+j)>=0 && (y+j)<N && (x-j)>=0 && (x-j)<N) mask[y+j][x-j] &= 2;
		}
		goto retry;
	}
	
	retry2:
	mi=10100,cy,cx;
	FOR(y,N) FOR(x,N) if(mask[y][x]&2) {
		int sc=0;
		FOR(j,N) if(j!=x && (mask[y][j]&2)) sc++;
		FOR(j,N) if(j!=y && (mask[j][x]&2)) sc++;
		if(sc<mi) mi=sc,cy=y,cx=x;
	}
	if(mi<10100) {
		y=cy, x=cx;
		if(S[y][x]=='.') S[y][x]='x';
		else S[y][x]='o';
		for(j=-N;j<=N;j++) {
			FOR(j,N) mask[y][j] &= 1;
			FOR(j,N) mask[j][x] &= 1;
		}
		goto retry2;
	}
	
	int pt=0,num=0;
	FOR(y,N) FOR(x,N) {
		if(S[y][x]!=T[y][x]) num++;
		if(S[y][x]=='o') pt+=2;
		if(S[y][x]=='+') pt+=1;
		if(S[y][x]=='x') pt+=1;
	}
	
	_P("Case #%d: %d %d\n",_loop,pt,num);
	FOR(y,N) FOR(x,N) if(S[y][x]!=T[y][x]) _P("%c %d %d\n",S[y][x],y+1,x+1);
	/*
	FOR(y,N) {
		cout<<S[y]<<" "<<T[y]<<" ";
		FOR(x,N) cout<<mask[y][x];
		cout<<endl;
	}
	*/
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


