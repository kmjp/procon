#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int C[202020];
vector<pair<int,int>> cand[202020];
vector<int> E[202020];
int L[202020],R[202020],id;
int rem[201010];

int pr[202020];
vector<int> hist[202020];


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void dfs(int cur,int pre) {
	if(hist[C[cur]].size()) pr[cur]=hist[C[cur]].back();
	
	L[cur]=id++;
	cand[C[cur]].push_back({L[cur],cur});
	FORR(e,E[cur]) {
		hist[C[cur]].push_back(e);
		if(e!=pre) dfs(e,cur);
		hist[C[cur]].pop_back();
	}
	R[cur]=id;
	bt.add(L[cur],N-(R[cur]-L[cur]));
	bt.add(L[cur]+1,-(N-(R[cur]-L[cur])));
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	
	FOR(i,N) {
		ll ret=0;
		sort(ALL(cand[i]));
		FORR(c,cand[i]) {
			x=c.second;
			int num=bt(L[x])+1;
			ret+=num;
			FORR(e,E[x]) if(L[e]>L[x]) {
				ret+=1LL*num*(R[e]-L[e]);
				num+=(R[e]-L[e]);
			}
			//cout<<x<<" "<<ret<<endl;
			FORR(e,E[x]) if(L[e]>L[x]) {
				bt.add(L[e],-(num-(R[e]-L[e])));
				bt.add(R[e],num-(R[e]-L[e]));
			}
			y=pr[x];
			bt.add(L[y],-(R[x]-L[x]));
			bt.add(L[x],(R[x]-L[x]));
			bt.add(R[x],-(R[x]-L[x]));
			bt.add(R[y],(R[x]-L[x]));
			rem[x]=num;
		}
		FORR(c,cand[i]) {
			x=c.second;
			FORR(e,E[x]) if(L[e]>L[x]) {
				bt.add(L[e],(rem[x]-(R[e]-L[e])));
				bt.add(R[e],-(rem[x]-(R[e]-L[e])));
			}
			y=pr[x];
			bt.add(L[y],(R[x]-L[x]));
			bt.add(L[x],-(R[x]-L[x]));
			bt.add(R[x],(R[x]-L[x]));
			bt.add(R[y],-(R[x]-L[x]));
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
