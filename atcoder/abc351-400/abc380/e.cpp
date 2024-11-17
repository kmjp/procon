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

int N,Q;

set<pair<int,int>> S;
int C[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=0;i<=N+1;i++) {
		C[i]=1;
		S.insert({i,i});
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			auto it=S.lower_bound({x+1,0});
			auto p=*it;
			auto q=*--it;
			S.erase(it);
			C[q.second]-=p.first-q.first;
			q.second=y;
			C[q.second]+=p.first-q.first;
			S.insert(q);
			it=S.find(q);
			
			if(next(it)->second==y) {
				S.erase(next(it));
			}
			it=S.find(q);
			if(prev(it)->second==y) {
				S.erase(it);
			}
		}
		else {
			cin>>x;
			cout<<C[x]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
