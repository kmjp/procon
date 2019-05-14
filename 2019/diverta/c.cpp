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
int pat[5];
// B*A
// B**
// **A

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ret=0;
	FOR(i,N) {
		cin>>s;
		if(s[0]=='B' && s.back()=='A') pat[0]++;
		else if(s[0]=='B') pat[1]++;
		else if(s.back()=='A') pat[2]++;
		FOR(j,s.size()-1) if(s[j]=='A' && s[j+1]=='B') ret++;
	}
	
	while(pat[2]&&pat[0]) {
		pat[0]--;
		ret++;
	}
	while(pat[0]&&pat[1]) {
		pat[0]--;
		ret++;
	}
	ret+=min(pat[1],pat[2]);
	ret+=max(0,pat[0]-1);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
