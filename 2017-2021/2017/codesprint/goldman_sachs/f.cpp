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

int N,K,P;
ll M;

map<ll,vector<int>> V;
ll pp[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>N>>K>>P>>M;
	pp[0]=1;
	M--;
	FOR(i,N) pp[i+1]=(pp[i]*P)&M;
	
	
	while(1) {
		ll tot=0;
		ll p=1;
		vector<int> A;
		FOR(i,N) {
			x=rand()%(K-1)+1;
			A.push_back(x);
			ll y=(x*pp[i])&M;
			tot=(tot+y)&M;
		}
		reverse(ALL(A));
		if(V.count(tot)) {
			if(A==V[tot]) continue;
			FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
			A=V[tot];
			FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
			return;
		}
		V[tot]=A;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
