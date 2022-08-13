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


ll N;
ll K;
ll A[50505],B[50505],C[50505];
int L[202020],R[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,17> bt;

ll hoge(double v) {
	
	vector<pair<double,int>> V;
	int i;
	FOR(i,N) {
		L[i]=R[i]=-1;
		double r=hypot(A[i],B[i]);
		double d=abs(C[i])/r;
		double D=(A[i]*A[i]+B[i]*B[i])*v*v-C[i]*C[i];
		if(D<=1e-8) continue;
		D=sqrt(D);
		double x1=(-A[i]*C[i]+B[i]*D)/(A[i]*A[i]+B[i]*B[i]);
		double y1=(-B[i]*C[i]-A[i]*D)/(A[i]*A[i]+B[i]*B[i]);
		double x2=(-A[i]*C[i]-B[i]*D)/(A[i]*A[i]+B[i]*B[i]);
		double y2=(-B[i]*C[i]+A[i]*D)/(A[i]*A[i]+B[i]*B[i]);
		V.push_back({atan2(y1,x1),i});
		V.push_back({atan2(y2,x2),i});
	}
	sort(ALL(V));
	ZERO(bt.bit);
	vector<pair<int,int>> len;
	FOR(i,V.size()) {
		bt.add(i,1);
		if(L[V[i].second]==-1) {
			L[V[i].second]=i;
		}
		else {
			R[V[i].second]=i;
			len.push_back({i-L[V[i].second],V[i].second});
		}
	}
	sort(ALL(len));
	ll sum=0;
	FORR2(a,x,len) {
		sum+=bt(R[x]-1)-bt(L[x]);
		bt.add(L[x],-1);
		bt.add(R[x],-1);
		
	}
	
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i]>>B[i]>>C[i];
	
	double L=0,R=1e9;
	FOR(i,60) {
		double M=(L+R)/2;
		if(hoge(M)<K) L=M;
		else R=M;
	}
	_P("%.12lf\n",L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
