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

int T;
int H,W,N;
ll A,B,G;
ll HH[10101];
ll S[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>H>>W>>A>>B>>G;
		N=H*W;
		FOR(x,N) cin>>HH[x];
		sort(HH,HH+N);
		FOR(x,N) S[x+1]=S[x]+HH[x];
		
		ll ret=1LL<<60;
		for(i=-100000;i<=100000;i++) {
			j=lower_bound(HH,HH+N,i)-HH;
			ll pl=(S[N]-S[j])-1LL*i*(N-j);
			ll mi=1LL*i*j-(S[j]-S[0]);
			ll tot=0;
			if(A+B>G) {
				ll a=min(pl,mi);
				tot += G*a;
				pl-=a;
				mi-=a;
			}
			tot += A*mi+B*pl;
			ret=min(ret,tot);
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
