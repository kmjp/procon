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


int N,M,L;
int A[32];

ll ret=0;
vector<int> cand;
int O[32];
const ll mo=1000000007;

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

int Bob(int LL,int RR);
int Alice(int LL,int RR) {
	if(LL+1==RR) return O[A[LL]];
	int MM=(LL+RR)/2;
	return max(Bob(LL,MM),Bob(MM,RR));
}
int Bob(int LL,int RR) {
	if(LL+1==RR) return O[A[LL]];
	int MM=(LL+RR)/2;
	return min(Alice(LL,MM),Alice(MM,RR));
}

void dfs(int mask) {
	
	if(mask==0) {
		int x=Alice(0,1<<L);
		int i;
		for(i=1;i<=M;i++) {
			ll p=comb(i-1,x)*comb(M-i,cand.size()-(x+1));
			(ret+=p%mo*i)%=mo;
		}
		return;
	}
	
	int i;
	for(int sm=mask; sm>0; sm=(sm-1)&mask) {
		FOR(i,N) if(sm&(1<<i)) O[i]=cand.size();
		cand.push_back(sm);
		dfs(mask^sm);
		cand.pop_back();
	}
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>L;
	FOR(i,1<<L) {
		cin>>A[i];
		A[i]--;
	}
	ret=0;
	dfs((1<<N)-1);
	
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


