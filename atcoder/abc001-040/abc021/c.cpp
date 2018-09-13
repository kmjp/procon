#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,A,B,M;
int mat[101][101];
int mat2[101][101];
vector<int> D[101];
ll num[101];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	A--,B--;
	FOR(x,N) FOR(y,N) mat[x][y]=1<<20;
	FOR(x,N) mat[x][x]=0;
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
	}
	
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	
	FOR(i,N) if(mat[A][i]<101) D[mat[A][i]].push_back(i);
	
	num[A]=1;
	FOR(i,101) {
		FORR(r,D[i]) {
			FOR(x,N) if(mat[A][x]==i+1 && mat[r][x]==1) num[x]=(num[x]+num[r])%mo;
		}
	}
	cout<<num[B]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
