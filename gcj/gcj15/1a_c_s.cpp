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

// this dows not work for Large input. O(2^N*N*logN)

template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

template<class C> vector<int> convex_hull(vector< pair<C, C> >& vp) {
	vector<pair<pair<C, C>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	if(vp.size()<=2) {
		if(vp.size()>=1) res.push_back(0);
		if(vp.size()>=2 && vp[0]!=vp[1]) res.push_back(1);
		return res;
	}
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<0) k--;
		res[k++]=sorted[i].second;
	}
	/* top */
	for(rb=k, i=vp.size()-2;i>=0;i--) {
		while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<0) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k-1);
	return res;
}

int N;
ll X[3030],Y[3030];
int ma[3030];


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i], ma[i]=2;
	
	for(int mask=0;mask<1<<N;mask++) if(__builtin_popcount(mask)>2) {
		vector<int> P;
		vector<pair<ll,ll> > Pos;
		FOR(x,N) if(mask&(1<<x)) P.push_back(x), Pos.emplace_back(X[x],Y[x]);
		}
		vector<int> V=convex_hull(Pos);
		FORR(r,V) ma[P[r]]=max(ma[P[r]],__builtin_popcount(mask));
	}
	
	_P("Case #%d:\n",_loop);
	FOR(i,N) _P("%d\n",N-ma[i]);
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


