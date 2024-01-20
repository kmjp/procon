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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> num,sum;

int N;
const int ME=300001;
vector<int> E[ME];
int L[ME],R[ME],D[ME],P[ME],rev[ME],eid;
ll ret[202020];

void EulerTour(int cur,int pre=0,int d=0) {
	if(pre==-1) ZERO(L),ZERO(R),eid=0;
	rev[eid]=cur;
	P[cur]=pre;
	L[cur]=eid++;
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) EulerTour(e,cur,d+1);
	R[cur]=eid;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		num.add(i,1);
	}
	EulerTour(0,-1);
	
	for(i=N-1;i>=0;i--) {
		int tot=i;
		num.add(L[i],-1);
		FORR(e,E[i]) {
			if(L[e]>L[i]) {
				int tt=(num(R[e]-1)-num(L[e]-1));
				sum.add(0,tt);
				sum.add(L[e],-tt);
				sum.add(R[e],tt);
				sum.add(N,-tt);
			}
			else {
				int tt=tot-(num(R[i]-1)-num(L[i]-1));
				sum.add(L[i],tt);
				sum.add(R[i],-tt);
			}
		}
		
		
	}
	
	FOR(i,N) cout<<sum(L[i])<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
