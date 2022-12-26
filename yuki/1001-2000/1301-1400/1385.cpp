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
ll L;
ll T[505050];
double S[505050];
double C[505050];
double SS;
double SC;
double DS;
double DC;


void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>T[i];
		S[i]=sin(2*pi*T[i]/L);
		C[i]=cos(2*pi*T[i]/L);
		SS+=S[i];
		SC+=C[i];
		if(i>=2) {
			DS+=S[i]*(i-1);
			DC+=C[i]*(i-1);
		}
	}
	double ret=0;
	FOR(i,N) {
		ret+=S[i]*DC-C[i]*DS;
		DS-=SS;
		DC-=SC;
		DS+=S[i]*(N-1)+S[i+1];
		DC+=C[i]*(N-1)+C[i+1];
	}
	ret /= 2;
	ret /= 1LL*N*(N-1)*(N-2)/6;
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
