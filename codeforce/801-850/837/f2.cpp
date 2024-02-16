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
int A[202020];
ll H[202020];


std::random_device rnd;
std::mt19937 mt(rnd());

vector<int> As;
int nex;
int root[202020];
int L[202020<<5],R[202020<<5];
ll val[202020<<5];

int add(int cur,int CL,int CR,int V,ll XV) {
	int ncur=nex++;
	val[ncur]=val[cur];
	L[ncur]=L[cur];
	R[ncur]=R[cur];
	
	if(CL+1==CR) {
		val[ncur]^=XV;
	}
	else {
		int CM=(CL+CR)/2;
		if(V<CM) {
			L[ncur]=add(L[ncur],CL,CM,V,XV);
		}
		else {
			R[ncur]=add(R[ncur],CM,CR,V,XV);
		}
		val[ncur]=val[L[ncur]]^val[R[ncur]];
	}
	
	return ncur;
}
int get(int cur1,int cur2,int CL,int CR) {
	if(CL+1==CR) {
		if(val[cur1]^val[cur2]) return As[CL];
		else return 0;
	}
	int CM=(CL+CR)/2;
	
	if(val[L[cur1]]^val[L[cur2]]) return get(L[cur1],L[cur2],CL,CM);
	return get(R[cur1],R[cur2],CM,CR);
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	root[0]=nex++;
	cin>>N;
	As.push_back(0);
	FOR(i,N) {
		cin>>A[i];
		As.push_back(A[i]);
		H[i+1]=mt();
	}
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(As),A[i])-As.begin();
		root[i+1]=add(root[i],0,As.size(),A[i],H[A[i]]);
	}
	
	cin>>Q;
	int ans=0;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L=(L^ans)-1;
		R=(R^ans);
		ans=get(root[L],root[R],0,As.size());
		cout<<ans<<"\n";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
