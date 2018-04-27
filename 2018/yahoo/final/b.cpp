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

ll K;
string S[101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(y,100) S[y]=string(100,'#');
	FOR(i,40) {
		if(K%3>=1) for(j=i*2;j<100;j++) S[i*2][j]='.';
		if(K%3>=2) for(j=i*2;j<100;j++) S[j][i*2]='.';
		S[i*2][i*2]=S[i*2][i*2+1]=S[i*2][i*2+2]='.';
		S[i*2+1][i*2]=S[i*2+1][i*2+1]=S[i*2+1][i*2+2]='.';
		S[i*2+2][i*2]=S[i*2+2][i*2+2]='.';
		K/=3;
	}
	
	FOR(x,100) S[99][x]=S[x][99]='.';
	
	cout<<"100 100"<<endl;
	FOR(y,100) cout<<S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
