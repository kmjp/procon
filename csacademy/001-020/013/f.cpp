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
int V[101010];
int L[101010];
int R[101010];
const int D=400;
vector<pair<int,int>> E[1000];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,18> tot;
BIT<int,18> num;
ll TV,TOT2;
double ret[101010];

void add(int t) {
	TV += 2*(TOT2-tot(t));
	TV += 2LL*num(t)*t+t;
	num.add(t,1);
	tot.add(t,t);
	TOT2+=t;
}
void del(int t) {
	num.add(t,-1);
	tot.add(t,-t);
	TOT2-=t;
	TV -= 2*(TOT2-tot(t));
	TV -= 2LL*num(t)*t+t;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>V[i+1];
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		E[L[i]/D].push_back({R[i],i});
	}
	FOR(i,D) {
		sort(ALL(E[i]));
		x=1;
		y=0;
		TV=TOT2=0;
		ZERO(num.bit);
		ZERO(tot.bit);
		FORR(r,E[i]) {
			j=r.second;
			if(x>y) x=L[j],y=L[j]-1;
			while(y<R[j]) add(V[++y]);
			while(y>R[j]) del(V[y--]);
			while(x<L[j]) del(V[x++]);
			while(x>L[j]) add(V[--x]);
			ret[j]=TV / ((R[j]-L[j]+1.0)*(R[j]-L[j]+1.0));
		}
		
		
	}
	
	FOR(i,Q) _P("%.12lf\n",ret[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
