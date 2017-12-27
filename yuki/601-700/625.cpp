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

int N,M;
int P[1010][1010];

int R[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	MINUS(P);
	if(N==1) return _P("%d\n",M);
	if(N==2) return _P("-1 %d\n",M);
	if(N==3) return _P("%d 0 0\n",M);
	P[3][0]=P[3][1]=0;
	P[3][2]=M;
	for(i=4;i<=N;i++) {
		vector<pair<int,int>> cand;
		FOR(j,i-1) cand.push_back({P[i-1][j],j});
		sort(ALL(cand));
		FOR(j,i-1) P[i][j]=0;
		int left=M;
		FOR(j,i/2) {
			x=cand[j].second;
			P[i][x]=P[i-1][x]+1;
			left-=P[i][x];
		}
		P[i][i-1]=left;
		if(P[i][i-1]<0) break;
	}
	
	x=N;
	while(P[x][x-1]<0) x--;
	
	FOR(i,N) _P("%d%c",P[x][N-1-i],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
