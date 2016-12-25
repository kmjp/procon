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

ll A,B;
vector<ll> V;
ll mat[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	V.push_back(0);
	V.push_back(A);
	V.push_back(-A);
	V.push_back(B);
	V.push_back(-B);
	sort(ALL(V));
	
	FOR(i,5) FOR(j,5) mat[i][j]=(i!=j)*1LL<<60;
	FOR(y,5) FOR(x,5) {
		if(V[y]>V[x]) mat[x][y]=min(mat[x][y],V[y]-V[x]);
		if(V[y]==-V[x]) mat[x][y]=min(mat[x][y],1LL);
	}
	
	FOR(k,5) FOR(i,5) FOR(j,5) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	
	FOR(i,5) FOR(j,5) if(V[i]==A && V[j]==B) {
		cout<<mat[i][j]<<endl;
		return;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
