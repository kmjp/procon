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
string S[1010];
char mi='1';
unsigned long long dig=2;
unsigned long long  mimi=1ULL<<63;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	FOR(i,N) {
		cin>>S[i];
		unsigned long long ret=0;
		mi='1';
		
		FOR(j,S[i].size()) mi=max(mi,S[i][j]);
		
		if(isdigit(mi)) dig=mi-'0'+1;
		else dig=mi-'A'+10+1;
		
		FOR(j,S[i].size()) {
			ret = ret*dig + ((S[i][j]<='9')?(int)S[i][j]-'0':(S[i][j]-'A'+10));
		}
		mimi=min(mimi,ret);
	}
	cout<<mimi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
