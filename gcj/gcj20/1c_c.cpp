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

int N,D;
ll A[10101];

unordered_map<ll,int> M[51];
vector<pair<ll,ll>> V;

bool comp(pair<ll,ll> A,pair<ll,ll> B) {
	// A.first/A.second<=B.first/B.second
	return A.first*B.second<B.first*A.second;
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	FOR(i,51) M[i].clear();
	V.clear();
	
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>A[i];
		for(j=1;j<=50;j++) {
			M[j][A[i]*j]++;
			V.push_back({A[i],j});
		}
	}
	sort(A,A+N);
	sort(ALL(V),comp);
	
	int mi=D-1;
	x=0;
	for(i=20;i>=0;i--) if(x+(1<<i)<V.size()) {
		ll a=V[x+(1<<i)].first;
		ll b=V[x+(1<<i)].second;
		ll num=0;
		FOR(j,N) num+=A[j]*b/a;
		if(num>=D) x+=1<<i;
	}
	
	y=x;
	FOR(i,y+1) if(i==0 || V[i].first*V[i-1].second!=V[i-1].first*V[i].second) {
		ll a=V[i].first;
		int j=V[i].second;
		//cout<<i<<" "<<y<<" "<<a<<" "<<j<<" "<<1.0*a/j<<endl;
		int cut=0;
		int lef=D;
		for(x=1;x<=lef;x++) if(M[j].count(a*x)) {
			int num=M[j][a*x];
			if(lef<=num*x) {
				cut+=lef/x*(x-1)+lef%x;
				lef=0;
			}
			else {
				lef-=num*x;
				cut+=num*(x-1);
			}
		}
		mi=min(mi,cut+lef);
	}
	
	_P("Case #%d: %d\n",_loop,mi);
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


