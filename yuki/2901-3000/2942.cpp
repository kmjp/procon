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

int N,Q,L;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>L;
	FOR(i,N) {
		cin>>x;
		num.add(x,1);
		sum.add(x,x);
	}
	int did=0;
	FOR(i,Q) {
		cin>>j;
		if(j==1) {
			cin>>x;
			num.add(x,1);
			sum.add(x,x);
		}
		else if(j==2) {
			cin>>x>>y;
			cout<<num(y)-num(x-1)<<" "<<sum(y)-sum(x-1)<<endl;
			did=1;
		}
		else {
			cin>>x;
			L=x;
		}
	}
	if(did==0) cout<<"Not Found!"<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
