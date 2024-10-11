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

int T,M;
int N[202020];
ll L[202020],R[202020],SS[202020];
vector<ll> A[202020],C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M;
		ll SL=0,SR=0;
		int NS=0;
		map<ll,vector<pair<int,ll>>> MM;
		FOR(i,M) {
			cin>>N[i]>>L[i]>>R[i];
			NS+=N[i];
			SL+=L[i];
			SR+=R[i];
			SS[i]=0;
			A[i].resize(N[i]);
			C[i].resize(N[i]);
			FOR(j,N[i]) {
				cin>>A[i][j];
			}
			FOR(j,N[i]) {
				cin>>C[i][j];
				SS[i]+=C[i][j];
				MM[A[i][j]].push_back({i,C[i][j]});
			}
		}
		if(SR-SL+1>NS) {
			cout<<0<<endl;
			continue;
		}
		ll mi=1LL<<60;
		for(ll len=SL;len<=SR;len++) {
			if(MM.count(len)==0) {
				mi=0;
				break;
			}
			auto V=MM[len];
			ll sum=SR;
			FORR2(a,b,V) {
				sum-=R[a];
			}
			ll can=0;
			ll must=0;
			ll need=0;
			FORR2(a,b,V) {
				ll oth=min(R[a],SS[a]-b);
				must+=max(0LL,L[a]-(SS[a]-b));
				can+=b-max(0LL,L[a]-(SS[a]-b));
				sum+=oth+max(0LL,L[a]-(SS[a]-b));
			}
			if(sum+can>=len) mi=min(mi,must+max(0LL,len-sum));
			
			
		}
		cout<<mi<<endl;
	}
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
