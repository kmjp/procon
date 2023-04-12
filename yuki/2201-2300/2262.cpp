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

int T;
ll N,K;

vector<pair<int,int>> D[302020];

int hoge(ll p,int q) {
	int ret=0,i;
	int tp=min(p,(ll)q-1);
	FORR2(a,s,D[q]) ret+=s*(tp/a);
	return ret;
}

pair<ll,ll> hoge2(ll N,ll K) {
	ll L=0,R=1LL*N*N;
	int i;
	while(L+1<R) {
		ll M=(L+R)/2;
		ll tot=0;
		for(i=1;i<=N;i++) tot+=hoge(M*i/N/N,i);
		if(tot>=K) {
			R=M;
		}
		else {
			L=M;
		}
	}
	
	for(i=1;i<=N;i++) {
		ll a=hoge(R*i/N/N,i);
		ll b=hoge(L*i/N/N,i);
		if(a!=b) return {R*i/N/N,i};
	}
	return {0,0};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=300000;i++) D[i].push_back({1,1});
	
	for(i=2;i<=300000;i++) if(D[i].size()==1) {
		for(j=i;j<=300000;j+=i) {
			x=D[j].size();
			FOR(y,x) D[j].push_back({D[j][y].first*i,-D[j][y].second});
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ll num=0;
		for(i=1;i<=N;i++) num+=hoge(i,i);
		if(K<=num) {
			pair<ll,ll> p=hoge2(N,K);
			cout<<p.first<<"/"<<p.second<<endl;
		}
		else if(K==num+1) {
			cout<<"1/1"<<endl;
		}
		else if(K<=2*num+1) {
			pair<ll,ll> p=hoge2(N,2*num+2-K);
			cout<<p.second<<"/"<<p.first<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
