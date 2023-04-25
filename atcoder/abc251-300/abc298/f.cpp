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
map<ll,ll> R;
set<pair<ll,ll>> CM;
map<ll,ll> C;
map<ll,vector<pair<int,int>>> Rs;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>y>>x>>k;
		R[y]+=k;
		C[x]+=k;
		Rs[y].push_back({x,k});
	}
	FORR2(a,b,C) CM.insert({b,a});
	ll ma=0;
	FORR2(r,s,R) {
		FORR2(a,b,Rs[r]) {
			CM.erase({C[a],a});
			CM.insert({C[a]-b,a});
		}
		ll v=CM.rbegin()->first;
		ma=max(ma,v+s);
		
		FORR2(a,b,Rs[r]) {
			CM.erase({C[a]-b,a});
			CM.insert({C[a],a});
		}
		
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
