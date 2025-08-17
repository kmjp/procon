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

int N,L;
int NL[8];
string S[8];
int ne[8][11][26];
const ll mo=998244353;
ll p11[11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p11[0]=1;
	FOR(i,8) p11[i+1]=p11[i]*11;
	
	cin>>N>>L;
	ll target=0;
	FOR(i,N) {
		cin>>S[i];
		NL[i]=S[i].size();
		FOR(j,NL[i]) {
			FOR(k,26) {
				s=S[i].substr(0,j)+(char)('a'+k);
				FOR(l,s.size()+1) if(S[i].substr(0,l)==s.substr(s.size()-l)) ne[i][j][k]=l;
			}
		}
		FOR(j,26) ne[i][NL[i]][j]=NL[i];
		target+=NL[i]*p11[i];
	}
	
	unordered_map<ll,ll> from,to;
	from[0]=1;
	FOR(i,L) {
		to.clear();
		FORR2(cur,b,from) {
			FOR(j,26) {
				ll nex=0;
				FOR(x,N) nex+=ne[x][cur/p11[x]%11][j]*p11[x];
				(to[nex]+=b)%=mo;
			}
		}
		swap(from,to);
	}
	cout<<from[target]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
