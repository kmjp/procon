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

ll X,Y,Z;
string S[2];
ll A[2];
ll D[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z;
	cin>>S[0]>>A[0];
	cin>>S[1]>>A[1];
	
	FOR(i,8) FOR(j,8) if(i!=j) D[i][j]=1LL<<60;
	D[0][1]=D[1][0]=X-1;
	D[2][3]=D[3][2]=Y-1;
	D[4][5]=D[5][4]=Z-1;
	D[0][2]=D[2][0]=1;
	D[0][4]=D[4][0]=1;
	D[2][4]=D[4][2]=1;
	D[1][3]=D[3][1]=1;
	D[1][5]=D[5][1]=1;
	D[3][5]=D[5][3]=1;
	
	FOR(i,2) {
		if(S[i]=="A") {
			D[6+i][0]=D[0][6+i]=A[i]-1;
			D[6+i][1]=D[1][6+i]=X-A[i];
		}
		if(S[i]=="B") {
			D[6+i][2]=D[2][6+i]=A[i]-1;
			D[6+i][3]=D[3][6+i]=Y-A[i];
		}
		if(S[i]=="C") {
			D[6+i][4]=D[4][6+i]=A[i]-1;
			D[6+i][5]=D[5][6+i]=Z-A[i];
		}
	}
	if(S[0]==S[1]) D[6][7]=D[7][6]=abs(A[1]-A[0]);
	FOR(k,8) FOR(i,8) FOR(j,8) D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
	cout<<D[6][7]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
