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

string S,T;
int N;
ll mo=998244353;
int memo[10100][10100];

const int NUM_=1000005;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
int base;

ll dfs(int same,int dif) {
	if(dif==0) {
		ll c=fact[base]*factr[same]%mo*factr[base-same]%mo;
		return fact[same]*fact[same]%mo*c%mo;
	}
	if(memo[same][dif]==-1) {
		ll ret=0;
		if(same) (ret+=dif*same*dfs(same-1,dif))%=mo;
		(ret+=dif*dif*dfs(same,dif-1))%=mo;
		memo[same][dif]=ret;
	}
	return memo[same][dif];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	int same=0,dif=0;
	FOR(i,N) if(S[i]=='1') {
		if(T[i]=='1') same++;
		else dif++;
	}
	base=same+dif;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	MINUS(memo);
	cout<<dfs(same,dif)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
