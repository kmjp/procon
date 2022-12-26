#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll A[20],B[20];
vector<pair<ll,ll>> As,Bs;
vector<ll> C;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	
	int mask;
	for(mask=1;mask<(1<<N)-1;mask++) {
		ll a=0,b=0;
		FOR(i,N) {
			if(mask&(1<<i)) a+=A[i];
			else b+=A[i];
		}
		if(a>b) As.push_back({a,b});
	}
	C.push_back(0);
	for(mask=1;mask<(1<<M)-1;mask++) {
		ll a=0,b=0;
		FOR(i,M) {
			if(mask&(1<<i)) a+=B[i];
			else b+=B[i];
		}
		if(a>b) {
			Bs.push_back({a,b});
			C.push_back(b);
		}
	}
	sort(ALL(As));
	sort(ALL(Bs));
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	
	double ret=0;
	x=0;
	FORR(a,As) {
		while(x<Bs.size() && Bs[x].first<a.first) {
			y=lower_bound(ALL(C),Bs[x].second)-C.begin();
			bt.add(y,1);
			x++;
		}
		y=lower_bound(ALL(C),a.second)-C.begin();
		ret=max(ret,(double)bt(y-1));
	}
	ret/=Bs.size();
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
