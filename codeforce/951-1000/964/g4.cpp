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

int T;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int L=1,R=999;
		while(L+2<R) {
			int M1=(L*2+R)/3;
			int M2=(L+R*2)/3;
			cout<<"? "<<M1<<" "<<M2<<endl;
			cin>>x;
			if(x==(M1*M2)) {
				L=M2+1;
			}
			else if(x==M1*(M2+1)) {
				L=M1+1;
				R=M2;
			}
			else {
				R=M1;
			}
		}
		if(L<R) {
			int M1=L;
			int M2=L+1;
			cout<<"? "<<M1<<" "<<M2<<endl;
			cin>>x;
			if(x==(M1*M2)) {
				L+=2;
			}
			else if(x==M1*(M2+1)) {
				L++;
			}
		}
		cout<<"! "<<L<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
