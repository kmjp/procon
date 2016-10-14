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

const int prime_max = 200000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		divp[i]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int T;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	
	cin>>T;
	while(T--) {
		cin>>S;
		ll ret=0;
		
		multiset<int> M;
		
		for(i=0;i<S.size();i++) {
			
			x = 1;
			FORR(r,M) {
				x=x*r%9;
				if(x==0) break;
			}
			if(x==0) x=9;
			ret += (S[i]-'0')*x;
			
			if(i<S.size()-1) {
				x = S.size()-1-i;
				y = 1+i;
				while(divp[x]) M.insert(divp[x]), x /= divp[x];
				while(divp[y]) M.erase(M.find(divp[y])), y /= divp[y];
			}
		}
		while(ret>=10) ret=ret%10+ret/10;
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
