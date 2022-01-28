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

int T,N;
int P[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>x;
			P[x]=i;
		}
		set<pair<int,int>> up,down;
		up.insert({-1,-1});
		up.insert({N,N});
		down.insert({-1,N});
		int ma=1;
		for(i=N;i>=1;i--) {
			x=P[i];
			auto it=down.lower_bound({x+1,x+1});
			it--;
			auto p=*it;
			down.erase(p);
			
			if(p.first<x) down.insert({p.first,x-1});
			if(p.second>x) down.insert({x+1,p.second});
			
			
			up.insert({x,x});
			it=up.lower_bound({x,x});
			if(next(it)->first==x+1) {
				p=*next(it);
				p.first=x;
				up.erase(next(it));
				up.erase({x,x});
				up.insert(p);
			}
			
			it=up.lower_bound({x,x});
			if(prev(it)->second==x-1) {
				y=it->second;
				p=*prev(it);
				up.erase(it);
				up.erase(p);
				p.second=y;
				up.insert(p);
			}
			
			x=up.size();
			if(up.begin()->second==-1) x--;
			if(up.rbegin()->first==N) x--;
			y=down.size();
			if(down.begin()->second==-1) y--;
			if(down.rbegin()->first==N) y--;
			
			ma=max(ma,x+y);
		}
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
