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
int E[2020];

int nex(int a,int b,int c,int d) {
	if(a==0 && b==0 && c==0 && d==0) return 1;
	if(a==0 && b==0 && c==1 && d==1) return 1;
	if(a==0 && b==1 && c==1 && d==0) return 1;
	if(a==0 && b==1 && c==1 && d==1) return 1;
	if(a==1 && b==0 && c==0 && d==0) return 1;
	if(a==1 && b==0 && c==1 && d==1) return 1;
	if(a==1 && b==1 && c==1 && d==0) return 1;
	if(a==1 && b==1 && c==0 && d==1) return 1;
	return 0;
}

ll ret=0;
ll from[2][2];
ll to[2][2];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>E[i];
	
	FOR(x,2) FOR(y,2) {
		ZERO(from);
		from[x][y]=1;
		FOR(i,N) {
			ZERO(to);
			int a,b,c;
			FOR(a,2) FOR(b,2) FOR(c,2) {
				if(nex(a,b,E[i],c)) (to[b][c]+=from[a][b])%=mo;
			}
			swap(from,to);
		}
		
		ret+=from[x][y];
		
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
