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

int N,A[101010];
int Q;
ll L,R,ret;
int cnt[101010];

template<int C,int NV> class SegTree_1 {
public:
	vector<vector<pair<int,int>>> val;
	
	SegTree_1(){val.resize(NV*2);};
	int getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		int pos=lower_bound(ALL(val[k]),make_pair(x,0))-val[k].begin();
		pair<int,int> p=val[k][pos];
		if(p.second<y) return r;
		if(r-l==1) return l;
		
		int m=(l+r)/2;
		int ret=getval(x,y,l,m,2*k);
		if(ret<m) return ret;
		return getval(x,y,m,r,2*k+1);
	}
	void build(vector<int> V, int l=0,int r=NV,int k=1) {
		int m=(l+r)/2;
		
		int VL=V.size();
		int i,c=0,CR=0;
		FOR(i,VL) {
			while(CR<VL&&c<r-l) {
				cnt[A[V[CR]]]++;
				if(cnt[A[V[CR]]]==C) c++;
				CR++;
			}
			if(c==r-l) val[k].push_back({V[i],V[CR-1]});
			if(cnt[A[V[i]]]==C) c--;
			cnt[A[V[i]]]--;
		}
		val[k].push_back({NV,NV});
		
		if(r-l>1) {
			vector<int> LV,RV;
			FORR(v,V) {
				if(A[v]<m) LV.push_back(v);
				else RV.push_back(v);
			}
			build(LV,l,m,k*2);
			build(RV,m,r,k*2+1);
		}
		
	}
};
SegTree_1<1,1<<20> st1;
SegTree_1<2,1<<20> st2;
SegTree_1<3,1<<20> st3;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(i);
	}
	st1.build(V);
	st2.build(V);
	st3.build(V);

	cin>>Q;
	while(Q--) {
		cin>>L>>R;
		L=(L^ret)-1;
		R=(R^ret);
		
		int a=st1.getval(L,R);
		int b=st2.getval(L,R);
		int c=st3.getval(L,R);
		
		ret=min(a+b+c,(int)(R-L-(a==0)-(b==0)-(c==0)));
		
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
