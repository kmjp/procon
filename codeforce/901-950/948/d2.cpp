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

int T,H,W;
string S[303030];

map<pair<ll,ll>,vector<pair<int,int>>> M;
const ll mo=1000000007;
ll p2[303030];
ll p3[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p3[0]=1;
	FOR(i,301010) p2[i+1]=p2[i]*2%mo,p3[i+1]=p3[i]*3%mo;
	
	
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		M.clear();
		pair<ll,ll> v;
		FOR(x,W) {
			ll cur1=0,cur2=0;
			FOR(y,H) if(S[y][x]=='1') cur1+=p2[y],cur2+=p3[y];
			FOR(y,H) {
				ll a=cur1,b=cur2;
				if(S[y][x]=='1') {
					a-=p2[y],b-=p3[y];
				}
				else {
					a+=p2[y],b+=p3[y];
				}
				M[{a,b}].push_back({x,y});
				if(M[{a,b}].size()>M[v].size()) v={a,b};
			}
		}
		int ret=M[v].size();
		int x1=M[v][0].first;
		int y1=M[v][0].second;
		string V;
		FOR(y,H) {
			if(y==y1) V+=S[y][x1]^1;
			else V+=S[y][x1];
		}
		cout<<ret<<endl;
		cout<<V<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
