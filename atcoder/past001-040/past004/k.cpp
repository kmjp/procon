#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K,Q,X;
int C[101010][22];
ll T[22];
ll R[101010];

const ll mo=1000000000;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			for(k=y+1;k<=20;k++) R[i]+=C[i][k];
			C[i][y]++;
		}
		R[i]%=mo;
	}
	
	ll ret=0;
	cin>>Q;
	while(Q--) {
		cin>>X;
		X--;
		(ret+=R[X])%=mo;
		FOR(i,21) {
			for(j=i+1;j<=20;j++) (ret+=T[j]*C[X][i])%=mo;
		}
		FOR(i,21) (T[i]+=C[X][i])%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
