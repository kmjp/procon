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
vector<string> S;
int ret;
int R[501],C[501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(y,N) {
		cin>>s;
		S.push_back(s);
		FOR(x,N) if(S[y][x]=='#') R[y]++, C[x]++;
	}
	
	if(count(R,R+N,0)==N) return _P("-1\n");
	
	int mi=101010;
	FOR(y,N) {
		int num=0;
		int add=0;
		FOR(x,N) if(S[y][x]=='.') num++;
		FOR(i,N) if(S[i][y]=='#') add=1;
		if(num && add==0) num++;
		FOR(x,N) if(C[x]!=N) num++;
		mi=min(mi,num);
	}
	
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
