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

ll B;
int N;
ll C[20];
ll sum;
ll ret[140000];

ll step(ll tar) {
	ll ov=0,fl=0;
	int j;
	if(tar<0) return 1LL<<60;
	FOR(j,N) if(C[j]>tar) ov += C[j]-tar;
	FOR(j,N) if(C[j]<tar) fl += tar-C[j];
	if(fl<=ov+B) return ov+fl;
	return 1LL<<60;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B>>N;
	ll sum=B;
	FOR(i,N) cin>>C[i], sum+=C[i];
	
	for(i=0;i<=10000;i++) ret[i]=step(i*100000);
	
	ll L=0,R=0;
	for(i=0;i<=10000;i++) {
		if(ret[L]>ret[i]) L=i;
		if(ret[R]>=ret[i]) R=i;
	}
	ll M=(L+R)*100000/2;
	ll mi=1LL<<60;
	for(ll i=M-2000000;i<=M+2000000;i++) mi=min(mi,step(i));
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
