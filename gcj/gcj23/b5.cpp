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

int T,N;
int D[101010];
ll cur[101010];
ll C[101010];
int in[101010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		cin>>D[i];
		D[i]--;
		in[D[i]]++;
		cur[i]=0;
	}
	queue<int> Q;
	FOR(i,N) {
		cin>>C[i];
		if(in[i]==0) Q.push(i);
	}
	ll ret=0;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(cur[x]<C[x]) ret+=C[x]-cur[x];
		cur[D[x]]+=C[x];
		in[D[x]]--;
		if(in[D[x]]==0) Q.push(D[x]);
	}
	
	FOR(i,N) if(in[i]) {
		vector<int> V={i};
		while(in[V.back()]) {
			in[V.back()]=0;
			V.push_back(D[V.back()]);
		}
		ll mi=1LL<<60;
		FOR(j,V.size()) {
			ll a=max(C[V[j]]-cur[V[j]],0LL);
			ll b=max(C[V[j]]-(C[V[(j+V.size()-1)%V.size()]]+cur[V[j]]),0LL);
			ret+=b;
			mi=min(mi,a-b);
		}
		ret+=mi;
	}
	
	cout<<"Case #"<<_loop<<": "<<ret<<endl;
	
	
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


