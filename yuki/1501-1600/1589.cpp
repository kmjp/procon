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

int N,K;
int T;
int B[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	int num=2;
	FOR(x,N) {
		for(y=N-2;y>=x;y--) {
			num+=5;
		}
	}
	cout<<num<<endl;
	
	FOR(x,N) {
		for(y=N-2;y>=x;y--) {
			cout<<"AND "<<N<<" "<<y<<" "<<y+1<<endl;
			cout<<"XOR "<<y<<" "<<y<<" "<<y+1<<endl;
			cout<<"UPD "<<y+1<<" 1"<<endl;
			cout<<"AND "<<y+1<<" "<<y+1<<" "<<N<<endl;
			cout<<"XOR "<<y<<" "<<y<<" "<<N<<endl;
		}
	}
	
	cout<<"UPD "<<N<<" 1"<<endl;
	cout<<"AND "<<N<<" "<<N<<" "<<(K-1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
