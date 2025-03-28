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
int R,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>R>>B;
		if(R%2) {
			cout<<"No"<<endl;
			continue;
		}
		if(B==0) {
			cout<<"Yes"<<endl;
			FOR(x,R/2) cout<<"R "<<3<<" "<<3+x<<endl;
			for(x=R/2-1;x>=0;x--) cout<<"R "<<4<<" "<<3+x<<endl;
		}
		else if(R==0) {
			if(B%2) {
				cout<<"No"<<endl;
			}
			else {
				cout<<"Yes"<<endl;
				FOR(x,B/2) cout<<"B "<<3+x<<" "<<3+x<<endl;
				for(x=B/2-1;x>=0;x--) cout<<"B "<<2+x<<" "<<4+x<<endl;
			}
		}
		else {
			cout<<"Yes"<<endl;
			FOR(i,R/2) cout<<"R "<<1000000-i<<" "<<1000000<<endl;
			for(i=R/2-1;i>=0;i--) cout<<"R "<<1000000-i<<" "<<1000001<<endl;
			if(B%2==0) {
				FOR(i,B/2) cout<<"B "<<1000000+i<<" "<<1000002+i<<endl;
				for(i=B/2-1;i>=0;i--) cout<<"B "<<1000001+i<<" "<<1000001+i<<endl;
			}
			else {
				FOR(i,B/2+1) cout<<"B "<<1000001+i<<" "<<1000001-i<<endl;
				for(i=B/2-1;i>=0;i--) cout<<"B "<<1000001+i<<" "<<999999-i<<endl;
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
