#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
const int MAT=3;
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat def={.v={{1,0,0},{0,1,0},{0,0,1}}};
Mat zero={.v={{0,0,0},{0,0,0},{0,0,0}}};

template<class V,int NV> class SegTree_A {
public:
	vector<V> val;
	virtual V comp(V l,V r){ return mulmat(r,l);};
	SegTree_A(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_B : public SegTree_A<V,NV>{
public:
	V comp(V l,V r){ return mulmat(l,r);};
};

int N,Q;
SegTree_A<Mat,1<<18> AS;
SegTree_B<Mat,1<<18> BS;

template<class V,int NV> class SegTree_S{
public:
	vector<V> val;
	SegTree_S(){val=vector<V>(NV*2,zero);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return zero;
		if(x<=l && r<=y) return val[k];
		
		if(y<=(l+r)/2) return getval(x,y,l,(l+r)/2,k*2);
		if(x>=(l+r)/2) return getval(x,y,(l+r)/2,r,k*2+1);
		
		Mat m1=getval(x,y,l,(l+r)/2,k*2);
		Mat m2=getval(x,y,(l+r)/2,r,k*2+1);
		Mat b=BS.getval(x,y,l,(l+r)/2,k*2);
		Mat a=AS.getval(x,y,l,(l+r)/2,k*2);
		
		m2 = mulmat(b,m2);
		m2 = mulmat(m2,a);
		int i,j;
		FOR(i,3) FOR(j,3) {
			m1.v[i][j]+=m2.v[i][j];
			if(m1.v[i][j]>=mo) m1.v[i][j]-=mo;
		}
		
		return m1;
	}
	void update(int x,int y,V v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return;
		if(x<=l && r<=y) {
			val[k]=v;
		}
		else {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			Mat m = mulmat(BS.val[k*2],val[k*2+1]);
			m = mulmat(m,AS.val[k*2]);
			int i,j;
			FOR(i,3) FOR(j,3) {
				val[k].v[i][j]=val[k*2].v[i][j]+m.v[i][j];
				if(val[k].v[i][j]>=mo) val[k].v[i][j]-=mo;
			}
		}
	}
};


SegTree_S<Mat,1<<18> SS;
Mat C[101010];
ll A[3],B[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>A[0]>>A[1]>>A[2];
	cin>>B[0]>>B[1];
	
	FOR(i,N+1) {
		C[i].v[0][0]=6*i+0;
		C[i].v[0][1]=6*i+1;
		C[i].v[0][2]=6*i+2;
		C[i].v[1][0]=6*i+3;
		C[i].v[1][1]=6*i+4;
		C[i].v[1][2]=6*i+5;
		SS.update(i,i+1,C[i]);
	}
	
	
	cin>>Q;
	while(Q--) {
		cin>>s>>i;
		if(s=="a") {
			Mat m;
			cin>>m.v[0][0]>>m.v[0][1]>>m.v[0][2];
			cin>>m.v[1][0]>>m.v[1][1]>>m.v[1][2];
			cin>>m.v[2][0]>>m.v[2][1]>>m.v[2][2];
			AS.update(i,m);
			SS.update(i,i+1,C[i]);
		}
		else if(s=="b") {
			Mat m;
			cin>>m.v[0][0]>>m.v[0][1];
			cin>>m.v[1][0]>>m.v[1][1];
			m.v[0][2]=m.v[1][2]=m.v[2][0]=m.v[2][1]=m.v[2][2]=0;
			BS.update(i,m);
			SS.update(i,i+1,C[i]);
		}
		else if(s=="ga") {
			Mat m=AS.getval(0,i);
			cout<<(m.v[0][0]*A[0]+m.v[0][1]*A[1]+m.v[0][2]*A[2])%mo<<" ";
			cout<<(m.v[1][0]*A[0]+m.v[1][1]*A[1]+m.v[1][2]*A[2])%mo<<" ";
			cout<<(m.v[2][0]*A[0]+m.v[2][1]*A[1]+m.v[2][2]*A[2])%mo<<endl;
		}
		else if(s=="gb") {
			Mat b=BS.getval(i+1,N+1);
			Mat s=SS.getval(i+1,N+1);
			Mat a=AS.getval(0,i+1);
			Mat sa=mulmat(s,a);
			cout<<((b.v[0][0]*B[0]+b.v[0][1]*B[1])%mo + (sa.v[0][0]*A[0]+sa.v[0][1]*A[1]+sa.v[0][2]*A[2])%mo)%mo<<" ";
			cout<<((b.v[1][0]*B[0]+b.v[1][1]*B[1])%mo + (sa.v[1][0]*A[0]+sa.v[1][1]*A[1]+sa.v[1][2]*A[2])%mo)%mo<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
