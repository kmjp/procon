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

int P;
ll E[10100],N[10100];
map<ll,ll> M;
vector<ll> V,ret;

map<ll,ll> dodo(map<ll,ll> mmm,ll v) {
	map<ll,ll> R,R2;
	FORR(r,mmm) if(r.second) {
		R[r.first] += r.second;
		R2[r.first+v] += r.second;
		mmm[r.first+v] -= r.second;
	}
	
	if(R2.count(0)) {
		V.push_back(-v);
		return R2;
	}
	else {
		V.push_back(v);
		return R;
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>P;
	M.clear();
	V.clear();
	FOR(i,P) cin>>E[i];
	FOR(i,P) cin>>N[i], M[E[i]]=N[i];
	
	while(M.begin()->second>1) {
		V.push_back(0);
		FORR(r,M) r.second/=2;
	}
	
	while(M.size()>1) {
		if(abs(M.begin()->first)>abs(M.rbegin()->first)) {
			auto it=M.begin();
			M=dodo(M,abs(it->first-(++it)->first));
		}
		else {
			auto it=M.rbegin();
			M=dodo(M,abs(it->first-(++it)->first));
		}
	}
	
	M.clear();
	vector<ll> v;
	FORR(r,V) v.push_back(abs(r));
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	FOR(i,P) M[E[i]]=N[i];
	
	V.clear();
	FORR(r,v) {
		if(r==0) {
			V.push_back(0);
			FORR(r,M) r.second/=2;
		}
		else {
			M=dodo(M,r);
		}
	}
	
	_P("Case #%d:",_loop);
	sort(V.begin(),V.end());
	FORR(r,V) _P(" %lld",r);
	_P("\n");
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


