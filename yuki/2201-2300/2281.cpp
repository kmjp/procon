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


int N,Q;
string S;
int L[202020],R[202020];
int P[2][202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	// static V const def=1LL<<60; min
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
SegTree_1<int,1<<20> LT;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		if(i==0||S[i]!=S[i-1]) L[i]=1;
		else L[i]=L[i-1]+1;
		P[0][i+1]=P[0][i];
		P[1][i+1]=P[1][i];
		P[S[i]-'0'][i+1]++;
	}
	for(i=N-1;i>=0;i--) {
		if(i==N-1||S[i]!=S[i+1]) R[i]=1;
		else R[i]=R[i+1]+1;
		LT.update(i,L[i]);
	}
	
	while(Q--) {
		int A,B,K;
		cin>>A>>B>>K;
		A--,B--;
		int ok=0;
		if(A+K-1<=B) {
			if(R[A]>=K) {
				ok=1;
			}
			else {
				x=A+R[A];
				if(LT.getval(x,B+1)>=K) ok=1;
			}
		}
		int ret=B-A+1;
		if(ok) {
			int n0=P[0][B+1]-P[0][A];
			int n1=P[1][B+1]-P[1][A];
			int k=2*K-1;
			int c=((n0-n1)%k+k)%k;
			// 0をK-1個残す
			ret=min(ret,K-1+(K-1-c+k)%k);
			// 1をK-1個残す
			ret=min(ret,K-1+(c+K-1)%k);
			
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
