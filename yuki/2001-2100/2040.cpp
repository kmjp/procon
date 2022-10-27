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
string S;
ll from[5050][2][2];
ll to[5050][2][2];

const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	from[2500][0][0]=1;
	FORR(c,S) {
		ZERO(to);
		FOR(x,5000) FOR(y,2) FOR(k,2) if(from[x][y][k]){ //dif, odd/even, prev
			if(c=='0'||c=='?') {
				(to[x+(k?0:2)-1][y^1][1]+=from[x][y][k])%=mo;
			}
			if(c=='1'||c=='?') {
				(to[x][y][0]+=from[x][y][k])%=mo;
			}
			
		}
		
		swap(from,to);
	}
	ll ret=0;
	if(count(ALL(S),'0')==0) ret++;
	for(x=2502;x<=5000;x++) ret+=from[x][0][0]+from[x][0][1];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
