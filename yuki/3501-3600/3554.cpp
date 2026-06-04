#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll U[31];
ll M,V;
ll memo[31][2][2];

ll dfs(int d,int le1,int le2) { // 確定したビットと、M未満が確定したかどうか
	if(d==-1) return 1;
	if(memo[d][le1][le2]>=0) return memo[d][le1][le2];
	ll ret=0;
	ll mb=(M>>d)%2;
	ll vb=(V>>d)%2;
	int x,y;
	FOR(x,2) FOR(y,2) {
		if(le1==0&&x>mb) continue;
		if(le2==0&&y>mb) continue;
		if(d%2) {
			if((x|y)==vb) ret+=dfs(d-1,le1|(x<mb),le2|(y<mb));
		}
		else {
			if((x&y)==vb) ret+=dfs(d-1,le1|(x<mb),le2|(y<mb));
		}
	}
	return memo[d][le1][le2]=ret;
	
}

ll H(ll n,ll v) {
	// f(x,y)=vとなるn未満のx,yの個数
	if(n==0) return 0;
	
	MINUS(memo);
	M=n-1;
	V=v;
	return dfs(30,0,0);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,30) U[i+1]=U[i]*4+2;
	int N;
	cin>>N;
	ll ret=0;
	ll pre=0;
	FOR(i,30) {
		ll L=pre,R=N+1;
		while(R-L>1) {
			ll M=(R+L)/2;
			if(H(M,U[i])>=H(M,U[i+1])) {
				L=M;
			}
			else {
				R=M;
			}
		}
		ret+=(R-pre)*U[i];
		pre=R;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
