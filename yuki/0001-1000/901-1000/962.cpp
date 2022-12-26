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
string S[202020];
ll ret=0;
ll sum[202020];

void dfs(int cur,int L,int R) {
	if(L>=R) return;
	int pre=L;
	int i;
	for(i=L;i<R;i++) {
		if(S[i].size()<=cur) {
			dfs(cur+1,pre,i);
			pre=i+1;
		}
		else {
			if(S[i][cur]!=S[pre][cur]) {
				dfs(cur+1,pre,i);
				pre=i;
			}
			ret+=sum[i-pre+1];
		}
	}
	dfs(cur+1,pre,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	for(i=1;i<=200000;i++) sum[i]=sum[i-1]+i;
	
	dfs(0,0,N);
	cout<<ret<<endl;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
