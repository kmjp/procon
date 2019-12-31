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

int N;
string S;
int C[5050];
int isp[5050][5050];

ll co[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>C[i+1];
	
	for(l=1;l<=N;l++) {
		for(x=0;x+l-1<N;x++) {
			isp[x][l]=S[x]==S[x+(l-1)];
			if(l>=3) isp[x][l] &= isp[x+1][l-2];
		}
	}
	for(x=1;x<=N;x++) {
		co[x]=1<<30;
		for(l=1;l<=x;l++) if(isp[x-l][l]) co[x]=min(co[x],co[x-l]+C[l]);
	}
	cout<<co[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
