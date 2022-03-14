#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
unsigned long long X;

ll pat[4010101];
ll sum[4010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	sum[1]=pat[1]=1;
	int sq=1;
	for(i=2;i<=3000000;i++) {
		if((sq+1)*(sq+1)<=i) sq++;
		pat[i]=sum[sq];
		sum[i]=sum[i-1]+pat[i];
	}
	
	
	cin>>T;
	while(T--) {
		cin>>X;
		unsigned long long sq=0;
		while((sq+10000)*(sq+10000)<=X) sq+=10000;
		while((sq+1)*(sq+1)<=X) sq++;
		
		ll ret=0;
		for(ll a=1;a<=3000000;a++) {
			if(a*a<=sq) ret+=(sq-a*a+1)*pat[a];
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
