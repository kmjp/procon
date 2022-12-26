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
string T;
ll from[3030],to[3030];
ll S[3030];

ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>T;
	
	FOR(i,N) from[i]=1;
	
	FOR(i,N-1) {
		ZERO(to);
		FOR(x,N+1) S[x]=((x?S[x-1]:0)+from[x])%mo;
		FOR(x,N-1-i) {
			if(T[i]=='>') to[x]=(S[N]+mo-S[x])%mo;
			else to[x]=S[x];

		}
		swap(from,to);
	}
	cout<<from[0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
