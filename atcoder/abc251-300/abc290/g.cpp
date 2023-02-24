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
ll D,K;
ll X;
ll P[62],S[62];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>D>>K>>X;
		P[0]=S[0]=1;
		FOR(i,D) {
			P[i+1]=P[i]*K;
			S[i+1]=1+S[i]*K;
		}
		
		ll mi=1LL<<60;
		
		for(i=0;i<=D;i++) {
			if(S[i]>=X) {
				ll ret=0;
				if(i!=D) ret++;
				ll V=X;
				for(x=i;x>0&&V;x--) {
					V--;
					ll rem=S[x-1]*K-V;
					ret+=rem/S[x-1];
					V%=S[x-1];
				}
				mi=min(mi,ret);
			}
		}
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
