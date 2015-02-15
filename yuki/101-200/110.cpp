#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N[2];
int W[2][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N[0];
	FOR(i,N[0]) cin>>W[0][i];
	cin>>N[1];
	FOR(i,N[1]) cin>>W[1][i];
	sort(W[0],W[0]+N[0]);
	sort(W[1],W[1]+N[1]);
	
	int ma=0;
	FOR(k,2) {
		x=W[k][N[k]-1];
		y=1;
		i=k^1;
		while(1) {
			for(j=N[i]-1;j>=0;j--) {
				if(W[i][j]<x) break;
			}
			if(j<0) break;
			x=W[i][j];
			y++;
			i^=1;
		}
		ma=max(ma,y);
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
