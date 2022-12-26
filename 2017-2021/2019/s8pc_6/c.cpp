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

int H,W;
string S[101];
vector<vector<int>> M;
int ok[101][101];

vector<vector<int>> mult(vector<vector<int>> A,vector<vector<int>> B) {
	vector<vector<int>> C=A;
	int x,y,z;
	FOR(x,H) FOR(y,H) C[y][x]=0;
	FOR(y,H) FOR(z,H) FOR(x,H) if(A[y][z]&&B[z][x]) C[y][x]=1;
	return C;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) {
		ZERO(ok);
		ok[y][0]=1;
		if(S[y][0]=='#') ok[y][0]=0;
		int y2;
		FOR(y2,H) FOR(x,W) if(ok[y2][x]) {
			if(y2+1<H&&S[y2+1][x]=='.') ok[y2+1][x]=1;
			if(x+1<W&&S[y2][x+1]=='.') ok[y2][x+1]=1;
		}
		vector<int> V;
		FOR(y2,H) V.push_back(ok[y2][W-1]);
		M.push_back(V);
	}
	
	vector<vector<int>> A;
	FOR(y,H) {
		vector<int> V(H);
		V[y]=1;
		A.push_back(V);
	}
	
	FOR(i,30) {
		if(1000000000&(1<<i)) {
			A=mult(A,M);
		}
		M=mult(M,M);
	}
	if(M[0][H-1]) cout<<"Yay!"<<endl;
	else cout<<":("<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
