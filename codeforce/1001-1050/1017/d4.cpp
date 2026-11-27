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
string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B;
		vector<pair<int,int>> X,Y;
		FORR(c,A) {
			if(X.empty()||X.back().first!=c) X.push_back({c,0});
			X.back().second++;
		}
		FORR(c,B) {
			if(Y.empty()||Y.back().first!=c) Y.push_back({c,0});
			Y.back().second++;
		}
		int ok=1;
		if(X.size()!=Y.size()) ok=0;
		if(X[0].first!=Y[0].first) ok=0;
		for(i=0;ok&&i<Y.size();i++) {
			if(X[i].second<(Y[i].second+1)/2) ok=0;
			if(X[i].second>Y[i].second) ok=0;
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
