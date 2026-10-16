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


template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		V m={max(l[0],r[0]),max(l[1],r[1]),max({l[2],r[2],l[0]+r[1]})};
		return m;
	};
	
	SegTree_ma(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int L,int R) {
		entry += NV;
		val[entry]={L,R,-1<<20};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<array<int,3>,1<<20> st;


int N;
int A[202020];
int dp[202020];
int L[202020],R[202020];
deque<int> Ls[202020],Rs[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) dp[i]=1<<30;
	vector<int> As={-1,1<<30};
	FOR(i,N) {
		cin>>A[i];
		As.push_back(A[i]);
	}
	FOR(i,N+2) Ls[i].push_back(0),Rs[i].push_back(0);
	
	
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	int lisma=0;
	FOR(i,N) {
		A[i]=lower_bound(ALL(As),A[i])-As.begin();
		L[i]=lower_bound(dp,dp+N,A[i])-dp;
		dp[L[i]]=A[i];
		L[i]++;
		Ls[A[i]].push_back(L[i]);
		lisma=max(lisma,L[i]);
	}
	FOR(i,N) dp[i]=1<<30;
	for(i=N-1;i>=0;i--) {
		x=(1<<30)-A[i];
		R[i]=lower_bound(dp,dp+N,x)-dp;
		dp[R[i]]=x;
		R[i]++;
		Rs[A[i]].push_front(R[i]);
	}
	FOR(i,As.size()) {
		st.update(i,Ls[i][0],Rs[i][0]);
	}
	
	FOR(i,N) {
		x=A[i];
		Rs[x].pop_front();
		st.update(x,Ls[x][0],Rs[x][0]);
		auto p=st.getval(0,N+2);
		int ret=max(lisma,p[2]+1);
		cout<<ret<<endl;
		Ls[x].pop_front();
		st.update(x,Ls[x][0],Rs[x][0]);
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
