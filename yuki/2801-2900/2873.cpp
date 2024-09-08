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
ll P,Q,R,S;
ll X[202020],Y[202020];
map<int,int> Xs,Ys;


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt1,bt2;

bool cmp(vector<ll>& L,vector<ll>& R) {
	ll a=L[1]*R[0]-L[0]*R[1];
	if(a<0) return 1;
	if(a>0) return 0;
	return L[2]<R[2];
}
bool cmp2(vector<ll>& L,vector<ll>& R) {
	ll a=L[1]*R[0]-L[0]*R[1];
	if(a>0) return 1;
	if(a<0) return 0;
	return L[2]<R[2];
}
bool cmp3(vector<ll>& L,vector<ll>& R) {
	ll a=L[1]*R[0]-L[0]*R[1];
	if(a>=0) return 1;
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> YY={-1<<30};
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		YY.push_back(Y[i]);
		Xs[X[i]]++;
		Ys[Y[i]]++;
	}
	FORR2(a,b,Xs) R+=b*(N-b);
	FORR2(a,b,Ys) S+=b*(N-b);
	sort(ALL(YY));
	YY.erase(unique(ALL(YY)),YY.end());
	
	vector<pair<int,int>> Ps[2];
	
	FOR(i,N) {
		Y[i]=lower_bound(ALL(YY),Y[i])-YY.begin();
		Ps[0].push_back({-X[i],Y[i]});
		Ps[1].push_back({X[i],Y[i]});
	}
	
	sort(ALL(Ps[0]));
	sort(ALL(Ps[1]));
	FORR2(x,y,Ps[0]) {
		P+=bt1(N)-bt1(y);
		bt1.add(y,1);
	}
	FORR2(x,y,Ps[1]) {
		Q+=bt2(N)-bt2(y);
		bt2.add(y,1);
	}
	
	
	
	R/=2;
	S/=2;
	double a=R;
	a*=S;
	a=sqrt(a);
	double b=P-Q;
	//cout<<P<<" "<<Q<<" "<<R<<" "<<S<<endl;
	_P("%.12lf\n",b/a);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
