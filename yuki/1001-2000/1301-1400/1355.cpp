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
ll X,Y;
ll A[202020];
map<pair<ll,ll>,pair<pair<ll,ll>,int>> M[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>X>>Y;
	FOR(i,N) cin>>A[i];
	M[N][{0,(1LL<<60)-1}]={{0,0},1};
	FOR(i,N) ret[i]=3;
	for(i=N-1;i>=0;i--) {
		FORR(m,M[i+1]) {
			ll o=m.first.first;
			ll a=m.first.second;
			if((Y&a)!=Y) continue;
			if((Y|o)!=Y) continue;
			if(((A[i]|o)&a)==Y) {
				i=i+1;
				while(i<N) {
					assert(M[i].count({o,a}));
					auto m2=M[i][{o,a}];
					o=m2.first.first;
					a=m2.first.second;
					ret[i]=m2.second;
					i++;
				}
				FOR(i,N) cout<<ret[i]<<" ";
				return;
			}
			//and
			ll am=(A[i]|o)&a;
			M[i][{o,am}]={{o,a},1};
			//or
			ll om=(A[i]&a)|o;
			M[i][{om,a}]={{o,a},2};
		}
	}
	FORR(m,M[0]) {
		ll o=m.first.first;
		ll a=m.first.second;
		if(((X|o)&a)==Y) {
			i=0;
			while(i<N) {
				auto m2=M[i][{o,a}];
				o=m2.first.first;
				a=m2.first.second;
				ret[i]=m2.second;
				i++;
			}
			FOR(i,N) cout<<ret[i]<<" ";
			return;
		}
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
