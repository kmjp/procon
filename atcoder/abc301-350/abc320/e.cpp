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
map<int,vector<pair<ll,ll>>> E;
ll ret[202020];
set<int> alive;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) alive.insert(i);
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x].push_back({y,k});
	}
	while(E.size()) {
		auto v=*E.begin();
		E.erase(E.begin());
		ll ct=v.first;
		auto V=v.second;
		sort(ALL(V));
		FORR2(a,b,V) {
			if(a<=0) {
				alive.insert(-a);
			}
			else if(alive.size()) {
				x=*alive.begin();
				alive.erase(x);
				ret[x]+=a;
				E[ct+b].push_back({-x,0});
			}
		}
	}
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
