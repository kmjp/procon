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

int H,W;
const ll mo=998244353;
ll from[1<<18][2],to[1<<18][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	from[(1<<W)-1][1]=1;
	int mask;
	FOR(y,H) {
		cin>>s;
		FOR(x,W) {
			ZERO(to);
			FOR(mask,1<<W) {
				if(s[x]=='0'||s[x]=='?') {
					(to[mask&((1<<W)-1-(1<<x))][0]+=from[mask][0]+from[mask][1])%=mo;
				}
				if(s[x]=='1'||s[x]=='?') {
					if((mask&(1<<x))) {
						(to[mask][0]+=from[mask][0])%=mo;
						(to[mask][1]+=from[mask][1])%=mo;
					}
					else {
						(to[mask][1]+=from[mask][1])%=mo;
					}
				}
				
			}
			
			swap(from,to);
		}
		FOR(mask,1<<W) {
			(from[mask][1]+=from[mask][0])%=mo;
			from[mask][0]=0;
		}
	}
	
	ll ret=0;
	FOR(mask,1<<W) ret+=from[mask][1];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
