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

int T,N,K;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		int C[11]={};
		FOR(i,N) {
			cin>>x;
			C[x]++;
		}
		int ret=0;
		if(K==2) {
			if(C[2]||C[4]||C[6]||C[8]||C[10]) ret=0;
			else ret=1;
		}
		else if(K==3) {
			if(C[3]||C[6]||C[9]) ret=0;
			else if(C[2]||C[5]||C[8]) ret=1;
			else ret=2;
		}
		else if(K==5) {
			ret=4;
			for(i=1;i<=10;i++) if(C[i]) ret=min(ret,(5-i%5)%5);
		}
		else {
			int num=0;
			num+=C[2]+C[4]*2+C[6]+C[8]*3+C[10];
			if(num==0) {
				if(C[3]||C[7]) ret=1;
				else if(C[1]+C[5]+C[9]>1) ret=2;
				else ret=3;
			}
			else if(num==1) {
				if(C[1]||C[3]||C[5]||C[7]||C[9]) ret=1;
				else ret=2;
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
