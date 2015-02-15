#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

ll H,W;
int N;
ll S[20050],T[20050];
int mask[100001];

ll mo=1000000007;
map<ll,int> XM;
vector<ll> XM2;

const int MAT=4;
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int i,x,y,z;
	Mat r;
	FOR(x,n) FOR(y,n) {
		r.v[x][y]=0;
		FOR(z,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
		r.v[x][y] %= mo;
	}
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y,z;
	Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

const int NV=1<<17;
Mat val[NV*2];


Mat getmat(int h,int mask) {
	int x,y;
	Mat r;
	FOR(x,4) FOR(y,4) r.v[x][y]=0;
	r.v[0][0]=1;
	if(h==1) {
		if(mask==0) r.v[0][1]=r.v[1][0]=1;
	}
	else {
		if(mask==0) {
			r.v[0][0]=2;
			r.v[3][0]=1;
			r.v[2][1]=1;
			r.v[1][2]=1;
			r.v[0][3]=1;
		}
		if(mask==1 || mask==0) r.v[2][0]=r.v[0][2]=1;
		if(mask==2 || mask==0) r.v[1][0]=r.v[0][1]=1;
	}
	return r;
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>S[i]>>T[i];
		S[i]--,T[i]--;
		XM[T[i]]=XM[T[i]+1]=0;
	}
	XM[0]=XM[W]=0;
	ITR(it,XM) it->second=XM2.size(), XM2.push_back(it->first);
	FOR(i,NV) val[i+NV].v[0][0]=1;
	
	Mat b=getmat(H,0);
	FOR(i,XM.size()-1) val[i+NV] = powmat(XM2[i+1]-XM2[i],b);
	for(i=NV-1;i>=1;i--) val[i]=mulmat(val[i*2],val[i*2+1]);
	
	FOR(i,N) {
		x=XM[T[i]];
		mask[x]^=1<<S[i];
		val[x+NV]=getmat(H,mask[x]);
		x+=NV;
		while(x>1) x>>=1, val[x]=mulmat(val[x*2],val[x*2+1]);
		
		cout << val[1].v[0][0] << endl;
	}
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


