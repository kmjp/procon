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

int  T,N;
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		int L=101,R=-1,U=101,D=-111;
		
		set<int> XpY,XmY;
		
		
		FOR(y,N) {
			cin>>S[y];
			FOR(x,N) if(S[y][x]=='#') {
				L=min(L,x);
				R=max(R,x);
				U=min(U,y);
				D=max(D,y);
				XpY.insert(x+y);
				XmY.insert(x-y);
			}
		}
		if(L==101||(R-L<=1&&D-U<=1)||XpY.size()<=1||XmY.size()<=1) {
			cout<<"Yes"<<endl;
		}
		else if(XpY.size()==2&&*XpY.rbegin()-*XpY.begin()==1) {
			cout<<"Yes"<<endl;
		}
		else if(XmY.size()==2&&*XmY.rbegin()-*XmY.begin()==1) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
