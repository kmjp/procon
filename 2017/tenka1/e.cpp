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

int N;
int A[101010],B[101010],C[101010];
vector<pair<double,double>> P;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

BIT<int,17> bt;
ll hoge(double v) {
	ZERO(bt.bit);
	vector<pair<double,int>> V;
	int i;
	
	FOR(i,N) V.push_back({v*P[i].first+P[i].second,i});
	sort(ALL(V));
	ll ret=0;
	
	FORR(c,V) {
		ret+=bt(c.second);
		bt.add(c.second,1);
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i]>>C[i];
	
	FOR(i,2) {
		P.clear();
		FOR(j,N) {
			if(i==0) P.push_back({-1.0*A[j]/B[j],1.0*C[j]/B[j]});
			else P.push_back({-1.0*B[j]/A[j],1.0*C[j]/A[j]});
		}
		sort(ALL(P));
		
		double L=-1e9,R=1e9;
		FOR(j,100) {
			double M=(L+R)/2.0;
			if(hoge(M)<(1LL*N*(N-1)/2+1)/2) L=M;
			else R=M;
		}
		
		_P("%.12lf%c",L,(i==0)?' ':'\n');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
