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
ll L,A;

int ok(ll L,ll A) {
	int a2,a3,a5;
	if(L==0) return 0;
	if(L>=1 && A==0) return 1;
	for(a2=0;a2<=1;a2++) {
		for(a3=0;a3<=4;a3++) {
			for(a5=0;a5<=1;a5++) {
				int a4;
				if(L-(a2*3+a3*4+a5*6)<-1) continue;
				a4=(L-(a2*3+a3*4+a5*6)+1)/5;
				
				int TA=A-a2-2*a4;
				if(TA<0) return 1;
				if(TA<=20) {
					int a=pow(3,a3)*pow(5,a5)+0.1;
					int b=pow(2,TA)+0.1;
					if(a>=b) return 1;
				}
			}
		}
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>A;
		ll ret=(1<<30)-1;
		for(i=29;i>=0;i--) if(ok(ret-(1<<i),A)) ret-=1<<i;
		cout<<max(0LL,L-ret+1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
