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
ll L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		ll ret=0;
		
		if(R>=L*2) {
			ret+=R/2-L+1;
			
			for(i=1;i<=min(50000LL,L-1);i++) {
				ll ma=R/i;
				ll mi=(L+i-1)/i;
				if(mi<ma) ret++;
			}
			ll pre=50000;
			for(i=50000;i>=2;i--) {
				ll CR=min(L-1,R/i);
				ll CL=max(pre+1,(L+(i-2))/(i-1));
				if(CL<=CR) {
					ret+=CR-CL+1;
					pre=CR;
				}
			}
		}
		else {
			for(i=1;i<=50000;i++) {
				ll ma=R/i;
				ll mi=(L+i-1)/i;
				if(mi<ma) ret++;
			}
			ll pre=50000;
			for(i=50000;i>=2;i--) {
				ll CR=R/i;
				ll CL=max(pre+1,(L+(i-2))/(i-1));
				if(CL<=CR) {
					ret+=CR-CL+1;
					pre=CR;
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
