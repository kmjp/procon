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
int P[202020],R[202020];
set<pair<int,int>> alive;
set<pair<int,int>> pos;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		alive.insert({i,P[i]});
		pos.insert({P[i],i});
	}
	
	vector<int> ret;
	while(pos.size()) {
		x=pos.begin()->second;
		auto it=alive.lower_bound({x,0});
		if(next(it)==alive.end()) {
			x=next(pos.begin())->second;
			it=alive.lower_bound({x,0});
		}
		x=it->first;
		y=next(it)->first;
		cout<<P[x]<<" "<<P[y]<<" ";
		alive.erase({x,P[x]});
		alive.erase({y,P[y]});
		pos.erase({P[x],x});
		pos.erase({P[y],y});
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
