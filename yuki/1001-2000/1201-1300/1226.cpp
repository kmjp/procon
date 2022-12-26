#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<int NV> class SegTree_1 {
public:
	vector<vector<double>> V;
	vector<double> comp(vector<double> a,vector<double> b) {
		vector<double> c(3);
		c[2]=a[2]+b[2];
		c[0]=a[0]+b[0]*cos(a[2])-b[1]*sin(a[2]);
		c[1]=a[1]+b[0]*sin(a[2])+b[1]*cos(a[2]);
		return c;
		
	}
	
	SegTree_1(){
		V.resize(NV*2);
		int i;
		for(i=NV;i<2*NV;i++) V[i]={1,0,0};
		for(i=NV-1;i>=1;i--) {
			V[i]=comp(V[2*i],V[2*i+1]);
		}
	};
	vector<double> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0};
		if(x<=l && r<=y) return V[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int L,int D) {
		entry += NV;
		V[entry][2]=D*2*atan(1)*4/360;
		V[entry][0]=L*cos(V[entry][2]);
		V[entry][1]=L*sin(V[entry][2]);
		while(entry>1) entry>>=1, V[entry]=comp(V[entry*2],V[entry*2+1]);
	}
};

int L[101010];
int D[101010];
SegTree_1<1<<20> st;
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) L[i]=1;
	while(Q--) {
		cin>>i;
		if(i==0||i==1) {
			cin>>x>>y;
			x--;
			if(i==0) D[x]=y;
			if(i==1) L[x]=y;
			st.update(x,L[x],D[x]);
		}
		else {
			cin>>x;
			auto a=st.getval(0,x);
			_P("%.12lf %12lf\n",a[0],a[1]);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
