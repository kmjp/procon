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

int T,N,K;
int A[402020];
vector<int> E[402020];
int D[404040];
int NC[2][2][204242];

void dfs(int cur,int d) {
	d%=K;
	if(D[cur]!=-1) {
		assert(D[cur]==d);
		return;
	}
	D[cur]=d;
	FORR(e,E[cur]) dfs(e,d+1);
}

using VT = vector<int>;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,2*N) {
			E[i].clear();
			D[i]=-1;
		}
		int C[2][2]={};
		
		FOR(i,2) {
			FOR(j,N) {
				cin>>A[j+(i*N)];
				C[i][A[j+(i*N)]]++;
			}
			cin>>k;
			FOR(j,k) {
				cin>>x>>y;
				x--,y--;
				E[x+(i*N)].push_back(y+(i*N));
			}
		}
		if(C[0][0]!=C[1][1]) {
			cout<<"NO"<<endl;
			continue;
		}
		if(C[0][0]==0||C[1][0]==0) {
			cout<<"YES"<<endl;
			continue;
		}
		
		dfs(0,0);
		dfs(N,0);
		FOR(i,2) {
			FOR(j,K) NC[i][0][j]=NC[i][1][j]=0;
			FOR(j,N) NC[i][A[j+(i*N)]][D[j+(i*N)]]++;
		}
		vector<int> go,re;
		FOR(i,K) go.push_back(NC[0][1][i]);
		FOR(i,2*K) go.push_back(NC[1][0][i%K]);
		FOR(i,K) re.push_back(NC[1][1][i]);
		FOR(i,2*K) re.push_back(NC[0][0][i%K]);
		
		auto AA=Zalgo(go);
		auto BB=Zalgo(re);
		FOR(i,K) if(AA[i+K]>=K) {
			int dif=(K*10-i+2)%K;
			if(BB[K+dif]>=K) break;
		}
		if(i<K) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
