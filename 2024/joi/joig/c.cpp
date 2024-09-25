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
int C[303030],X[303030];
ll ret[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,vector<int>> M;
	multiset<ll> V={-1LL<<60,1LL<<60};
	FOR(i,N) {
		cin>>C[i]>>X[i];
		M[C[i]].push_back(i);
		V.insert(X[i]);
	}
	FORR2(a,b,M) {
		FORR(c,b) V.erase(V.find(X[c]));
		FORR(c,b) {
			auto it=V.lower_bound(X[c]);
			ret[c]=min(*it-X[c],X[c]-*prev(it));
		}
		FORR(c,b) V.insert(X[c]);
		
	}
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
