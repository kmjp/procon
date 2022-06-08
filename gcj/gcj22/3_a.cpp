#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
int A[555];
int C[555];
int tstep;
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	FOR(i,N) {
		cin>>A[i];
	}
	
	int step=0;
	while(1) {
		step++;
		int vis[100]={};
		int nc=1;
		FOR(i,N) if(vis[i]==0) {
			vector<int> V;
			int cur=i;
			while(vis[cur]==0) {
				vis[cur]=1;
				V.push_back(cur);
				cur=A[cur]-1;
			}
			if(V.size()<=4) {
				FORR(v,V) C[v]=nc;
				nc++;
			}
			else {
				FOR(j,V.size()) {
					if(j<V.size()/2) C[V[j]]=nc;
					else C[V[j]]=nc+1;
				}
				nc+=2;
			}
		}
		FOR(i,N) cout<<C[i]<<" ";
		cout<<endl;
		cin>>x;
		if(x==-1) exit(0);
		if(x==1) break;
		FOR(i,N) cin>>A[i];
		/*
		cerr<<step<<" ";
		FOR(i,N) cerr<<A[i]<<" ";
		cerr<<endl;
		*/
	}
	tstep+=step;
	cerr<<_loop<<" "<<step<<" "<<tstep<<endl;
	//_P("Case #%d:\n",_loop);
}

void init() {
	cin>>N>>K;
	
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


