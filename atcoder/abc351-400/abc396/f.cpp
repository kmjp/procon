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

int N,M;
int A[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

vector<int> cand[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll cur=0;
	FOR(i,N) {
		cin>>A[i];
		cand[M-A[i]-1].push_back(i);
		cur+=bt(M+1)-bt(A[i]);
		bt.add(A[i],1);
	}
	FOR(i,M) {
		cout<<cur<<endl;
		int num=0;
		FORR(a,cand[i]) {
			//Œã‚ë‚É‚ ‚é‚æ‚è¬‚³‚¢‚à‚Ì
			cur-=(N-1-a)-(cand[i].size()-(num+1));
			//‘O‚É‚ ‚é¬‚³‚¢‚à‚Ì
			cur+=a-num;
			num++;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
