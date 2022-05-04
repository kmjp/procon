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
ll K;
ll A[1010],B[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<ll> V;
	int is0=0;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		ll c=(A[i]<<32)|B[i];
		FORR(t,V) c=min(c,t^c);
		if(c) V.push_back(c);
	}
	sort(ALL(V));
	reverse(ALL(V));
	
	if(V.empty()) {
		cout<<0<<endl;
		return;
	}
	if(V.back()>=(K+1)<<32) {
		cout<<-1<<endl;
		return;
	}
	
	ll ma=-1;
	ll a=0,b=0;
	FORR(v,V) {
		ll x=v>>32;
		ll y=v&((1LL<<31)-1);
		
		if((a^x)>K) continue;
		
		vector<ll> V2;
		FORR(v2,V) if(v2<v) {
			ll y2=v2&((1LL<<31)-1);
			FORR(v3,V2) y2=min(y2,y2^v3);
			V2.push_back(y2);
		}
		ll n=b;
		FORR(v2,V2) n=max(n,n^v2);
		ma=max(ma,n);
		
		a^=x;
		b^=y;
		ma=max(ma,b);
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
