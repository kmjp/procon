#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,T;
int D[2][101010];
int A[101010];
vector<pair<int,int>> E[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>x>>y>>j;
		E[0][x-1].push_back({y-1,j});
		E[1][y-1].push_back({x-1,j});
	} 
	
	memset(D,0x3f,sizeof(D));
	priority_queue<pair<int,int>> Q;
	D[0][0]=D[1][0]=0;
	Q.push({0,0});
	Q.push({0,1000000});
	while(Q.size()) {
		auto k=Q.top();
		Q.pop();
		int cur=k.second%1000000;
		int ph=k.second/1000000;
		int cost=-k.first;
		
		if(cost!=D[ph][cur]) continue;
		FORR(r,E[ph][cur]) if(D[ph][r.first]>cost+r.second) {
			D[ph][r.first]=cost+r.second;
			Q.push({-D[ph][r.first],ph*1000000+r.first});
		}
	}
	ll ma=0;
	FOR(i,N) if(D[0][i]+D[1][i]<T) ma=max(ma,(ll)(T-(D[0][i]+D[1][i]))*A[i]);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
