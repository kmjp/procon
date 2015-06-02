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

ll N,K;
ll pat[100];

ll lower(ll v,ll T,int m) {
	if(v==0) return 0;
	ll p=v/(T/K), r=v%(T/K);
	if(p>=K/2) return (p-(K/2))*pat[m-1] + lower(r,T/K,m-1);
	return 0;
}

ll upper(ll v,ll T,int m) {
	if(v==0) return 0;
	ll p=v/(T/K), r=v%(T/K);
	ll ret=min(p,(K+1)/2)*pat[m-1];
	if(p<(K+1)/2) ret += upper(r,T/K,m-1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(N==1) return _P("1\n");
	
	int m=0;
	ll T=1;
	pat[0]=1;
	while(T*K<=N) T*=K, pat[m+1]=pat[m]*((K+1)/2), m++;
	cout<<upper(T-(N-T)/(K-1),T,m) + lower((N-T)/(K-1),T,m)*((K+1)/2)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
