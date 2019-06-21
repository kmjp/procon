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

int S;
ll P[1010101];
ll PS[1010101];

ll mo=1000000007;
int L[1010101];
int R[1010101];
ll X[1010101];
ll Y[1010101];





void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>S;
	vector<pair<ll,int>> cand;
	set<int> valid;
	FOR(i,S) {
		cin>>P[i];
		L[i]=R[i]=i;
		X[i]=Y[i]=0;
		PS[i+1]=(PS[i]+P[i])%mo;
		cand.push_back({P[i],i});
		valid.insert(i);
	}
	sort(ALL(cand));
	ll ret=0;
	FORR(c,cand) {
		int cur=c.second;
		auto it=valid.find(cur);
		int CL=cur,CR=cur;
		if(it!=valid.begin()) {
			it--;
			if(P[*it]<=P[cur]) CL=*it;
			it++;
		}
		it++;
		if(it!=valid.end()) {
			if(P[*it]<P[cur]) CR=*it;
		}
		
		
		ll LX=X[CL];
		ll RY=Y[CR];
		X[cur]=X[CL]+X[CR];
		Y[cur]=Y[CL]+Y[CR];
		valid.erase(CL);
		valid.erase(CR);
		valid.insert(cur);
		
		CL=L[cur]=L[CL];
		CR=R[cur]=R[CR];
		
		(ret+=(CR-cur+1)*LX)%=mo;
		Y[cur]+=(CR-cur+1)*(P[cur]*(cur-CL)%mo-(PS[cur]-PS[CL]));
		(ret+=(cur-CL+1)*RY)%=mo;
		X[cur]+=(cur-CL+1)*(P[cur]*(CR-cur)%mo-(PS[CR+1]-PS[cur+1]));
		
		X[cur]=(X[cur]%mo+mo)%mo;
		Y[cur]=(Y[cur]%mo+mo)%mo;
	}
	
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


