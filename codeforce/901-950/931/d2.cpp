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
ll N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		vector<ll> V={N};
		if((N^M)<N) {
			V.push_back(M);
		}
		else {
			if((N&M)!=M) {
				ll v=0;
				int cnt=0;
				for(i=60;i>=0;i--) {
					if(cnt==2) {
						v^=1LL<<i;
						continue;
					}
					if((N&(1LL<<i))==(M&(1LL<<i))) {
						v^=(N&(1LL<<i));
						continue;
					}
					if(M&(1LL<<i)) break;
					cnt++;
					if(cnt==1) v^=1LL<<i;
				}
				if(v!=N) V.push_back(v);
				N=v;
			}
			if((N^M)>=N) {
				cout<<-1<<endl;
				continue;
			}
			if(N!=M) V.push_back(M);
		}
		cout<<V.size()-1<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
