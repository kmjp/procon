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
BIT<ll,20> AX,B;

int N;
ll A[202020],T[202020];
int Q;
ll D[202020],L[202020],R[202020],ret[202020];

vector<pair<int,int>> ev;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>T[i];
		B.add(i,A[i]);
		if(A[i]) {
			ev.push_back({T[i],i});
			ev.push_back({T[i]+A[i],i});
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>D[i]>>L[i]>>R[i];
		L[i]--,R[i]--;
		ev.push_back({D[i],N+i});
	}
	sort(ALL(ev));
	FORR2(t,i,ev) {
		if(i<N) {
			if(t==T[i]) {
				B.add(i,T[i]-1);
				AX.add(i,-1);
			}
			else {
				B.add(i,-A[i]-T[i]+1);
				AX.add(i,1);
			}
		}
		else {
			i-=N;
			ret[i]=t*(AX(R[i])-AX(L[i]-1))+B(R[i])-B(L[i]-1);
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
