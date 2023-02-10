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

int N,K;
ll L,P,A[55],B[55];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt[18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L>>P;
	FOR(i,N) cin>>A[i]>>B[i];
	int X=N/2;
	int Y=N-X;
	int mask;
	vector<ll> pat={-1LL};
	vector<pair<ll,pair<int,ll>>> C,D;
	FOR(mask,1<<X) {
		ll As=0,Bs=0;
		FOR(i,X) if(mask&(1<<i)) As+=A[i],Bs+=B[i];
		C.push_back({As,{__builtin_popcount(mask),Bs}});
		pat.push_back(Bs);
		pat.push_back(P-Bs);
	}
	FOR(mask,1<<Y) {
		ll As=0,Bs=0;
		FOR(i,Y) if(mask&(1<<i)) As+=A[i+X],Bs+=B[i+X];
		D.push_back({As,{__builtin_popcount(mask),Bs}});
		pat.push_back(Bs);
	}
	sort(ALL(pat));
	sort(ALL(C));
	reverse(ALL(C));
	sort(ALL(D));
	reverse(ALL(D));
	ll ret=0;
	FORR2(a,b,C) {
		if(a>L) continue;
		if(b.first>K) continue;
		while(D.size()&&D.back().first+a<=L) {
			x=lower_bound(ALL(pat),D.back().second.second)-pat.begin();
			bt[D.back().second.first].add(x,1);
			D.pop_back();
		}
		x=lower_bound(ALL(pat),P-b.second)-pat.begin();
		FOR(i,18) if(b.first+i<=K) ret+=bt[i]((1<<20)-1)-bt[i](x-1);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
