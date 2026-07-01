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

int N,Q;
int X[202020],V[202020];
int W[202020];


int L[202020],R[202020];
ll ret[202020];
const int DI=350;
vector<pair<int,int>> ev[DI];

unordered_map<int,int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<int> Xs,Vs;
	FOR(i,N) {
		cin>>X[i]>>V[i];
		Xs.push_back(X[i]);
		Vs.push_back(V[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Vs));
	FOR(i,N) {
		x=lower_bound(ALL(Xs),X[i])-Xs.begin();
		y=lower_bound(ALL(Vs),V[i])-Vs.begin();
		W[x]=y;
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
		R[i]=lower_bound(ALL(Xs),R[i]+1)-Xs.begin();
		if(R[i]>L[i]) {
			ev[L[i]/DI].push_back({R[i],i});
		}
	}
	FOR(i,DI) {
		sort(ALL(ev[i]));
		C.clear();
		int CL=i*DI;
		int CR=i*DI;
		ll cur=0;
		FORR2(r,c,ev[i]) {
			while(L[c]<CL) {
				cur+=CR-CL+1;
				CL--;
				cur-=C[W[CL]]++;
			}
			while(CR<R[c]) {
				cur+=CR-CL+1;
				cur-=C[W[CR]]++;
				CR++;
			}
			while(L[c]>CL) {
				cur+=--C[W[CL]];
				CL++;
				cur-=CR-CL+1;
			}
			ret[c]=cur;
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
