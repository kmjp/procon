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

int N,K[101010],A[101010];
multiset<ll> V[101010];
multiset<ll> W;

vector<pair<ll,vector<int>>> cand[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+6) V[i].insert(-(1LL<<50));
	
	FOR(i,N) {
		cin>>K[i]>>A[i];
		K[i]--;
		V[K[i]].insert(A[i]);
	}
	FOR(i,N+6) W.insert(*V[i].rbegin());
	
	ll ret=-1;
	cand[0].push_back({0,{}});
	FOR(i,N) {
		W.erase(W.find(*V[K[i]].rbegin()));
		V[K[i]].erase(V[K[i]].find(A[i]));
		
		FORR2(a,b,cand[4]) {
			int ng=0;
			for(j=2;j<=3;j++) if(j>=2&&b[j]==K[i]) ng=1;
			
			if(ng==0) {
				W.erase(W.find(*V[b[2]].rbegin()));
				W.erase(W.find(*V[b[3]].rbegin()));
				ret=max(ret,a+A[i]+*W.rbegin());
				W.insert(*V[b[2]].rbegin());
				W.insert(*V[b[3]].rbegin());
			}
		}
		W.insert(*V[K[i]].rbegin());
		
		for(j=3;j>=0;j--) {
			FORR2(a,b,cand[j]) {
				int ng=0;
				FORR(c,b) {
					if(c==K[i]) ng=1;
				}
				if(ng==0) {
					b.push_back(K[i]);
					cand[j+1].push_back({a+A[i],b});
					b.pop_back();
				}
			}
		}
		FOR(j,5) {
			sort(ALL(cand[j]));
			reverse(ALL(cand[j]));
			if(cand[j].size()>30) {
				cand[j].resize(30);
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
