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

int N;
int L[202020],U[202020];

int Q;
int SY[202020],SX[202020],TY[202020],TX[202020];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
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
template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
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
SegTree_ma<int,1<<20> sma;
SegTree_mi<int,1<<20> smi;

int getnext(int x,int y) {
	if(smi.getval(x+1,N)>=y&&sma.getval(x+1,N)<=y) return N-1;
	int i;
	for(i=20;i>=0;i--) if(x+(1<<i)+1<=N) if(smi.getval(x,x+(1<<i)+1)>=y&&sma.getval(x,x+(1<<i)+1)<=y) x+=1<<i;
	return x;
}

int nex[402020][20];
ll nexS[402020][20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) {
		cin>>L[x]>>U[x];
		sma.update(x,L[x]);
		smi.update(x,U[x]);
	}
	FOR(x,N) {
		y=getnext(x,L[x]);
		if(y==N-1) {
			nex[x*2][0]=2*N;
		}
		else {
			y++;
			if(U[y]<L[x]) {
				nex[x*2][0]=y*2+1;
				nexS[x*2][0]=L[x]-U[y];
			}
			else {
				nex[x*2][0]=y*2;
				nexS[x*2][0]=L[y]-L[x];
			}
		}
		y=getnext(x,U[x]);
		if(y==N-1) {
			nex[x*2+1][0]=2*N;
		}
		else {
			y++;
			if(U[x]<L[y]) {
				nex[x*2+1][0]=y*2;
				nexS[x*2+1][0]=L[y]-U[x];
			}
			else {
				nex[x*2+1][0]=y*2+1;
				nexS[x*2+1][0]=U[x]-U[y];
			}
		}
	}
	FOR(i,19) {
		nex[2*N][i]=2*N;
		FOR(j,2*N+1) {
			nex[j][i+1]=nex[nex[j][i]][i];
			nexS[j][i+1]=nexS[nex[j][i]][i]+nexS[j][i];
		}
	}
	
	
	
	cin>>Q;
	FOR(i,Q) {
		cin>>SX[i]>>SY[i]>>TX[i]>>TY[i];
		SX[i]--,TX[i]--;
		if(TX[i]<SX[i]) swap(SX[i],TX[i]),swap(TY[i],SY[i]);
		ll ret=TX[i]-SX[i];
		int ne=getnext(SX[i],SY[i]);
		if(ne>=TX[i]) {
			ret+=abs(TY[i]-SY[i]);
		}
		else {
			if(SY[i]<L[ne+1]) {
				ret+=L[ne+1]-SY[i];
				ne=(ne+1)*2;
			}
			else {
				ret+=SY[i]-U[ne+1];
				ne=(ne+1)*2+1;
			}
			
			for(j=19;j>=0;j--) if(nex[ne][j]/2<TX[i]) {
				ret+=nexS[ne][j];
				ne=nex[ne][j];
			}
			SX[i]=ne/2;
			SY[i]=(ne%2)?U[ne/2]:L[ne/2];
			ret+=abs(TY[i]-SY[i]);
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
