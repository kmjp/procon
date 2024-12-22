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

int T,N;
ll A[5050];
int P[5050];
vector<int> C[5050];
ll ret;
vector<ll> hoge(int cur) {
	vector<ll> V={0};
	ll sum=0;
	int i;
	FORR(e,C[cur]) {
		auto W=hoge(e);
		while(V.size()<W.size()+1) V.push_back(0);
		FOR(i,W.size()) V[i+1]=min(1LL<<60,V[i+1]+W[i]);
		sum+=A[e];
	}
	if(C[cur].empty()) V={1LL<<60};
	
	
	if(A[cur]<sum) {
		V[0]=sum-A[cur];
	}
	else {
		ll d=A[cur]-sum;
		FOR(i,V.size()) {
			ll mi=min(V[i],d);
			ret+=mi*i;
			d-=mi;
			V[i]-=mi;
		}
		assert(d==0);
		
	}
	return V;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			C[i].clear();
		}
		for(i=1;i<N;i++) {
			cin>>P[i];
			C[P[i]-1].push_back(i);
		}
		ret=0;
		hoge(0);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
