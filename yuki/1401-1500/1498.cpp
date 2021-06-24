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

ll X[1010101];
vector<ll> V[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100001;i++) X[i]=1LL*i*i+1;
	for(i=1;i<=100001;i++) if(X[i]>1) {
		ll p=X[i];
		
		for(ll x=i;x<=100001;x+=p) {
			while(X[x]%p==0) X[x]/=p, V[x].push_back(p);
		}
		for(ll x=p-i;x<=100001;x+=p) {
			while(X[x]%p==0) X[x]/=p, V[x].push_back(p);
		}
	}
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x;
		sort(ALL(V[x]));
		FOR(i,V[x].size()) {
			cout<<V[x][i];
			if(i<V[x].size()-1) cout<<" ";
		}
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
