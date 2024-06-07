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

string S;
ll from[1<<10][2][2];
ll to[1<<10][2][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	from[0][1][0]=1;
	FORR(c,S) {
		c-='0';
		ZERO(to);
		int mask,lead,le,d;
		FOR(mask,1<<10) FOR(lead,2) FOR(le,2) {
			FOR(d,10) {
				if(le==0&&d>c) continue;
				
				if(lead==1&&d==0) {
					(to[0][lead][le|(d<c)]+=from[mask][lead][le])%=mo;
				}
				else {
					(to[mask^(1<<d)][0][le|(d<c)]+=from[mask][lead][le])%=mo;
				}
				
			}
		}
		
		swap(from,to);
	}
	ll ret=from[0][0][0]+from[0][0][1];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
