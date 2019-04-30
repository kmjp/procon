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
int K;
pair<int,int> P[101010];
int D[101010];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	void init(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<19> st;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	st.init();
	
	cin>>N>>K;
	
	set<int> invalid;
	invalid.insert(0);
	invalid.insert(N+1);
	ll ret=0;
	
	FOR(i,N) {
		P[i].second=i+1;
		cin>>P[i].first;
	}
	FOR(i,N) {
		cin>>x;
		st.update(i+1,x);
	}
	
	sort(P,P+N);
	reverse(P,P+N);
	FOR(i,N) {
		int cur=P[i].second;
		auto it=invalid.lower_bound(cur);
		int R=*it-1;
		it--;
		int L=*it+1;
		invalid.insert(cur);
		
		ll maL=cur+1,maR=cur-1;
		ll miL=cur+1,miR=cur-1;
		for(j=19;j>=0;j--) {
			if(maL-(1<<j)>=L && st.getval(maL-(1<<j),cur+1)<=P[i].first+K) maL-=1<<j;
			if(maR+(1<<j)<=R && st.getval(cur,maR+(1<<j)+1)<=P[i].first+K) maR+=1<<j;
			if(miL-(1<<j)>=L && st.getval(miL-(1<<j),cur+1)<P[i].first-K) miL-=1<<j;
			if(miR+(1<<j)<=R && st.getval(cur,miR+(1<<j)+1)<P[i].first-K) miR+=1<<j;
		}
		
		ret+=(cur+1-maL)*(maR+1-cur)-(cur+1-miL)*(miR+1-cur);
		
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


