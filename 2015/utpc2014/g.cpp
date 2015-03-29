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

int N,X,P;
ll mo=1000000007;
map<int,ll> memo[52][11][55];
int A[55],F;
int p3[15];

const int CN=201;
ll C[CN][CN];

ll dfs(int cur,int mask,int pre,int fr) {
	int i,n;
	
	if((mask / p3[X])>1) return 0;
	if(memo[cur][pre][fr].count(mask)) return memo[cur][pre][fr][mask];
	if(cur==N) return (mask / p3[X])==1;
	ll ret = 0;
	
	if(A[cur]!=100) {
		int nmask=0;
		FOR(i,X+1) {
			int keep=(mask/p3[i])%3;
			int take=(i-A[cur]<0)?0:((mask/p3[i-A[cur]])%3);
			nmask += min(keep+take,2)*p3[i];
		}
		ret += dfs(cur+1,nmask,1,fr);
	}
	else {
		for(n=pre;n<=P;n++) {
			int nmask=0;
			FOR(i,X+1) {
				int keep=(mask/p3[i])%3;
				int take=(i-n<0)?0:((mask/p3[i-n])%3);
				nmask += min(keep+take,2)*p3[i];
			}
			if(n==pre) ret += dfs(cur+1,nmask,n,fr);
			else ret += dfs(cur+1,nmask,n,N-cur)*C[fr][N-cur] % mo;
		}
	}
	
	return memo[cur][pre][fr][mask] = ret%mo;
}



void solve() {
	int i,j,k,l,r,x,y,t; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	p3[0]=1;
	FOR(i,12) p3[i+1]=p3[i]*3;
	
	cin>>N>>X>>P;
	
	FOR(i,N) {
		cin>>s;
		if(s=="0") {
			cout<<0<<endl;
			return;
		}
		if(s=="?") A[i]=100, F++;
		else A[i] = atoi(s.c_str());
	}
	sort(A,A+N);
	
	cout<<dfs(0,1,1,F)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
