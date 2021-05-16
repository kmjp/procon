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


int N;
int V[101010];
const ll mo=1000000007;
set<int> VS[101010];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll dfs(int L,int R,int cur) {
	if(L==R+1) return 1;
	if(VS[cur].empty()) return 0;
	
	auto it=VS[cur].lower_bound(R+1);
	if(it==VS[cur].begin()) return 0;
	it--;
	int M=*it;
	if(M<L||M>R) return 0;
	ll pat1=dfs(L,M-1,cur);
	ll pat2=dfs(M+1,R,cur+1);
	
	ll ret=pat1*pat2%mo*comb(R-L,M-L)%mo;
	return ret;
	
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	FOR(i,N+1) VS[i].clear();
	
	cin>>N;
	FOR(i,N) {
		cin>>V[i+1];
		VS[V[i+1]].insert(i+1);
	}
	
	ll ret=dfs(1,N,1);
	
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
		//fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


