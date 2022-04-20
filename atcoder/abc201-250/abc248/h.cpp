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


int N,K;
int P[202020];

template<class V,int NV> class SegTree_3 {
public:
	vector<int> dif;
	vector<V> cand;
	SegTree_3(){
		int i;
		dif.resize(NV*2);
		cand.resize(NV*2);
		FOR(i,NV*2) {
			cand[i][0]={500000,1};
			cand[i][1]={1500001,1};
			cand[i][2]={1500002,1};
			cand[i][3]={1500003,1};
			
		}
	};
	
	V merge(V a,V b) {
		V c;
		int i,x=0,y=0;
		FOR(i,4) {
			if(a[x].first==b[y].first) {
				c[i]={a[x].first,a[x].second+b[y].second};
				x++,y++;
			}
			else if(a[x].first<b[y].first) {
				c[i]=a[x++];
			}
			else {
				c[i]=b[y++];
			}
		}
		return c;
	}
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) {
			V a;
			a[0]={1500000,1};
			a[1]={1500001,1};
			a[2]={1500002,1};
			a[3]={1500003,1};
			return a;
		}
		if(x<=l && r<=y) return cand[k];
		V a=merge(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		int i;
		FOR(i,4) a[i].first+=dif[k];
		return a;
	}
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		int i;
		if(x<=l && r<=y) {
			dif[k]+=v;
			FOR(i,4) cand[k][i].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			cand[k]=merge(cand[k*2],cand[k*2+1]);
			int i;
			FOR(i,4) cand[k][i].first+=dif[k];
		}
	}
};
SegTree_3<array<pair<int,int>,4>,1<<19> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<int> ma={0};
	vector<int> mi={1};
	P[0]=N+5;
	P[1]=-5;
	
	ll ret=0;
	for(i=2;i<=N+1;i++) {
		cin>>P[i];
		st.update(2,i,-1);
		st.update(i,i+1,-500000);
		while(P[ma.back()]<P[i]) {
			x=ma.back();
			int d=P[i]-P[x];
			ma.pop_back();
			st.update(ma.back()+1,x+1,d);
		}
		while(P[mi.back()]>P[i]) {
			x=mi.back();
			int d=P[i]-P[x];
			mi.pop_back();
			st.update(mi.back()+1,x+1,-d);
		}
		ma.push_back(i);
		mi.push_back(i);
		auto v=st.getval(2,i+1);
		FOR(j,4) if(v[j].first<=K) ret+=v[j].second;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
