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

ll SD[202020];

set<int> S[202020];
int AA[302020],BB[302020],CC[302020];
int C[202020];
int N,X,Q;
const ll mo=998244353;
map<pair<int,int>,int> ret;
set<int> cand[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Q;
	FOR(i,N) {
		C[i]=i;
		S[i].insert(i);
	}
	FOR(i,Q) {
		cin>>AA[i]>>BB[i];
		
		if(AA[i]==1) {
			cin>>CC[i];
		}
		if(AA[i]==2) {
			cin>>CC[i];
			if(BB[i]==CC[i]) {
				ret[{BB[i],CC[i]}]=0;
			}
			else {
				cand[BB[i]].insert(CC[i]);
				cand[CC[i]].insert(BB[i]);
			}
		}
	}
	
	FOR(i,Q) {
		if(AA[i]==1) {
			int a=C[BB[i]];
			int b=C[X];
			if(a==b) continue;
			if(S[a].size()<S[b].size()) swap(a,b);
			SD[a]=(SD[a]+SD[b]+1LL*S[a].size()*S[b].size()%mo*CC[i])%mo;
			
			FORR(c,S[b]) {
				FORR(d,cand[c]) if(S[a].count(d)) {
					ret[{c,d}]=ret[{d,c}]=CC[i];
				}
			}
			FORR(c,S[b]) {
				C[c]=a;
				S[a].insert(c);
			}
			S[b].clear();
		}
		else if(AA[i]==2) {
			if(C[BB[i]]!=C[CC[i]]) {
				cout<<-1<<endl;
			}
			else {
				assert(ret.count({BB[i],CC[i]}));
				x=ret[{BB[i],CC[i]}];
				cout<<x<<endl;
				X=(X+x)%N;
			}
		}
		else if(AA[i]==3) {
			cout<<SD[C[BB[i]]]<<endl;
		}
		else if(AA[i]==4) {
			X=(X+BB[i])%N;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
