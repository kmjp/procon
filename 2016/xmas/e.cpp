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

int T=200;
int N=50,M=30;
int A[50][50];
int P[50];
int PA[50];
int hit[50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(T--) {
		ZERO(hit);
		FOR(y,M) FOR(x,N) cin>>A[y][x];
		FOR(y,N) {
			int ans[4]={};
			FOR(x,M) ans[A[x][y]]++;
			pair<int,int> ans2[4];
			FOR(i,4) ans2[i]={ans[i],i};
			sort(ans2,ans2+4);
			PA[y]=ans2[3].second;
			FOR(x,M) if(PA[y]==A[x][y]) hit[x]++;
		}
		
		pair<int,int> player[51];
		FOR(i,M) player[i]={-hit[i],i};
		sort(player,player+M);
		FOR(y,N) {
			pair<int,int> prob[4]={};
			FOR(x,M/3) prob[A[player[x].second][y]].first++;
			FOR(x,4) prob[x].second=x;
			sort(prob,prob+4);
			_P("%d%c",prob[3].second,(y==N-1)?'\n':' ');
			
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
