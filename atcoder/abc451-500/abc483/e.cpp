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
string S;
unordered_map<string,int> num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll ret=0;
	FOR(i,N) {
		cin>>S;
		
		ll n0=num[S];
		ll n1=0,n2=0;
		FOR(x,M) {
			string V=S;
			V[x]='_';
			n1+=num[V];
			FOR(y,x) {
				string W=V;
				W[y]='_';
				n2+=num[W];
			}
		}
		n1-=M*n0;
		n2-=M*(M-1)/2*n0;
		n2-=(M-1)*n1;
		ret+=n0+n1+n2;
		
		num[S]++;
		FOR(x,M) {
			string V=S;
			V[x]='_';
			num[V]++;
			FOR(y,x) {
				string W=V;
				W[y]='_';
				num[W]++;
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
