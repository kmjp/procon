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

int N,Q;
string S;
int nex[505050][28];
int nexd[505050][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) c-='a';
	N=S.size();
	FOR(i,27) nex[N][i]=nex[N+1][i]=N+1;
	FOR(i,20) nexd[N][i]=nexd[N+1][i]=N+1;
	for(i=N-1;i>=0;i--) {
		nex[i][S[i]]=i+1;
		for(j=S[i]+1;j<=26;j++) nex[i][j]=nex[nex[i][j-1]][j-1];
		for(j=0;j<S[i];j++) nex[i][j]=nex[nex[i][26]][j];
		nexd[i][0]=nex[i][26];
		for(j=0;j<19;j++) nexd[i][j+1]=nexd[nexd[i][j]][j];
	}
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		for(i=19;i>=0;i--) if(nexd[L][i]<=R) L=nexd[L][i];
		if(L==R) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
