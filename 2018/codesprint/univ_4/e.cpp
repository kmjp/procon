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

template<class V,int NV> class SegTree_1 {
public:
	vector<vector<V>> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,int v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) {
			return lower_bound(ALL(val[k]),v+1)-val[k].begin();
		}
		return getval(x,y,v,l,(l+r)/2,k*2)+getval(x,y,v,(l+r)/2,r,k*2+1);
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
	}
	void build() {
		for(int i=NV-1;i>=1;i--) {
			val[i].clear();
			int a=0,b=0;
			int x=i*2,y=i*2+1;
			while(a<val[x].size() || b<val[y].size()) {
				if(a==val[x].size()) {
					val[i].push_back(val[y][b++]);
				}
				else if(b==val[y].size()) {
					val[i].push_back(val[x][a++]);
				}
				else if(val[x][a]<val[y][b]) {
					val[i].push_back(val[x][a++]);
				}
				else {
					val[i].push_back(val[y][b++]);
				}
			}
		}
	}
};
SegTree_1<int,1<<20> st;

int N;
int nex[1010101];
int pre[1010101];
int Q,L[1010101],R[1010101],ret[1010101];
vector<pair<int,int>> E[1015];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> p;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>x;
		if(p.count(x)) {
			nex[p[x]]=i;
			pre[i]=p[x];
		}
		else {
			pre[i]=-1;
		}
		nex[i]=N+1;
		p[x]=i;
	}
	
	for(i=1;i<=N;i++) st.set(i,nex[i]);
	st.build();
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		E[L[i]/1000].push_back({R[i],i});
	}
	FOR(i,1010) if(E[i].size()) {
		int LL,RR;
		LL=RR=i*1000;
		int cnt=0;
		sort(ALL(E[i]));
		FORR(r,E[i]) {
			x=r.second;
			while(RR<=R[x]) {
				if(pre[RR]<LL) cnt++;
				else if(pre[pre[RR]]<LL) cnt--;
				RR++;
			}
			while(L[x]<LL) {
				LL--;
				if(nex[LL]>=RR) cnt++;
				else if(nex[nex[LL]]>=RR) cnt--;
			}
			while(LL<L[x]) {
				if(nex[LL]<RR) {
					if(nex[nex[LL]]>=RR) cnt++;
				}
				else cnt--;
				LL++;
			}
			ret[x]=cnt;
		}
		
		
	}
	FOR(i,Q) _P("%d\n",ret[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
