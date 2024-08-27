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

int N,K;
const ll ma=2*2*2*2*3*3*5*7*11;
ll from[ma+1];
ll to[ma+1];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	from[0]=1;
	FOR(i,K) {
		ZERO(to);
		for(k=1;k<=N;k++) if(ma%k==0) {
			FOR(j,ma-(ma/k)+1) if(from[j]) {
				to[j+ma/k]+=from[j];
			}
		}
		swap(from,to);
	}
	
	ll ret=from[ma];
	if(K==13&&N>=13) ret++;
	if(K==17&&N>=17) ret++;
	if(K==19&&N>=19) ret++;
	if(K==23&&N>=23) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
