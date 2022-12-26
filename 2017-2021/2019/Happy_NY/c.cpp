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
ll N,P;

ll loglog(ll a,ll v) {
	ll ret=0;
	while(v>=a) {
		ret+=v/a;
		v/=a;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>P;
		if(N<P) {
			cout<<-1<<endl;
		}
		else if(N%P!=P-1) {
			cout<<(N%P)+1<<endl;
		}
		else {
			ll M=N/2;
			if(loglog(P,N)<=loglog(P,M)+loglog(P,N-M)) {
				cout<<-1<<endl;
			}
			else {
				for(i=59;i>=0;i--) if(M>=1LL<<i) {
					if(loglog(P,N)>loglog(P,M-(1LL<<i))+loglog(P,N-(M-(1LL<<i)))) M-=1LL<<i;
				}
				
				cout<<M<<endl;
			}
			
			
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
