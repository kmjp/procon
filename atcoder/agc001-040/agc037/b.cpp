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
string S;
ll mo=998244353;

ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	ll ret=1;
	ll V[3]={},D[3]={};
	
	queue<int> Q;
	FORR(c,S) {
		if(c=='R') i=0;
		if(c=='G') i=1;
		if(c=='B') i=2;
		
		// close
		x=(i+1)%3;
		y=(i+2)%3;
		if(D[i]) {
			(ret*=D[i])%=mo;
			D[i]--;
		}
		else if(V[x]) {
			(ret*=V[x])%=mo;
			D[y]++;
			V[x]--;
		}
		else if(V[y]) {
			(ret*=V[y])%=mo;
			D[x]++;
			V[y]--;
		}
		else {
			V[i]++;
		}
		//cout<<c<<" "<<V[0]<<" "<<V[1]<<" "<<V[2]<<" "<<D[0]<<" "<<D[1]<<" "<<D[2]<<" "<<ret<<endl;
	}
	
	FOR(i,N) ret=ret*(i+1)%mo;
	
	
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
