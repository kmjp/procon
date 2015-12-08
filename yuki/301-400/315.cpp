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

string A,B;
ll P;
ll mo=1000000007;
ll p10[202020];
ll memo[202020][3][2];

ll dfs(string& S,int d,int m,int lead) {
	if(d>=S.size()) return (m==0);
	if(memo[d][m][lead]>=0) return memo[d][m][lead];
	ll ret=0;
	int i;
	
	if(lead==1) {
		FOR(i,S[d]-'0') {
			if(i==3) ret+=p10[S.size()-1-d];
			else ret += dfs(S,d+1,(m+i)%3,0);
		}
		if(S[d]=='3') {
			ll pat=0;
			for(i=d+1;i<=S.size()-1;i++) pat=(pat*10+(S[i]-'0'))%mo;
			ret += pat+1;
		}
		else {
			ret += dfs(S,d+1,(m+S[d]-'0')%3,1);
		}
	}
	else {
		FOR(i,10) {
			if(i==3) ret += p10[S.size()-1-d];
			else ret += dfs(S,d+1,(m+i)%3,0);
		}
	}
	return memo[d][m][lead]=ret%mo;
}

string decdec(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r--!='0') break;
		r='9';
	}
	if(A.back()=='0') A.resize(A.size()-1);
	reverse(A.begin(),A.end());
	return A;
}


int greed(int v,int p) {
	int ret=0;
	for(int i=1;i<=v;i++) {
		if(i%p==0) continue;
		int j=i;
		while(j) {
			if(j%10==3) break;
			j/=10;
		}
		if(j||(i%3==0)) ret++;
	}
	return ret;
}

ll hoge(string S,ll P) {
	ll dp[2][3]={},t[2]={};
	if(S.size()<=5) return greed(atol(S.c_str()),P);
	
	ll ret=0;
	int low=atol(S.substr(S.size()-5).c_str());
	int i,j;
	S=S.substr(0,S.size()-5);
	FOR(j,2) {
		MINUS(memo);
		FOR(i,3) dp[j][i]=dfs(S,0,i,1);
		FORR(r,S) t[j]=(t[j]*10+r-'0')%mo;
		t[j]++;
		S=decdec(S);
	}
	
	FOR(i,100000) {
		int v=i;
		if(i%P==0) continue;
		while(v) {
			if(v%10==3) break;
			v/=10;
		}
		if(v) ret+=t[(i>low)];
		else ret += dp[(i>low)][i%3];
	}
	
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,202000) p10[i+1]=p10[i]*10%mo;
	
	cin>>A>>B>>P;
	A=decdec(A);
	cout<<((hoge(B,P)+mo-hoge(A,P))%mo)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
