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
int S[5050][5050];
int A[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>y>>x>>r;
		x--,y--;
		S[y+r][x]=max(S[y+r][x],r+1);
	}
	for(y=N-1;y>=0;y--) {
		FOR(x,N) S[y][x]=max(S[y][x],S[y+1][x]-1);
	}
	int num=0;
	FOR(y,N) {
		FOR(x,N) {
			if(x) S[y][x]=max(S[y][x],S[y][x-1]-1);
			if(S[y][x]) num++;
		}
	}
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
