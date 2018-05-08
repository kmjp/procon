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

int B[10];
string S;
ll p10[20];
int A;
ll ret;

void dfs(int cur) {
	
	if(cur>=S.size()) return;
	for(int i=0;i<S[cur]-'0';i++) if(B[i]==0) {
		ret+=p10[S.size()-cur-1];
	}
	
	if(B[S[cur]-'0']) return;
	dfs(cur+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) {
		cin>>B[i];
		A+=B[i]==0;
	}
	cin>>S;
	
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*A;
	
	for(i=1;i<S.size();i++) {
		ret+=(A-(B[0]==0))*p10[i-1];
	}
	if(B[0]==0) ret++;
	int last=0;
	for(i=1;i<S[0]-'0';i++) if(B[i]==0) {
		last=i;
		ret+=p10[S.size()-1];
	}
	if(B[S[0]-'0']==0) dfs(1);
	
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
