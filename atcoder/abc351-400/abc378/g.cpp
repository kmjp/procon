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

int A,B;
ll mo;
ll P[120];
map<ll,ll> memo;
int V[12];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>mo;
	if(A<B) swap(A,B);
	P[0]=1;
	FOR(i,B+2) P[i+1]=P[i]*(A+1);
	ll ret=1;
	FOR(x,2) {
	
		memo.clear();
		memo[0]=1;
		while(memo.size()) {
			ll k=memo.begin()->first;
			ll v=memo.begin()->second%mo;
			memo.erase(memo.begin());
			int sum=0;
			FOR(i,B) {
				V[i]=k/P[i]%(A+1);
				sum+=V[i];
			}
			if(sum==A*B-1) {
				ret=ret*(v%mo)%mo;
				break;
			}
			FOR(i,B) {
				if(V[i]==A) continue;
				if(i&&V[i]==V[i-1]) continue;
				if(x&&i<B-1&&V[i]==A-1&&V[i+1]<A-1) continue;
				memo[k+P[i]]+=v;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
