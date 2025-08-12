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

ll mo;
int N,Q,L,R;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=1;};}; //

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y]%mo;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		return mulmat(l,r);
	};
	
	SegTree_ma(){
		val=vector<V>(NV*2,Mat());};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return Mat();
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<Mat,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>mo>>N;
	FOR(i,N) {
		Mat A;
		cin>>A.v[0][0]>>A.v[0][1]>>A.v[1][0]>>A.v[1][1];
		FOR(x,2) FOR(y,2) A.v[x][y]=(A.v[x][y]%mo+mo)%mo;
		st.update(i,A);
	}
	cin>>Q;
	while(Q--) {
		cin>>i>>L>>R;
		Mat A;
		cin>>A.v[0][0]>>A.v[0][1]>>A.v[1][0]>>A.v[1][1];
		FOR(x,2) FOR(y,2) A.v[x][y]=(A.v[x][y]%mo+mo)%mo;
		st.update(i-1,A);
		auto p=st.getval(L-1,R);
		cout<<(p.v[0][0]%mo+mo)%mo<<" "<<(p.v[0][1]%mo+mo)%mo<<endl;
		cout<<(p.v[1][0]%mo+mo)%mo<<" "<<(p.v[1][1]%mo+mo)%mo<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
