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

int N;
int S[1<<18];
ll dp[1<<9][1<<9];
ll p2[2<<18];
ll p11[2<<18];
const ll mo=998244353;

void update(int n) {
	n=(n>>9)<<9;
	ll from[1<<9],to[1<<9];
	int mask;
	FOR(mask,1<<9) from[mask]=S[n+mask];
	int i;
	FOR(i,9) {
		FOR(mask,1<<9) {
			to[mask]=(from[mask]*p11[1<<i]+from[mask^(1<<i)]*p2[1<<i])%mo;
		}
		swap(from,to);
	}
	FOR(mask,1<<9) dp[n>>9][mask]=from[mask];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p11[0]=1;
	FOR(i,(1<<18)+(1<<17)) {
		p2[i+1]=p2[i]*2%mo;
		p11[i+1]=p11[i]*11%mo;
	}
	cin>>N>>s;
	FOR(i,1<<N) S[i]=s[i]-'0';
	FOR(i,1<<9) update(i<<9);
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			S[x]=y;
			update(x);
		}
		else {
			int L,R,X;
			cin>>L>>R>>X;
			R++;
			int len=0;
			ll ret=0;
			while((L&((1<<9)-1))&&L<R) {
				ret=(ret*11+S[L^X]*p2[len])%mo;
				L++;
				len++;
			}
			while(L+(1<<9)<=R) {
				ret=(ret*p11[1<<9]+dp[(L^X)>>9][X&((1<<9)-1)]*p2[len])%mo;
				L+=1<<9;
				len+=1<<9;
			}
			while(L<R) {
				ret=(ret*11+S[L^X]*p2[len])%mo;
				L++;
				len++;
			}
			cout<<ret<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
