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
int A[202020],B[202020];

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma; //区間全体を覆う最大値・区間内のいずれかの最大値
	SegTree_3(){
		val.resize(NV*2,def);
		ma.resize(NV*2,def);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return max({val[k],getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)});
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=max(val[k],v);
			ma[k]=max(ma[k],v);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max({ma[k],ma[k*2],ma[k*2+1]});
		}
	}
	void update2(int entry,V v) {
		entry += NV;
		val[entry]=v;
		ma[entry]=v;
		while(entry>1) {
			entry>>=1;
			val[entry]=0;
			ma[entry]=max(ma[entry*2],ma[entry*2+1]);
		}
	}
};

SegTree_3<int,1<<20> Ast;
vector<int> ev[202020],ev2[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> As={-1,N},Bs={-1,N};
		FOR(i,N) {
			cin>>A[i];
			As.insert(i);
		}
		FOR(i,N) cin>>B[i];
		FOR(i,N) if(A[i]>B[i]) break;
		FOR(i,N+1) {
			ev[i].clear();
			ev2[i].clear();
		}
		if(i<N) {
			cout<<"NO"<<endl;
			continue;
		}
		FOR(i,N) {
			Ast.update2(i,A[i]);
			ev[A[i]].push_back(i);
			ev2[B[i]].push_back(i);
		}
		for(x=1;x<=N;x++) {
			FORR(i,ev[x]) {
				auto it=As.find(i);
				auto it2=Bs.lower_bound(i);
				int L=max(*prev(it),*prev(it2));
				int R=min(*next(it),*it2);
				Ast.update(L+1,R,x);
				
				As.erase(it);
			}
			FORR(i,ev2[x]) Bs.insert(i);
		}
		int ok=1;
		FOR(i,N) if(Ast.getval(i,i+1)!=B[i]) ok=0;
		if(ok) {
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
