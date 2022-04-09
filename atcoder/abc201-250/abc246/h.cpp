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

const int MAT=3;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
const ll mo=998244353;

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return mulmat(l,r);};
	
	SegTree_1(){
		val=vector<V>(NV*2);
		FORR(v,val) v.v[0][0]=v.v[1][1]=v.v[2][2]=1;
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) {
			Mat v;
			v.v[0][0]=v.v[1][1]=v.v[2][2]=1;
			return v;
		}
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<Mat,1<<20> st;
Mat A[3];
int N,Q;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[0].v[0][0]=A[0].v[0][1]=A[0].v[0][2]=A[0].v[1][1]=A[0].v[2][2]=1;
	A[1].v[0][0]=A[1].v[1][0]=A[1].v[1][1]=A[1].v[1][2]=A[1].v[2][2]=1;
	A[2].v[0][0]=A[2].v[0][1]=A[2].v[0][2]=A[2].v[1][0]=A[2].v[1][1]=A[2].v[1][2]=A[2].v[2][2]=1;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		if(S[i]=='0') st.update(i,A[0]);
		if(S[i]=='1') st.update(i,A[1]);
		if(S[i]=='?') st.update(i,A[2]);
	}
	FOR(i,Q) {
		cin>>x>>s;
		x--;
		if(s=="0") st.update(x,A[0]);
		if(s=="1") st.update(x,A[1]);
		if(s=="?") st.update(x,A[2]);
		cout<<(st.val[1].v[0][2]+st.val[1].v[1][2])%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
