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
ll N,M1,M2;
unordered_map<ll,ll> memo;

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M1>>M2;
		ll M=M1*M2;
		auto P=enumdiv(M1);
		auto Q=enumdiv(M2);
		auto X=enumpr(M1);
		auto Y=enumpr(M2);
		
		vector<ll> A;
		FORR(p,P) FORR(q,Q) A.push_back(p*q);
		sort(ALL(A));
		A.erase(unique(ALL(A)),A.end());
		
		FORR2(a,b,Y) X[a]+=b;
		
		memo.clear();
		int num=0;
		ll val=0;
		FORR(a,A) {
			if(a<=N) memo[a]=a;
			if(a/memo[a]<=N) {
				num++;
				val^=a/memo[a];
			}
			FORR2(p,q,X) {
				if(M/a%p==0) {
					memo[a*p]=max(memo[a*p],memo[a]);
				}
			}
		}
		cout<<num<<" "<<val<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
