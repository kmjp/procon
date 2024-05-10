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
vector<int> E[101010];
int A[101010],D[2][101010];
int U[202020],V[202020];

map<pair<int,int>,int> M;
map<int,int> C;
int ret[202020];
multiset<int> Vs[202020];
vector<int> R;

void dfs(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id,d+1);
}
void dfs2(int cur,int pre,int id) {
	if(C[A[cur]]==2) Vs[id].insert(A[cur]);
	
	FORR(e,E[cur]) if(e!=pre) {
		if(D[0][e]+D[1][e]!=D[0][R[1]]) dfs2(e,cur,id);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
		M[{U[i],V[i]}]=M[{V[i],U[i]}]=i;
	}
	int ma2=0,ma3=0;
	
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
	}
	FORR2(a,b,C) {
		if(b>=3) ma3=a;
		if(b==2) ma2=a;
	}
	FOR(i,N-1) ret[i]=ma3;
	
	if(ma2>ma3) {
		FOR(i,N) if(A[i]==ma2) R.push_back(i);
		dfs(R[0],R[0],0,0);
		dfs(R[1],R[1],1,0);
		vector<int> Rs(D[0][R[1]]+1);
		FOR(i,N) {
			if(D[0][i]+D[1][i]==D[0][R[1]]) {
				Rs[D[0][i]]=i;
				dfs2(i,i,i);
			}
		}
		FOR(i,N-1) {
			if(D[0][U[i]]+D[1][U[i]]!=D[0][R[1]]||D[0][V[i]]+D[1][V[i]]!=D[0][R[1]]) {
				ret[i]=ma2;
			}
		}
		set<int> L1,R1;
		map<int,int> L2,R2;
		FORR(r,Rs) FORR(v,Vs[r]) R2[v]=2;
		
		FOR(i,Rs.size()-1) {
			x=Rs[i];
			y=Rs[i+1];
			FORR(v,Vs[x]) {
				if(L1.count(v)) L2[v]=2;
				else L1.insert(v);
				if(R2.count(v)) {
					R2[v]--;
					if(R2[v]==1) {
						R2.erase(v);
					}
				}
			}
			k=M[{x,y}];
			if(L2.size()) ret[k]=max(ret[k],L2.rbegin()->first);
			if(R2.size()) ret[k]=max(ret[k],R2.rbegin()->first);
		}
	}
	
	FOR(i,N-1) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
