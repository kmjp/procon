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

int N,M,Q,L;
vector<pair<int,int>> E[202020];

ll D[303030][33];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q>>L;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x].push_back({y,r-1});
		E[y].push_back({x,r-1});
	}
	
	FOR(x,N+1) FOR(y,31) D[x][y]=1LL<<60;
	D[1][0]=1;
	priority_queue<pair<ll,int>> q;
	q.push({-1,1*100});
	while(q.size()) {
		ll co=-q.top().first;
		int cur=q.top().second/100;
		int id=q.top().second%100;
		q.pop();
		
		if(id>=30||D[cur][id]!=co) continue;
		FORR2(e,c,E[cur]) {
			if(D[e][id+c]>co+(1<<id)) {
				D[e][id+c]=co+(1<<id);
				q.push({-D[e][id+c],e*100+id+c});
			}
		}
	}
	
	FOR(j,Q) {
		cin>>x;
		ll mi=1LL<<60;
		FOR(i,30) mi=min(mi,D[x][i]);
		if(mi>L) {
			cout<<"Large"<<endl;
		}
		else {
			cout<<mi<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
