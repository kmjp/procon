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

int N,M;
int A[202020];
deque<int> Q[202020];
int did[202020];

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_mi<int,1<<20> stmi1,stmi2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		Q[A[i]].push_back(i);
	}
	FOR(i,M) {
		stmi1.update(i+1,Q[i+1][0]);
		stmi2.update(i+1,Q[i+1].back());
	}
	vector<int> R;
	FOR(i,N) {
		x=A[i];
		if(did[x]) continue;
		
		if(Q[x].size()==1) {
			R.push_back(x);
			did[x]=1;
			stmi1.update(x,1<<20);
			stmi2.update(x,1<<20);
			continue;
		}
		
		Q[x].pop_front();
		stmi1.update(x,Q[x][0]);
		
		int y=stmi1.getval(0,x);
		int k=stmi2.getval(x,M+1);
		if(y>k) {
			R.push_back(x);
			did[x]=1;
			stmi1.update(x,1<<20);
			stmi2.update(x,1<<20);
		}
	}
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
