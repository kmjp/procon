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

int N,M;
string S;
vector<int> E[6060];
const ll mo=998244353;
int H;

ll p26[6060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>S;
	
	p26[0]=1;
	FOR(i,N+2) p26[i+1]=p26[i]*26%mo;
	
	FOR(i,N) if(S[i]=='?') H++;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	ll ret=0;
	FOR(i,N) {
		
		if(S[i]=='?') H--;
		else if(S[i]!='o') continue;
		
		FORR(a,E[i]) FORR(b,E[i]) if(a!=b) {
			if(S[a]=='a'||S[a]=='?') {
				if(S[b]=='i'||S[b]=='?') {
					(ret+=p26[H-(S[a]=='?')-(S[b]=='?')])%=mo;
				}
			}
			
		}
			
		if(S[i]=='?') H++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
