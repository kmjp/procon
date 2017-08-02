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

int H,W,Q;
string S[1010];
int C[1010][1010][3];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			FOR(i,3) C[y+1][x+1][i]=C[y][x+1][i]+C[y+1][x][i]-C[y][x][i];
			if(S[y][x]=='J') C[y+1][x+1][0]++;
			if(S[y][x]=='O') C[y+1][x+1][1]++;
			if(S[y][x]=='I') C[y+1][x+1][2]++;
		}
	}
	while(Q--) {
		int X1,Y1,X2,Y2;
		cin>>Y1>>X1>>Y2>>X2;
		X1--,Y1--;
		FOR(i,3) {
			cout<<C[Y2][X2][i]-C[Y1][X2][i]-C[Y2][X1][i]+C[Y1][X1][i];
			if(i==2) cout<<endl;
			else cout<<" ";
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
