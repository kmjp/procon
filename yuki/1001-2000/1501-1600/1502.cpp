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

int N,M,K;
vector<pair<int,int>> E[101010];
const ll mo=1000000007;

ll num[2][101010];
set<int> cand;

void dfs(int cur,int v,int id) {
	cand.insert(cur);
	if(num[id][cur]!=-1LL<<60) {
		if(num[id][cur]!=v) {
			cout<<0<<endl;
			exit(0);
		}
		return;
	}
	num[id][cur]=v;
	FORR2(e,c,E[cur]) dfs(e,c-v,id^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	K--;
	FOR(i,M) {
		cin>>x>>y>>k;
		k-=2;
		if(k<0) return _P("0\n");
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,N) num[0][i]=num[1][i]=-1LL<<60;
	
	ll from[2]={1,0};
	FOR(i,N) if(num[0][i]==-1LL<<60&&num[1][i]==-1LL<<60) {
		ll to[2]={0,0};
		cand.clear();
		dfs(i,0,0);
		
		if(num[1][i]==-1LL<<60) {
			ll L=0,R=K;
			FORR(c,cand) {
				ll a=num[0][c];
				ll b=num[1][c];
				if(a!=-1LL<<60) {
					L=max(L,-a);
					R=min(R,K-a);
				}
				else {
					L=max(L,b-K);
					R=min(R,b);
				}
			}
			if(L>R) {
				cout<<0<<endl;
				return;
			}
			ll v=(R-L+1);
			set<int> S;
			FORR(c,cand) {
				if(num[0][c]+R==K) S.insert(R);
				if(num[1][c]-L==K) S.insert(L);
			}
			
			to[0]=from[0]*(v-S.size())%mo;
			to[1]=(from[0]*S.size()+from[1]*v)%mo;
		}
		else {
			int ok=1;
			int ma=0;
			FORR(c,cand) {
				ll v=num[0][c]+num[1][c];
				if(v%2||v<0) {
					cout<<0<<endl;
					return;
				}
				v/=2;
				if(v==K) ma=1;
			}
			to[ma]=(from[0]+from[1])%mo;
		}
		swap(from,to);
	}
	cout<<from[1]<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
