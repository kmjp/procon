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

int N;
int A[303],S;
ll mo=998244353;

ll from[300*301][2];
ll to[300*301][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	from[0][0]=from[0][1]=1;
	ll ret=1;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		ret=ret*3%mo;
		ZERO(to);
		FOR(j,300*301) {
			if(from[j][0]) {
				// add
				(to[j+A[i]][0]+=from[j][0])%=mo;
				// non
				(to[j][0]+=from[j][0])%=mo;
			}
			if(from[j][1]) {
				// add
				(to[j+A[i]][1]+=from[j][1])%=mo;
				// non
				(to[j][1]+=2*from[j][1])%=mo;
			}
		}
		swap(from,to);
	}
	
	
	for(i=0;i<=S;i++) {
		if(i*2>=S) {
			ret-=from[i][1]*3;
		}
		if(i*2==S) {
			ret+=from[i][0]*3;
		}
		ret%=mo;
	}
	cout<<(ret+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
