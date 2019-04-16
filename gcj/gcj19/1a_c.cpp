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
string W[1010];

int valid[1010];
int num[1010][1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		cin>>W[i];
		reverse(ALL(W[i]));
	}
	ZERO(num);
	FOR(y,N) FOR(x,y) {
		while(num[x][y]<W[x].size()&&num[x][y]<W[y].size()&&W[x][num[x][y]]==W[y][num[x][y]]) num[x][y]++;
	}
	ZERO(valid);
	int ret=0;
	for(i=50;i>=1;i--) {
		set<string> SS;
		FOR(y,N) if(valid[y]==0) FOR(x,y) if(valid[x]==0 && num[x][y]>=i) {
			string S=W[x].substr(0,i);
			if(SS.count(S)==0) {
				SS.insert(S);
				ret+=2;
				valid[x]=valid[y]=1;
			}
		}
	}
	
	
	_P("Case #%d: %d\n",_loop,ret);
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


