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

int W;

set<pair<ll,ll>> S;

void hoge(ll p) {
	auto it=S.lower_bound({p,1LL<<60});
	it--;
	auto pa=*it;
	S.erase(it);
	if(pa.first<=p-10000000000LL) {
		S.insert({pa.first,p});
	}
	if(pa.second>=p+20000000000LL) {
		S.insert({p+10000000000LL,pa.second});
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	S.clear();
	S.insert({1,1000000000001LL});
	while(1) {
		ll P;
		cin>>P;
		if(P==-1) exit(0);
		if(P<0) break;
		
		hoge(P);
		vector<pair<ll,ll>> V[4];
		FORR(s,S) {
			ll d=s.second-s.first;
			if(d==20000000000LL) V[1].push_back(s);
			else if(d<20000000000LL) V[0].push_back(s);
			else if(d<30000000000LL) V[2].push_back(s);
			else V[3].push_back(s);
		}
		
		ll tar;
		if(V[3].size()) {
			tar=V[3][0].first+20000000000LL;
		}
		else if(V[2].size()) {
			tar=V[2][0].first;
		}
		else if(V[1].size()) {
			if((V[0].size()+V[1].size())%2==0) {
				tar=V[1][0].first;
			}
			else {
				tar=V[1][0].first+1;
			}
		}
		else {
			tar=V[0][0].first;
		}
		
		
		cout<<tar<<endl;
		hoge(tar);
		
	}
}

void init() {
	cin>>W;
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


