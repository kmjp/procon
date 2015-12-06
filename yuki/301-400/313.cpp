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

string S;
ll ret=0;
ll hoge=1187919047255;

const int prime_max = 3000000;
int NP,prime[300000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>S;
	S=S.substr(0,1)+S.substr(2,200000);
	for(i=1;i<=200001;i++) ret += (S[i-1]-'0')*1LL*prime[i+5];
	
	ll dif=(hoge-ret);
	
	for(i=1;i<=200001;i++) if(dif % prime[i+5]==0) break;
	cout<<S[i-1]<<" "<<(char)(S[i-1]+dif/prime[i+5])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
