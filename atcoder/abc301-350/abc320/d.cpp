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

int N,M;
vector<pair<int,pair<int,int>>> E[202020];
ll X[202020],Y[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) X[i]=Y[i]=1LL<<60;
	FOR(i,M) {
		cin>>j>>k>>x>>y;
		E[j-1].push_back({k-1,{x,y}});
		E[k-1].push_back({j-1,{-x,-y}});
	}
	X[0]=Y[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR2(e,D,E[cur]) {
			ll x2=X[cur]+D.first;
			ll y2=Y[cur]+D.second;
			if(X[e]==1LL<<60) {
				X[e]=x2;
				Y[e]=y2;
				Q.push(e);
			}
		}
	}
	FOR(i,N) {
		if(X[i]==1LL<<60) {
			cout<<"undecidable"<<endl;
		}
		else {
			cout<<X[i]<<" "<<Y[i]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
