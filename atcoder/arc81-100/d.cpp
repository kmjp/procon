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
string S[2];

ll from[3][3],to[3][3];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>S[0]>>S[1];
	
	if(S[0][0]==S[1][0]) {
		from[0][0]=from[1][1]=from[2][2]=1;
	}
	else {
		from[0][1]=from[0][2]=from[1][0]=from[1][2]=from[2][0]=from[2][1]=1;
	}
	
	int a1,b1,a2,b2;
	for(i=1;i<N;i++) {
		ZERO(to);
		FOR(a1,3) FOR(b1,3) FOR(a2,3) FOR(b2,3) {
			if((S[0][i-1]==S[0][i]) != (a1==a2)) continue;
			if((S[1][i-1]==S[1][i]) != (b1==b2)) continue;
			if((S[0][i]==S[1][i]) != (a2==b2)) continue;
			(to[a2][b2]+=from[a1][b1])%=mo;
		}
		
		swap(from,to);
	}
	
	ll tot=0;
	FOR(x,3) FOR(y,3) tot+=from[x][y];
	cout<<tot%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
