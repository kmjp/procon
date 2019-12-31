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

int G;
int N;
int A[31];
string S[2]={"Sherlock","Watson"};
int V[2];

int did[201010];
int mp[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	did[1]=1;
	did[2]=2;
	mp[1]=2;
	int add=2;
	for(x=3;x<=100000;x++) {
		if(did[x]) continue;
		did[x]=1;
		did[x+add]=1;
		mp[x]=x+add;
		add++;
	}
	
	cin>>G;
	while(G--) {
		cin>>N;
		
		if(N>2) {
			int xo=0;
			FOR(i,N) cin>>x, xo^=x;
			cout<<S[xo==0]<<endl;
		}
		else {
			cin>>x>>y;
			if(x>y) swap(x,y);
			cout<<S[mp[x]==y]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
