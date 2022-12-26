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
struct Mat { double v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=v[2][2]=1;};}; //

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += a.v[x][z]*b.v[z][y];
	return r;
}

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return mulmat(r,l);};
	
	SegTree_1(){val=vector<V>(NV*2,Mat());};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return Mat();
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<Mat,1<<18> st;

int N,T;
double P[101010],Q[101010],R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double PI=atan(1)*4;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i]>>Q[i]>>R[i];
		Mat m;
		double c=cos(R[i]*PI/180);
		double s=sin(R[i]*PI/180);
		m.v[0][0]=m.v[1][1]=c;
		m.v[0][1]=-s;
		m.v[1][0]=s;
		m.v[0][2]=P[i]*(1-c)+Q[i]*s;
		m.v[1][2]=Q[i]*(1-c)-P[i]*s;
		st.update(i,m);
	}
	
	cin>>T;
	while(T--) {
		int S,T;
		double X,Y;
		cin>>S>>T>>X>>Y;
		Mat m=st.getval(S-1,T);
		double dx=m.v[0][0]*X+m.v[0][1]*Y+m.v[0][2];
		double dy=m.v[1][0]*X+m.v[1][1]*Y+m.v[1][2];
		_P("%.12lf %.12lf\n",dx,dy);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
