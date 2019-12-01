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
int A[101010];
int C[101010];

ll ret[101010];

int GCD(int x,int y) {
	if(x<y) swap(x,y);
	if(y==0) return x;
	int z=y;
	while(__builtin_clz(x)!=__builtin_clz(z)) z<<=1;
	
	return GCD(y,x^z);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	int g=0;
	FOR(i,N) {
		cin>>A[i];
		g=GCD(g,A[i]);
		C[A[i]]++;
		sum+=A[i];
	}
	ll mi=1LL<<60;
	for(i=1;i<=100000;i++) {
		ret[i]=sum;
		for(j=i;j<=100000;j+=i) {
			ret[i]-=1LL*C[j]*j;
			ret[i]+=1LL*C[j]*(j/i);
		}
		if(i%g==0) mi=min(mi,ret[i]);
	}
	for(int m=1;m<1<<17;m++) {
		ll t=0;
		FOR(i,17) if(m&(1<<i)) t^=(ll)g<<i;
		if(t<=100000) mi=min(mi,ret[t]);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
