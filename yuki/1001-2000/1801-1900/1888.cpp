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
BIT<int,20> bt;

int N,P[202020],Q[202020];
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		Q[P[i]]=i;
	}
	
	FOR(i,N-1) {
		int y1=bt(Q[i]);
		int y2=bt(Q[i+1]);
		if(y1%2&&y2%2) {
			cout<<"No"<<endl;
			return;
		}
		if(y2%2==0) {
			if(y1%2||Q[i]<Q[i+1]) {
				swap(Q[i],Q[i+1]);
				swap(y1,y2);
			}
		}
		X[i]=P[Q[i]];
		Y[i]=y1;
		bt.add(Q[i],1);
	}
	X[N-1]=P[Q[N-1]];
	Y[N-1]=bt(Q[N-1]);
	if(Y[N-1]%2) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<X[i]+1<<" "<<Y[i]+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
