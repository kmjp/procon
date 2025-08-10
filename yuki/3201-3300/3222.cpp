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
int P[101010],T[101010];
set<int> E[101010],E2[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
		E2[x-1].insert(y-1);
		E2[y-1].insert(x-1);
	}
	FOR(i,M) {
		cin>>x;
		T[x-1]=1;
	}
	priority_queue<pair<int,int>> PQ;
	queue<int> TQ;
	FOR(i,N) {
		if(T[i]==1) TQ.push(i);
		if(T[i]==0&&E[i].size()==1) PQ.push({P[i],i});
	}
	ll ret=0;
	FOR(i,N) {
		while(PQ.size()) {
			x=PQ.top().second;
			PQ.pop();
			if(T[x]) continue;
			ret+=P[x];
			y=*E[x].begin();
			E[y].erase(x);
			T[x]=-1;
			if(E[y].size()==1&&T[y]==0) PQ.push({P[y],y});
			break;
		}
		queue<int> NQ;
		while(TQ.size()) {
			x=TQ.front();
			TQ.pop();
			FORR(e,E2[x]) if(T[e]==0) {
				T[e]=1;
				NQ.push(e);
			}
			
		}
		TQ=NQ;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
