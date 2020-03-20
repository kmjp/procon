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
int A[101010];
int id[101010];
int inloop[101010];
vector<int> V;
vector<int> C[101010];
int cid;
int L[101010],R[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
int cnt[101010];

int dfs(int cur) {
	if(id[cur]>=0) return id[cur];
	if(id[cur]==-2) {
		int i;
		for(i=V.size()-1;;i--) {
			inloop[V[i]]=1;
			if(V[i]==cur) break;
		}
		return id[cur]=cid++;
	}
	id[cur]=-2;
	V.push_back(cur);
	id[cur]=dfs(A[cur]);
	if(inloop[cur]==0) C[A[cur]].push_back(cur);
	V.pop_back();
	return id[cur];
	
}

void dfs2(int cur) {
	L[cur]=cid++;
	FORR(c,C[cur]) dfs2(c);
	R[cur]=cid;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	MINUS(id);
	FOR(i,N) {
		if(id[i]==-1) {
			V.clear();
			dfs(i);
		}
	}
	
	cid=0;
	FOR(i,N) if(inloop[i]) dfs2(i);
	
	FOR(i,N) {
		if(inloop[i]) {
			cout<<cnt[id[i]]<<endl;
			cnt[id[i]]++;
		}
		else {
			cout<<bt(R[i]-1)-bt(L[i])<<endl;
			cnt[id[i]]++;
			bt.add(L[i],1);
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
