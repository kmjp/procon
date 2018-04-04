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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int okok(int v) {
	int num=0;
	int type=0;
	
	for(int i=0;prime[i]*prime[i]<=v;i++) {
		if(v%prime[i]==0) {
			type++;
			while(v%prime[i]==0) num++, v/=prime[i];
		}
	}
	if(v>1) num++,type++;
	return ((type==2&&num==2) || (type==1&&num==3));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	int ok=0;
	vector<int> C;
	C.push_back(0);
	i=1;
	while(C.size()<=1000002) {
		if(okok(i)) C.push_back(i);
		i++;
	}
	
	cin>>N;
	cout<<C[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
