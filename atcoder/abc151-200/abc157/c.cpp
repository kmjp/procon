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

int N,M;
int S[10],C[10];
int p10[5];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	p10[1]=10;
	p10[2]=100;
	p10[3]=1000;
	p10[4]=10000;
	
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>S[i]>>C[i];
		S[i]=N-S[i];
	}
	for(i=(N==1?0:p10[N-1]);i<p10[N];i++) {
		int ng=0;
		FOR(j,M) if(i/p10[S[j]]%10!=C[j]) ng++;
		if(ng==0) return _P("%d\n",i);
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
