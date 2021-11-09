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
ll A[6],B[6];
int ok;
set<vector<ll>> S;

void dfs(vector<ll> V) {
	ll a=min(V[0],V[3]);
	V[0]-=a;
	V[3]-=a;
	a=min(V[2],V[5]);
	V[2]-=a;
	V[5]-=a;
	if(S.count(V)) return;
	S.insert(V);
	int i;
	a=0;
	FOR(i,3) a+=V[i];
	if(a==0) {
		ok=1;
		return;
	}
	int x,y;
	for(x=2;x<=4;x++) if(V[x-2]) {
		for(y=x;y<=5;y++) if(V[y+1]) {
			ll m=min(V[x-2],V[y+1]);
			vector<ll> W=V;
			W[x-2]-=m;
			W[y+1]-=m;
			if(y-x>=2) W[y-x+1]+=m;
			dfs(W);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ll sum=0;
		FOR(i,5) {
			cin>>A[i+1];
			sum+=A[i+1]*(i+1);
		}
		FOR(i,5) {
			cin>>B[i+1];
			sum-=B[i+1]*(i+1);
		}
		if(sum>0) {
			cout<<"No"<<endl;
			continue;
		}
		ok=0;
		S.clear();
		vector<ll> V;
		ll a=min(A[5],B[5]);
		A[5]-=a;
		B[5]-=a;
		if(A[5]) {
			cout<<"No"<<endl;
			continue;
		}
		for(i=2;i<=4;i++) V.push_back(A[i]);
		for(i=2;i<=5;i++) V.push_back(B[i]);
		dfs(V);
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
