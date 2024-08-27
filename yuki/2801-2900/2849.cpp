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

const int MA=202020;
ll tot[MA+1];
ll S[MA+1];
int T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=MA;i++) tot[i]=i;
	for(i=2;i<=MA;i++) if(tot[i]==i) {
		for(j=i;j<=MA;j+=i) tot[j]=tot[j]/i*(i-1);
	}
	tot[1]=0;
	for(i=1;i<=MA;i++) S[i]=S[i-1]+tot[i];
	
	
	cin>>T;
	ll ret=0;
	while(T--) {
		ll L,R;
		cin>>L>>R;
		L^=ret;
		R^=ret;
		ret=0;
		for(i=1;i<=500;i++) {
			if((L-1)/i!=R/i) ret+=tot[i];
		}
		int pre=500;
		for(i=500;i>=1;i--) {
			int mi=(L+(i-1))/i;
			int ma=R/i;
			if(ma>pre) {
				mi=max(mi,pre+1);
				if(mi<=ma) ret+=S[ma]-S[mi-1];
				pre=ma;
			}
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
