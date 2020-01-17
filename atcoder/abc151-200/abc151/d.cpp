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
string S[20];
int A[400][400];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(x,400) FOR(y,400) A[x][y]=(x==y)?0:101010;
	
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='.') {
			if(x&&S[y][x-1]=='.') A[y*20+x-1][y*20+x]=A[y*20+x][y*20+x-1]=1;
			if(y&&S[y-1][x]=='.') A[y*20+x-20][y*20+x]=A[y*20+x][y*20+x-20]=1;
		}
	}
	FOR(i,400) FOR(x,400) FOR(y,400) A[x][y]=min(A[x][y],A[x][i]+A[i][y]);
	int ma=0;
	FOR(y,400) FOR(x,400) if(A[x][y]<400) ma=max(ma,A[x][y]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
