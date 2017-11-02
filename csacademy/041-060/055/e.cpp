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

int N,Q;
vector<int> E[101010];
int C[101010],C2[101010];
int P[21][200005],D[200005];

int T[101010];
int CH[101010];

int DH[101010];
int T2[101010];

void dfs(int cur) {
	CH[cur]=1;
	ITR(it,E[cur]) if(*it!=P[0][cur]) {
		D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
		CH[cur]+=CH[*it];
		T[cur]+=T[*it]+CH[*it];
	}
}

void dfs2(int cur,int pre,ll pd) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,pd+(T[cur]-(T[e]+CH[e]))+(N-CH[e]));
	}
	T[cur]+=pd;
}

void dfs3(int cur,int pre) {
	DH[cur]=C2[cur];
	T2[cur]=0;
	FORR(e,E[cur]) if(e!=pre) {
		dfs3(e,cur);
		T2[cur]+=T2[e]+DH[e];
		DH[cur]+=DH[e];
	}
}
void dfs4(int cur,int pre,ll pd) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs4(e,cur,pd+(T2[cur]-(T2[e]+DH[e]))+(DH[0]-DH[e]));
	}
	T2[cur]+=pd;
}

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=15;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=15;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	dfs2(0,-1,0);
	FOR(i,17) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	set<int> dif;
	FOR(i,Q) {
		if(i==0 || dif.size()>200) {
			dif.clear();
			FOR(j,N) C2[j]=C[j];
			dfs3(0,-1);
			dfs4(0,-1,0);
		}
		cin>>x>>y;
		y--;
		if(x==1) {
			C[y]^=1;
			if(dif.count(y)) {
				dif.erase(y);
			}
			else {
				dif.insert(y);
			}
		}
		else {
			ll ret=T2[y];
			FORR(e,dif) {
				x=dist(y,e);
				if(C[e]==0) ret-=x;
				else ret+=x;
			}
			if(C[y]==0) ret=T[y]-ret;
			cout<<ret<<endl;
		}
		
		
		
	}
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
