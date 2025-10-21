#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int N,K,D;
int H[202020],id[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,20> num,sum;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>D;
	vector<ll> Hs;
	vector<pair<int,int>> P;
	FOR(i,N) {
		cin>>H[i];
		P.push_back({H[i],i});
	}
	sort(ALL(P));
	FOR(i,N) {
		Hs.push_back(P[i].first);
		id[P[i].second]=i;
	}
	ll ret=1LL<<60;
	FOR(i,N) {
		num.add(id[i],1);
		sum.add(id[i],H[i]);
		if(i-K>=0) {
			num.add(id[i-K],-1);
			sum.add(id[i-K],-H[i-K]);
		}
		if(i<K-1) continue;
		x=num.lower_bound(1);
		y=num.lower_bound(K);
		if(Hs[y]-Hs[x]<=D) {
			cout<<0<<endl;
			return;
		}
		ll cur=-1LL<<30;
		for(j=31;j>=0;j--) {
			ll tmp=cur+(1LL<<j);
			x=lower_bound(ALL(Hs),tmp)-Hs.begin();
			y=lower_bound(ALL(Hs),tmp+D+1)-Hs.begin();
			int lef=num(x-1);
			int ri=K-num(y-1);
			if(lef<=ri) cur=tmp;
		}
		for(ll cand=cur-3;cand<=cur+3;cand++) {
			x=lower_bound(ALL(Hs),cand)-Hs.begin();
			y=lower_bound(ALL(Hs),cand+D+1)-Hs.begin();
			ll a=cand*num(x-1)-sum(x-1);
			ll b=sum(N)-sum(y-1)-(cand+D)*(K-num(y-1));
			ret=min(ret,a+b);
			
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
