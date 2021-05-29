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
int P[202020],R[202020];
int dp[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<18> lis;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,19> bit;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>P[i];
	if(P[0]<=K) {
		vector<vector<int>> V;
		FOR(i,N) {
			if(P[i]<=K) {
				V.push_back({P[i]});
			}
			else {
				V.back().push_back(P[i]);
			}
		}
		sort(ALL(V));
		reverse(ALL(V));
		FORR(v,V) FORR(a,v) cout<<a<<" ";
		cout<<endl;
	}
	else {
		FOR(i,N) {
			x=P[i];
			R[x]=i;
			if(P[i]<=P[0]) {
				dp[x]=lis.getval(x,N+1)+1;
				lis.update(x,dp[x]);
			}
		}
		vector<int> ret={0,0,0};
		for(i=1;i<=P[0];i++) {
			x=R[i];
			if(bit(N)-bit(x)>=K-dp[i]) {
				y=x;
				for(j=17;j>=0;j--) if(y+(1<<j)<N&&bit(N)-bit(y+(1<<j))>=K-dp[i]) y+=1<<j;
				ret=max(ret,{y,min(K,dp[i]),i});
			}
			bit.add(x,1);
		}
		vector<vector<int>> V;
		FOR(i,ret[0]+1) cout<<P[i]<<" ";
		for(i=ret[0]+1;i<N;i++) {
			if(P[i]<ret[2]) {
				V.push_back({P[i]});
			}
			else {
				V.back().push_back(P[i]);
			}
		}
		assert(V.size()==K-ret[1]);
		sort(ALL(V));
		reverse(ALL(V));
		FORR(v,V) FORR(a,v) cout<<a<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
