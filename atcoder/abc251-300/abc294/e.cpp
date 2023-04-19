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

ll L;
int N[2];
deque<pair<int,ll>> D[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>N[0]>>N[1];
	FOR(i,2) {
		FOR(j,N[i]) {
			ll y;
			cin>>x>>y;
			D[i].push_back({x,y});
		}
	}
	ll ret=0;
	while(D[0].size()) {
		ll x=min(D[0][0].second,D[1][0].second);
		if(D[0][0].first==D[1][0].first) ret+=x;
		FOR(i,2) {
			D[i][0].second-=x;
			if(D[i][0].second==0) D[i].pop_front();
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
