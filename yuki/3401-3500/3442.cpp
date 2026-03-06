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

int T;
int N;
vector<int> E[200005];
int P[21][200005],D[200005],C[202020];
int L[202020],R[202020],re[202020];
int Q;
int id;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
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
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];

	set<int> Cs;
	FOR(i,N) {
		cin>>C[i];
		if(C[i]) Cs.insert(L[i]);
	}
	
	auto it=Cs.begin();
	while(it!=Cs.end()&&next(it)!=Cs.end()) {
		x=*it;
		it++;
		y=*it;
		bt.add(x,dist(re[x],re[y]));
	}
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			x--;
			if(C[x]==0) {
				Cs.insert(L[x]);
				auto it=Cs.find(L[x]);
				if(next(it)!=Cs.end()) {
					k=*next(it);
					bt.add(L[x],dist(x,re[k]));
					
					if(it!=Cs.begin()) {
						y=*prev(it);
						bt.add(y,-(bt(y)-bt(y-1)));
					}
					
				}
				if(it!=Cs.begin()) {
					y=*prev(it);
					bt.add(y,dist(x,re[y]));
				}
			}
			else {
				auto it=Cs.find(L[x]);
				bt.add(L[x],-(bt(L[x])-bt(L[x]-1)));
				if(it!=Cs.begin()) {
					y=*prev(it);
					bt.add(y,-(bt(y)-bt(y-1)));
					if(next(it)!=Cs.end()) {
						k=*next(it);
						bt.add(y,dist(re[y],re[k]));
					}
				}
				Cs.erase(it);
			}
			C[x]^=1;
			
		}
		else {
			cin>>x>>y;
			x--,y--;
			ll ret=0;
			if(x==y) {
				if(Cs.size()>=1) {
					x=*Cs.begin();
					y=*Cs.rbegin();
					ret=(bt(N)+dist(re[x],re[y]))/2+1;
				}
			}
			else if(L[y]<L[x]&&L[x]<R[y]) {
				x=getpar(x,D[x]-D[y]-1);
				auto it=Cs.lower_bound(0);
				auto it2=Cs.lower_bound(L[x]);
				auto it3=Cs.lower_bound(R[x]);
				auto it4=Cs.lower_bound(N);
				if(it!=it2) {
					int a=*it;
					int b=*prev(it2);
					if(it3!=it4) {
						int c=*it3;
						int d=*prev(it4);
						ret=(dist(re[a],re[d])+dist(re[b],re[c])+bt(b-1)-bt(a-1)+bt(d-1)-bt(c-1))/2+1;
					}
					else {
						ret=(bt(b-1)-bt(a-1)+dist(re[a],re[b]))/2+1;
					}
				}
				else if(it3!=it4) {
					x=*it3;
					y=*prev(it4);
					ret=(bt(y-1)-bt(x-1)+dist(re[x],re[y]))/2+1;
				}
			}
			else {
				auto it=Cs.lower_bound(L[y]);
				auto it2=Cs.lower_bound(R[y]);
				if(it!=it2) {
					x=*it;
					y=*prev(it2);
					ret=(bt(y-1)-bt(x-1)+dist(re[x],re[y]))/2+1;
				}
			}
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
