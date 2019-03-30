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

int N;
string A[303030];
string M;

int L[90909][53];
int R[90909][53];
int ret[52][52][52];
int pat[52][52][52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0;
	FOR(i,N) {
		cin>>A[i];
		FORR(c,A[i]) {
			if(c>='A' && c<='Z') c-='A';
			else c=c-'a'+26;
		}
		FOR(j,52) FOR(x,A[i].size()+2) L[x][j]=R[x][j]=0;
		FOR(j,A[i].size()) {
			FOR(x,52) L[j+1][x]=L[j][x];
			L[j+1][A[i][j]]++;
		}
		for(j=A[i].size()-1;j>=0;j--) {
			FOR(x,52) R[j+1][x]=R[j+2][x];
			R[j+1][A[i][j]]++;
			FOR(x,52) FOR(y,52) if(L[j][x]&&R[j+2][y]) {
				if(pat[x][A[i][j]][y]==0) {
					pat[x][A[i][j]][y]=1;
					ret[x][A[i][j]][y]++;
					ma=max(ma,ret[x][A[i][j]][y]);
				}
			}
		}
		FOR(j,A[i].size()) {
			FOR(x,52) FOR(y,52) if(L[j][x]&&R[j+2][y]) pat[x][A[i][j]][y]=0;
		}
	}
	FOR(i,26) M+=(char)('A'+i);
	FOR(i,26) M+=(char)('a'+i);
	
	FOR(i,52) FOR(j,52) FOR(x,52) if(ret[i][j][x]==ma) {
		cout<<M[i]<<M[j]<<M[x]<<endl;
		return;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
