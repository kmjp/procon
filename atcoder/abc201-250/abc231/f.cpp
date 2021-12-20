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
int A[202020],B[202020];
map<int,int> ev[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> As,Bs;
	FOR(i,N) {
		cin>>A[i];
		As.push_back(A[i]);
	}
	FOR(i,N) {
		cin>>B[i];
		Bs.push_back(B[i]);
	}
	sort(ALL(As));
	sort(ALL(Bs));
	vector<pair<int,int>> V;
	FOR(i,N) {
		A[i]=lower_bound(ALL(As),A[i])-As.begin();
		B[i]=lower_bound(ALL(Bs),B[i])-Bs.begin();
		ev[A[i]][B[i]]++;
	}
	
	ll sum=0;
	FOR(i,N) {
		FORR2(a,b,ev[i]) {
			bt.add(a,b);
		}
		FORR2(a,b,ev[i]) {
			sum+=1LL*b*(bt(N)-bt(a-1));
		}
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
