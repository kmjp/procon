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
vector<ll> V[10];
ll p10[19];

ll num(ll v) {
	ll ret=0;
	int x,y;
	int L=to_string(v).size();
	FOR(x,10) {
		FORR(a,V[x]) if(a*p10[x]+a<=v) ret--;
		FOR(y,10) {
			if(x+y<L) {
				ret+=1LL*V[x].size()*V[y].size();
			}
			else if(x+y==L) {
				FORR(a,V[x]) {
					ret+=lower_bound(ALL(V[y]),v-a*p10[y]+1)-V[y].begin();
				}
			}
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,10) p10[i+1]=p10[i]*10;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		V[to_string(x).size()].push_back(x);
	}
	FOR(i,10) sort(ALL(V[i]));
	ll ret=1LL<<60;
	for(i=59;i>=0;i--) if(num(ret-(1LL<<i))>=1LL*N*(N-1)/2) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
