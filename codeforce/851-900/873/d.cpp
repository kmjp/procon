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

int T,N;
int P[20][505050];
vector<pair<int,int>> E[505050];
int id;
int L[505050],R[505050],D[505050];
template<class V, int ME> class BIT {

public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs(int cur,int d) {
	L[cur]=id++;
	D[cur]=d;
	FORR2(e,l,E[cur]) {
		l=id;
		dfs(e,d+1);
	}
	R[cur]=id;
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int center,nei;

int sum(int cur) {
	return bt(R[cur]-1)-bt(L[cur]-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			bt.add(i,-bt(i));
		}
		FOR(i,N-1) {
			cin>>P[0][i+1];
			P[0][i+1]--;
			E[P[0][i+1]].push_back({i+1,0});
		}
		id=0;
		dfs(0,0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		int cur=0,sz=1;
		cout<<0<<" ";
		bt.add(L[0],1);
		bt.add(L[1],1);
		for(i=2;i<N;i++) {
			int cand;
			bt.add(L[i],1);
			if(L[cur]<=L[i]&&L[i]<R[cur]) {
				cand=getpar(i,D[i]-D[cur]-1);
				int nsz=sum(cand);
				if(nsz*2>(i+1)) {
					cur=cand;
					sz=(i+1)-nsz;
				}
				else {
					sz=max(sz,nsz);
				}
			}
			else {
				cand=P[0][cur];
				int nsz=sum(cur);
				if((i+1-nsz)*2>i+1) {
					cur=cand;
					sz=nsz;
				}
				else {
					sz=max(sz,i+1-nsz);
				}
			}
			cout<<(i+1)-2*sz<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
