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

int T,N,M;
ll A[202020];
const ll mo=998244353;

vector<ll> enumpr(ll n) {
	vector<ll> V;
	//if(n==1) return vector<ll>(1,1);
	for(ll i=2;i*i<=n;i++) while(n%i==0) V.push_back(i),n/=i;
	if(n>1) V.push_back(n);
	sort(V.begin(),V.end());
	return V;
}

ll hoge(ll v,ll p) {
	vector<ll> P=enumpr(p);
	P.erase(unique(ALL(P)),P.end());
	ll ret=0;
	int N=P.size();
	int mask;
	int i;
	
	FOR(mask,1<<N) {
		ll m=1;
		FOR(i,N) {
			if(mask&(1<<i)) m*=-P[i];
		}
		if(m>0) {
			ret+=v/m;
		}
		else {
			ret-=v/(-m);
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>A[i];
		ll cur=A[0];
		ll ret=1;
		for(i=1;i<N;i++) {
			if(cur%A[i]) {
				ret=0;
				break;
			}
			if(A[i]==cur) {
				(ret*=M/cur)%=mo;
			}
			else {
				(ret*=hoge(M/A[i],cur/A[i]))%=mo;
			}
			cur=A[i];
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
