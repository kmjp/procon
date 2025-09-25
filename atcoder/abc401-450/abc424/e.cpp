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
int N,K,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		map<ll,ll> M;
		cin>>N>>K>>X;
		FOR(i,N) {
			cin>>x;
			M[(1LL<<30)*x]++;
		}
		while(K) {
			auto p=*M.rbegin();
			if(K<p.second) {
				M[p.first/2]+=K*2;
				M[p.first]-=K;
				break;
			}
			else {
				M[p.first/2]+=p.second*2;
				K-=p.second;
				M.erase(p.first);
			}
		}
		while(X) {
			auto p=*M.rbegin();
			M.erase(p.first);
			if(X<=p.second) {
				double a=p.first;
				a/=1<<30;
				_P("%.12lf\n",a);
				break;
			}
			else {
				X-=p.second;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
