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
BIT<ll,20> sum,num;
ll VV[101010];
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(VV);
	cin>>N;
	cin>>Q;
	FOR(i,Q) {
		int T,X,Y,V;
		cin>>T>>X>>Y>>V;
		if(T==0) {
			if(VV[X]==-1) {
				VV[X]=V;
				num.add(X,1);
				if(X%2==0) sum.add(X,V);
				else sum.add(X,-V);
			}
		}
		else {
			if(num(Y-1)-num(X-1)!=(Y-1)-(X-1)) {
				cout<<"Ambiguous"<<endl;
				continue;
			}
			if(X==Y) {
				cout<<V<<endl;
			}
			else if(X<Y) {
				ll a=sum(Y-1)-sum(X-1);
				if(X%2==Y%2) {
					if(X%2==0) a=-a;
					cout<<V+a<<endl;
				}
				else {
					if(X%2==1) a=-a;
					cout<<a-V<<endl;
				}
			}
			else {
				ll a=sum(X-1)-sum(Y-1);
				if(X%2==Y%2) {
					if(Y%2==1) a=-a;
					cout<<V+a<<endl;
				}
				else {
					if(Y%2==1) a=-a;
					cout<<a-V<<endl;
				}
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
