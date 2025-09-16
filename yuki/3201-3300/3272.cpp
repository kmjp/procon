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
vector<int> E[202020];
int CR;
pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//dS‚ðŽæ‚éê‡
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

int D[200005],side[202020],G[202020];;
int L[202020],R[202020],re[202020];
ll ret[202020];
int id;

void dfs(int cur,int p,int s,int d,int g) {
	side[cur]=s;
	G[cur]=g;
	L[cur]=id++;
	D[cur]=d;
	FORR(e,E[cur]) if(e!=p) dfs(e,cur,s,d+1,g);
	R[cur]=id;
}

int U[202020],V[202020];
map<pair<int,int>,int> M;
int cnt[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		M[{U[i],V[i]}]=M[{V[i],U[i]}]=i;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	auto p=diameter();
	CR=p.first/2;
	int C1=p.second[0];
	int C2=p.second.back();
	ll sum=0;
	if(C1==C2) {
		L[C1]=id++;
		FORR(e,E[C1]) dfs(e,C1,0,1,e);
		R[C1]=id;
		FOR(i,N) sum+=D[i]+CR;
	}
	else {
		L[C1]=id++;
		FORR(e,E[C1]) if(e!=C2) dfs(e,C1,0,1,e);
		R[C1]=id;
		L[C2]=id++;
		FORR(e,E[C2]) if(e!=C1) dfs(e,C2,1,1,e);
		R[C2]=id;
		FOR(i,N) {
			sum+=1+CR+D[i];
		}
		ret[M[{C1,C2}]]=sum-N-CR;
	}
	FOR(i,N) if(D[i]==CR) cnt[L[i]+1]++;
	FOR(i,N) cnt[i+1]+=cnt[i];
	vector<int> C[2];
	FOR(i,N) if(D[i]==1&&cnt[R[i]]-cnt[L[i]]) C[side[i]].push_back(i);
	
	if(C1==C2) {
		FOR(i,N-1) {
			x=U[i],y=V[i];
			if(D[x]>D[y]) swap(x,y);
			ret[i]=sum;
			ret[i]-=R[y]-L[y];
			ret[i]-=D[y]+CR-1;
			k=G[y];
			if(cnt[R[y]]-cnt[L[y]]&&cnt[R[k]]-cnt[L[k]]==cnt[R[y]]-cnt[L[y]]&&C[0].size()==2) {
				ret[i]-=(R[C[0][C[0][0]==k]]-L[C[0][C[0][0]==k]]);
			}
		}
	}
	else {
		FOR(i,N-1) if(M[{C1,C2}]!=i) {
			x=U[i],y=V[i];
			if(D[x]>D[y]) swap(x,y);
			ret[i]=sum;
			ret[i]-=R[y]-L[y];
			ret[i]-=D[y]+CR;
			k=G[y];
			if(side[y]==0&&cnt[R[C1]]-cnt[L[C1]]==cnt[R[y]]-cnt[L[y]]) ret[i]-=(R[C2]-L[C2]);
			if(side[y]==1&&cnt[R[C2]]-cnt[L[C2]]==cnt[R[y]]-cnt[L[y]]) ret[i]-=(R[C1]-L[C1]);
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
