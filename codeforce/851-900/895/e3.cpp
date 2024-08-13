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

static ll const def=-1<<20;
template<int NV> class SegTree_3 {
public:
	vector<int> val[2];
	vector<int> flag;

	SegTree_3(){
		int i;
		val[0].resize(NV*2,0);
		val[1].resize(NV*2,0);
		flag.resize(NV*2,0);
	};
	
	pair<int,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {0,0};
		if(x<=l && r<=y) return {val[0][k],val[1][k]};
		pair<int,int> a=getval(x,y,l,(l+r)/2,k*2);
		pair<int,int> b=getval(x,y,(l+r)/2,r,k*2+1);
		a.first^=b.first;
		a.second^=b.second;
		if(flag[k]) swap(a.first,a.second);
		return a;
	}
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			flag[k]^=1;
			swap(val[0][k],val[1][k]);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			val[0][k]=val[0][k*2]^val[0][k*2+1];
			val[1][k]=val[1][k*2]^val[1][k*2+1];
			if(flag[k]) swap(val[0][k],val[1][k]);

		}
	}
	
	void update(int entry) {
		entry += NV;
		val[0][entry]=val[1][entry]=flag[entry]=0;
		while(entry>1) entry>>=1, val[0][entry]=val[1][entry]=flag[entry]=0;
	}
};

int T,N,Q;
SegTree_3<1<<20> st;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>x;
			st.val[0][(1<<20)+i]=x;
			st.val[1][(1<<20)+i]=0;
		}
		cin>>S;
		FOR(i,N) {
			st.update(i,i+1,1);
			if(S[i]=='0') st.update(i,i+1,1);
		}
		cin>>Q;
		while(Q--) {
			int L,R;
			cin>>i;
			if(i==1) {
				cin>>L>>R;
				st.update(L-1,R,1);
			}
			else {
				cin>>x;
				cout<<st.val[x][1]<<" ";
			}
		}
		cout<<endl;
		FOR(i,N) {
			st.update(i);
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
