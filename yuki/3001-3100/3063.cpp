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
int A[603030];
vector<int> pos[303030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V m={0,0,0,0};
		
		int al,ar,bl,br;
		for(al=0;al<2;al++) for(ar=al;ar<2;ar++) {
			for(bl=ar;bl<2;bl++) for(br=bl;br<2;br++) {
				chmax(m[al*2+br],l[al*2+ar]+r[bl*2+br]);
			}
		}
		return m;
	};
	
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry][0]=0;
		val[entry][1]=0;
		val[entry][2]=0;
		val[entry][3]=0;
		if(v==0) val[entry][0]=1;
		if(v==1) val[entry][3]=1;
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<int,4>,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[N+i]=A[i];
		pos[A[i]].push_back(i);
		st.update(i,0);
		st.update(N+i,0);
	}
	int ret=1<<30;
	for(i=1;i<=N;i++) if(pos[i].size()) {
		int sum=2*(N-pos[i].size());
		pos[i].push_back(pos[i][0]+N);
		FOR(j,pos[i].size()-1) {
			auto p=st.getval(pos[i][j]+1,pos[i][j+1]);
			sum-=max({p[0],p[1],p[3]});
		}
		ret=min(ret,sum);
		pos[i].pop_back();
		FORR(p,pos[i]) st.update(p,1),st.update(N+p,1);
		
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
