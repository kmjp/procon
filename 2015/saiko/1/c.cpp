#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<ll> bitnum(ll L,ll R=-1) {
	if(R==-1) R=L,L=0;
	else L--;
	
	vector<ll> r;
	for(int i=0;i<=62;i++) {
		ll step=1LL<<i;
		r.push_back((R/(2*step)*step) + max(0LL,(R%(2*step))-(step-1)));
		r.back() -= (L/(2*step)*step) + max(0LL,(L%(2*step))-(step-1));
	}
	return r;
}

const int MAT=2;
struct Mat { long double v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]);
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

int T;
ll K,L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>K>>L>>R;
		auto v=bitnum(L,R);
		double ret=0;
		FOR(i,31) {
			long double p = v[i]*1.0/(R-(L-1));
			Mat m;
			m.v[0][0]=1-2*p;
			m.v[0][1]=p;
			m.v[1][0]=0;
			m.v[1][1]=1;
			auto m2=powmat(K,m);
			ret += pow(2,i)*m2.v[0][1];
		}
		
		_P("%.12lf\n",ret);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
