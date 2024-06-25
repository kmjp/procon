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
vector<int> E[200005];
int P[21][200005],D[200005];
int id;
ll ret=0;
int A[202020];

int L[202020],R[202020],re[202020];
int S[202020];

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
}
vector<int> V[202020];

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=17;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=17;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,17) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		V[A[i]].push_back(i);
	}
	
	FOR(i,N) {
		if(V[i].size()<=100) {
			FORR(x,V[i]) FORR(y,V[i]) if(x<y) ret+=dist(x,y);
		}
		else {
			FOR(j,N) {
				S[j+1]=S[j]+(A[re[j]]==i);
			}
			FOR(j,N) {
				x=re[j];
				y=S[R[j]]-S[L[j]];
				ret+=1LL*(V[i].size()-y)*y;
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
