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

int N;
ll X[202],L[202];
vector<ll> cand;

ll hoge(ll k) {
	int i;
	vector<ll> D;
	FOR(i,N) D.push_back(abs(X[i]-k));
	sort(ALL(D));
	FOR(i,N) if(D[i]>L[i]) return 0;
	return 1;
}

ll hoge2(ll LL,ll RR) {
	vector<pair<ll,int>> V;
	int i;
	FOR(i,N) {
		if(X[i]>=LL) V.push_back({X[i]-LL,1});
		else V.push_back({LL-X[i],-1});
	}
	sort(ALL(V));
	
	ll CL=LL,CR=RR;
	FOR(i,N) {
		if(V[i].second==1) {
			ll x=V[i].first+LL-L[i];
			CL=max(x,CL);
		}
		else {
			ll x=L[i]+LL-V[i].first;
			CR=min(x,CR);
		}
	}
	if(CL>CR) return 0;
	return CR-CL+1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cand.push_back(-(2LL<<60));
	cand.push_back((2LL<<60));
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i];
		cand.push_back(X[i]);
	}
	FOR(i,N) cin>>L[i];
	FOR(y,N) FOR(x,y) {
		cand.push_back((X[y]+X[x])/2);
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	ll ret=0;
	FOR(x,cand.size()) {
		ret+=hoge(cand[x]);
		if(x+1<cand.size()) ret+=hoge2(cand[x]+1,cand[x+1]-1);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
