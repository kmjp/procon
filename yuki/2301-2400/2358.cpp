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

ll N;

void solve() {
	int i,j,k,l,r; string s;
	
	cin>>N;
	ll x,y,z;
	vector<vector<ll>> V;
	for(y=1;1LL*y*y<=N;y++) {
		for(z=y;y*z<=N;z++) {
			ll a=N-y*z;
			if(a>=0&&a%(y+z)==0) {
				x=a/(y+z);
				if(x<=y) {
					if(x==y&&y==z) V.push_back({x,y,z});
					else if(x==y||y==z) {
						V.push_back({x,y,z});
						V.push_back({z,x,y});
						V.push_back({y,z,x});
					}
					else {
						V.push_back({x,y,z});
						V.push_back({z,x,y});
						V.push_back({y,z,x});
						V.push_back({x,z,y});
						V.push_back({y,x,z});
						V.push_back({z,y,x});
					}
					
				}
			}
		}
	}
	cout<<V.size()<<endl;
	FORR(a,V) cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
