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

static ll const def=(1LL<<60);
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;
int N,A[202020];
ll dp[202020];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	vector<pair<int,int>> mis={{-1,-1}},mas={{1<<30,-1}};
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		{
			pair<int,int> p={A[i],i};
			while(mis.back().first>=p.first) {
				st.update(mis[mis.size()-2].second+1,mis.back().second+1,mis.back().first-p.first);
				mis.pop_back();
			}
			mis.push_back(p);
		}
		{
			pair<int,int> p={A[i],i};
			while(mas.back().first<=p.first) {
				st.update(mas[mas.size()-2].second+1,mas.back().second+1,p.first-mas.back().first);
				mas.pop_back();
			}
			mas.push_back(p);
		}
		
		dp[i+1]=st.getval(0,i);
		st.update(i+1,i+2,dp[i+1]);
	}
	cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
