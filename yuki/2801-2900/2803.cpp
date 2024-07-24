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

int N,S;
int P[202020];
multiset<ll> X={-1LL<<60,1LL<<60};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	FOR(i,N) {
		cin>>P[i];
		X.insert(P[i]);
	}
	vector<int> V;
	FOR(i,N) {
		X.erase(X.find(P[i]));
		auto it=X.lower_bound(P[i]);
		if(*it>P[i]+S&&*prev(it)<P[i]-S) V.push_back(i+1);
		X.insert(P[i]);
	}
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
