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
ll N,K,L;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>L;
		K*=2;
		L*=2;
		ll pos=0,tim=0;
		ll ret=1LL<<30;
		FOR(i,N) {
			cin>>A[i];
			A[i]*=2;
			if(i==0) {
				pos=K;
				tim=A[0];
				ret=tim+(L-pos);
			}
			else {
				if(pos<A[i]-tim) {
					A[i]-=tim;
					assert((A[i]-pos)%2==0);
					tim+=(A[i]-pos)/2;
					pos=(pos+A[i])/2+K;
				}
				else if(A[i]-tim<=pos&&pos<=A[i]+tim) {
					pos+=K;
				}
				else {
					pos=max(pos,A[i]+tim+K);
				}
				
				if(pos>=L) ret=min(ret,tim);
				else ret=min(ret,tim+L-pos);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
