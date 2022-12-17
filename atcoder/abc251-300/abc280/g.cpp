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

const ll mo=998244353;
int N;
ll X[303],Y[303];
ll D;
ll p2[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	p2[0]=1;
	FOR(i,301) p2[i+1]=p2[i]*2%mo;
	
	ll ret=0;
	FOR(x,N) FOR(y,N) {
		if(x!=y) {
			if(Y[x]>=Y[y]||X[x]<=X[y]) continue;
		}
		ll a=Y[x]-X[x];
		ll b=Y[y]-X[y];
		if(a>b) swap(a,b);
		if(abs(a-b)>D) continue;
		vector<ll> V;
		FOR(i,N) {
			if(i==x) continue;
			if(i==y) continue;
			if(Y[i]==Y[x]&&X[i]<X[x]) continue;
			if(X[i]==X[y]&&Y[i]<Y[y]) continue;
			if(X[i]<X[y]||X[i]>X[y]+D) continue;
			if(Y[i]<Y[x]||Y[i]>Y[x]+D) continue;
			V.push_back(Y[i]-X[i]);
		}
		sort(ALL(V));
		FOR(i,V.size()) {
			ll v=V[i];
			if(v>a) break;
			if(v+D<b) continue;
			k=lower_bound(ALL(V),v+D+1)-V.begin()-i;
			ret+=p2[k-1];
		}
		k=lower_bound(ALL(V),a+D+1)-lower_bound(ALL(V),a+1);
		ret+=p2[k];
		
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
