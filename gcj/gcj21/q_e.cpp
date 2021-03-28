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

int P,N;
string S[101];
int O[101];
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	N=100;
	pair<int,int> A[101];
	pair<int,int> cnt[10101];
	FOR(i,N) {
		cin>>S[i];
		A[i].first=count(ALL(S[i]),'1');
		A[i].second=i;
	}
	FOR(j,10000) {
		cnt[j]={0,j};
		FOR(i,100) if(S[i][j]=='1') cnt[j].first++;
	}
	sort(A,A+N);
	sort(cnt,cnt+10000);
	FOR(i,N) {
		O[i]=A[i].second;
		string U;
		FOR(j,10000) U.push_back(S[i][cnt[j].second]);
		S[i]=U;
	}
	
	x=0;
	int ma=-1,ret=-1;
	int X[N],Y[N];
	FOR(j,N) {
		x=y=0;
		FOR(i,1000) {
			x+=S[O[j]][i]=='1';
			y+=S[O[j]][9999-i]=='0';
		}
		X[j]=x;
		Y[j]=y;
	}
	
	FOR(j,N) {
		int dif=0;
		x=j-1;
		y=j+1;
		if(x<0) x=y+1;
		if(y==N) y=x-1;
		dif=abs(X[j]-X[x])+abs(X[j]-X[y])+abs(Y[j]-Y[x])+abs(Y[j]-Y[y]);
		if(dif>ma) ma=dif, ret=O[j];
		
	}
	
	
	
	_P("Case #%d: %d\n",_loop, ret+1);
	
}

void init() {
	cin>>P;
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
		//fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


