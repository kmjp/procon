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

int N,Q;
int T[101010],L[101010],R[101010];
vector<int> cand;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=1;};}; //
ll mo=1000000007;

Mat mulmat(Mat a,Mat b,int n=MAT) {
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

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

Mat okm,ngm;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	
	SegTree_1(){
		val=vector<V>(NV*2);
		Mat m;
		FORR(v,val) v=m;
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) {
			Mat m;
			return m;
		}
		if(x<=l && r<=y) return val[k];
		return mulmat(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry) {
		entry += NV;
		if(val[entry].v[0][0]==1) val[entry]=ngm;
		else val[entry]=okm;
		while(entry>1) entry>>=1, val[entry]=mulmat(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<Mat,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	cand.push_back(0);
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>L[i];
			cand.push_back(L[i]);
			cand.push_back(L[i]+1);
		}
		else {
			cin>>L[i]>>R[i];
			cand.push_back(L[i]);
			cand.push_back(R[i]+1);
		}
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	okm.v[0][0]=okm.v[0][1]=okm.v[1][0]=1;
	okm.v[1][1]=0;
	ngm.v[1][0]=1;
	ngm.v[0][0]=ngm.v[0][1]=ngm.v[1][1]=0;
	FOR(i,cand.size()-1) st.val[(1<<20)+i]=powmat(cand[i+1]-cand[i],okm);
	for(i=(1<<20)-1;i>=1;i--) st.val[i]=mulmat(st.val[i*2],st.val[i*2+1]);
	
	FOR(i,Q) {
		if(T[i]==1) {
			x=lower_bound(ALL(cand),L[i])-cand.begin();
			st.update(x);
		}
		else {
			x=lower_bound(ALL(cand),L[i])-cand.begin();
			y=lower_bound(ALL(cand),R[i]+1)-cand.begin();
			Mat m=st.getval(x,y);
			cout<<m.v[0][1]<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
