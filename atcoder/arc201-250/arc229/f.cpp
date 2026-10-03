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

int T,N;
ll C[202020];
ll S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>C[i];
		sort(C,C+N);
		FOR(i,N) S[i+1]=S[i]+C[i];
		
		ll ret=0;
		if(N==2) {
			ret=C[0]*2;
		}
		else if(N==3) {
			ret=C[0]*3+C[1];
		}
		else {
			ret=1LL<<60;
			for(i=1;i<N;i++) {
				int lef=N-1-i;
				if(i*2<=lef) {
					ll up=S[i]*2+(lef-i*2)*C[0];
					ll down=S[N-1]-S[N-1-lef];
					ret=min(ret,up+down);
				}
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
