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
string S;
int did[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	queue<int> Q;
	FOR(i,N-2) if(S.substr(i,3)=="RGB") Q.push(i);
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(x<0||x>N-2 || did[x]) continue;
		
		if(S[x]!='*' && S[x]!='R') continue;
		if(S[x+1]!='*' && S[x+1]!='G') continue;
		if(S[x+2]!='*' && S[x+2]!='B') continue;
		did[x]=1;
		S[x]=S[x+1]=S[x+2]='*';
		Q.push(x-2);
		Q.push(x-1);
		Q.push(x+1);
		Q.push(x+2);
	}
	
	if(count(ALL(S),'*')!=N) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
