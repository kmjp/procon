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

int N,A[3],B[3];
vector<int> E[2020];


void dfs(int cur,int pre,int d,map<int,int>& M) {
	M[d]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1,M);
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>A[0]>>A[1]>>A[2];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	B[0]=-A[0]+A[1]+A[2];
	B[1]=A[0]-A[1]+A[2];
	B[2]=A[0]+A[1]-A[2];
	int g=__gcd(B[0],__gcd(B[1],B[2]));
	B[0]/=g;
	B[1]/=g;
	B[2]/=g;
	sort(B,B+3);
	
	ll ret=0;
	FOR(i,N) {
		ll from[1010][8]={};
		ll to[1010][8]={};
		for(k=1;k*(B[0]+B[1]+B[2])<N;k++) from[k][B[0]==0]=to[k][B[0]==0]=1;
		FORR(e,E[i]) {
			map<int,int> M;
			dfs(e,i,1,M);
			for(k=1;k*(B[0]+B[1]+B[2])<N;k++) {
				FOR(x,8) {
					if((x&1)==0                        ) to[k][x^1] += from[k][x]*M[k*B[0]];
					if((x&2)==0 && (B[0]<B[1] || (x&1))) to[k][x^2] += from[k][x]*M[k*B[1]];
					if((x&4)==0 && (B[1]<B[2] || (x&2))) to[k][x^4] += from[k][x]*M[k*B[2]];
				}
			}
			memmove(from,to,sizeof(from));
		}
		for(k=1;k*(B[0]+B[1]+B[2])<N;k++) ret += from[k][7];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
