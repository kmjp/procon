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

int N,M,E;
ll D,A[50];
vector<pair<ll,ll>> B[2][3];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

ll hoge(vector<pair<ll,ll>> S,vector<pair<ll,ll>> T) {
	vector<ll> Y;
	vector<int> L,R;
	
	Y.push_back(-1LL<<60);
	Y.push_back(1LL<<60);
	FORR(r,S) Y.push_back(-D-r.second),Y.push_back(D-r.second);
	FORR(r,T) Y.push_back(r.second);
	sort(ALL(Y));
	Y.erase(unique(ALL(Y)),Y.end());
	int i;
	
	ZERO(bt.bit);
	ZERO(bt.val);
	
	vector<pair<ll,pair<int,ll>>> ev;
	FORR(r,S) ev.push_back({r.first,{1,r.second}});
	FORR(r,T) {
		ev.push_back({-D-r.first,{0,r.second}});
		ev.push_back({D-r.first,{2,r.second}});
	}
	
	ll ret=0;
	sort(ALL(ev));
	FORR(r,ev) {
		if(r.second.first==1) {
			int L=lower_bound(ALL(Y),-D-r.second.second)-Y.begin();
			int R=lower_bound(ALL(Y),D-r.second.second)-Y.begin();
			ret+=bt.total(R)-bt.total(L-1);
		}
		else {
			int y=lower_bound(ALL(Y),r.second.second)-Y.begin();
			if(r.second.first==0) bt.add(y,1);
			else bt.add(y,-1);
		}
	}
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	cin>>N>>D>>E;
	FOR(i,N) cin>>A[i];
	FOR(mask,1<<(2*min(10,N))) {
		int e=0;
		ll s[3]={};
		FOR(i,min(10,N)) {
			x = (mask>>(2*i))&3;
			if(x==3) e++;
			else s[x]+=A[i];
		}
		if(e<=E) B[0][e].push_back({s[1]-s[0],s[2]-s[0]});
	}
	FOR(mask,1<<(2*max(N-10,0))) {
		int e=0;
		ll s[3]={};
		FOR(i,max(N-10,0)) {
			x = (mask>>(2*i))&3;
			if(x==3) e++;
			else s[x]+=A[i+10];
		}
		if(e<=E) B[1][e].push_back({s[1]-s[0],s[2]-s[0]});
	}
	
	ll ret=0;
	FOR(x,3) FOR(y,3) if(x+y<=E) ret+=hoge(B[0][x],B[1][y]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
