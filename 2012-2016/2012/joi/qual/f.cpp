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

int M,L;
string A,B,S;
ll memo[551][11][3][3][551];
ll mo=10000;

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}

ll dfs(int d,int pre,int up,int top,int m) {
	if(d==L) return m==0;
	if(memo[d][pre][up][top][m]>=0) return memo[d][pre][up][top][m];
	
	ll ret=0;
	
	int i;
	if(top) {
		FOR(i,S[d]-'0'+1) {
			if(up && i<=pre) continue;
			if(!up && i>=pre) continue;
			ret += dfs(d+1,i,!up,(i==S[d]-'0'),(m*10+i)%M);
		}
	}
	else {
		FOR(i,10) {
			if(up && i<=pre) continue;
			if(!up && i>=pre) continue;
			ret += dfs(d+1,i,!up,0,(m*10+i)%M);
		}
	}
	
	return memo[d][pre][up][top][m]=ret%mo;
}

ll hoge(string s) {
	S=s;
	L=S.size();
	ll ret=0;
	int i,j;
	
	if(L==1) {
		for(i=1;i<=S[0]-'0';i++) if(i%M==0) ret++;
		return ret;
	}
	
	MINUS(memo);
	for(i=1;i<S[0]-'0';i++) ret+=dfs(1,i,0,0,i%M)+dfs(1,i,1,0,i%M);
	ret+=dfs(1,S[0]-'0',0,1,(S[0]-'0')%M)+dfs(1,S[0]-'0',1,1,(S[0]-'0')%M);
	for(i=1;i<L;i++) {
		for(j=1;j<=9;j++) {
			ret+=dfs(i+1,j,0,0,j%M);
			if(i!=L-1) ret+=dfs(i+1,j,1,0,j%M);
		}
	}
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>M;
	ll ret=hoge(B);
	ret+=mo-hoge(decdec(A));
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
