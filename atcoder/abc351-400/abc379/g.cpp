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
string V[200];
string S[200];

const ll mo=998244353;
ll p10[18];

vector<int> decode(int first,int mask) {
	int i;
	vector<int> V={first};
	FOR(i,W-1) V.push_back((V.back()+1+(mask>>i)%2)%3);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>V[y];
	
	if(W>H) {
		FOR(y,H) FOR(x,W) S[x].push_back(V[y][x]);
		swap(W,H);
	}
	else {
		FOR(y,H) S[y]=V[y];
	}
	
	p10[0]=1;
	FOR(i,16) p10[i+1]=p10[i]*10;
	
	map<ll,ll> F,T;
	F[0]=1;
	FOR(y,H) {
		FOR(x,W) {
			T.clear();
			FORR2(a,b,F) {
				ll p=a/p10[W-1-x]%10;
				ll q=a/p10[W-x]%10;
				for(j=1;j<=3;j++) {
					if(S[y][x]!='?'&&S[y][x]!='0'+j) continue;
					if(j==p||j==q) continue;
					ll na=a+(j-p)*p10[W-1-x];
					(T[na]+=b)%=mo;
				}
			}
			swap(F,T);
		}
	}
	
	ll ret=0;
	FORR2(a,b,F) ret+=b;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
