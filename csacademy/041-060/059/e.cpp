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

int T;
int A,B,M;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; };
ll mo;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M>>A>>B;
		mo=M;
		
		Mat nex={.v={{0,1},{1,1}}};
		Mat pre={.v={{M-1,1},{1,0}}};
		Mat E={.v={{1,0},{0,1}}};
		Mat preS=E,preS2=E;
		FOR(i,100000) {
			preS=mulmat(preS,pre);
		}
		map<pair<int,int>,ll> mp;
		FOR(i,100000) {
			int a=(preS2.v[0][0]*A+preS2.v[1][0]*B)%M;
			int b=(preS2.v[0][1]*A+preS2.v[1][1]*B)%M;
			if(mp.count({a,b})==0) mp[{a,b}]=100000LL*i;
			preS2=mulmat(preS2,preS);
		}
		ll mi=1LL<<60;
		FOR(i,100000) {
			int a=(E.v[0][0]*0+E.v[1][0]*1)%M;
			int b=(E.v[0][1]*0+E.v[1][1]*1)%M;
			if(mp.count({a,b})) {
				mi=min(mi,(i+mp[{a,b}]));
			}
			E=mulmat(E,nex);
		}
		if(mi==1LL<<60) mi=-1;
		cout<<mi<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
