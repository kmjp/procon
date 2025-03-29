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

int T;
int N,M;
int L[202020];
int U[202020],V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		int sum=0;
		int ma=0;
		FOR(i,N) {
			cin>>L[i];
			sum+=L[i]+2;
			set<int> S;
			FOR(j,L[i]) {
				cin>>x;
				S.insert(x);
			}
			U[i]=V[i]=-1;
			FOR(j,202020) {
				if(S.count(j)==0) {
					if(U[i]==-1) U[i]=j;
					else {
						V[i]=j;
						break;
					}
				}
			}
			ma=max(ma,V[i]);
		}
		
		ll ret;
		if(ma>=M) ret=1LL*(M+1)*ma;
		else ret=1LL*ma*(ma+1)+1LL*(M+ma+1)*(M-ma)/2;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
