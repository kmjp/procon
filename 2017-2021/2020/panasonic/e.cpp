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


string A[3];
int X,Y,Z;

int ok[3][4020];




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	
	int mi=1<<30;
	sort(A,A+3);
	do {
		int X=A[0].size();
		int Y=A[1].size();
		int Z=A[2].size();
		
		FOR(i,4010+1) {
			ok[0][i]=1;
			FOR(x,X) if(x>=i && x-i<Y && A[0][x]!='?' && A[1][x-i]!='?' && A[1][x-i]!=A[0][x]) ok[0][i]=0;
			ok[1][i]=1;
			FOR(x,X) if(x>=i && x-i<Z && A[0][x]!='?' && A[2][x-i]!='?' && A[2][x-i]!=A[0][x]) ok[1][i]=0;
			ok[2][i]=1;
			FOR(x,Y) if(x>=i && x-i<Z && A[1][x]!='?' && A[2][x-i]!='?' && A[2][x-i]!=A[1][x]) ok[2][i]=0;
		}
		FOR(x,2001) FOR(y,2001) {
			if(ok[0][x] && ok[1][x+y] && ok[2][y]) {
				mi=min(mi,max({X,x+Y,x+y+Z}));
			}
		}
		
		
		
		
	} while(next_permutation(A,A+3));
	
	cout<<mi<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
