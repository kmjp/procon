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
ll L,R;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		ll d=R/L;
		vector<pair<int,int>> C={{1,1}};
		int step=1;
		while(1) {
			vector<pair<int,int>> D;
			FORR2(a,b,C) {
				for(x=2;a*x<=d;x++) {
					D.push_back({a*x,b});
					if(a*x>=2*D[0].first) break;
				}
			}
			if(D.empty()) break;
			sort(ALL(D));
			C.clear();
			step++;
			FORR2(a,b,D) {
				if(C.empty()||C.back().first!=a) C.push_back({a,0});
				(C.back().second+=b)%=mo;
			}
		}
		ll ret=0;
		FORR2(a,b,C) {
			ll mi=L;
			ll ma=R/a;
			(ret+=(ma-mi+1)*b)%=mo;
		}
		cout<<step<<" "<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
