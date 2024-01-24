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

int T,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>Q;
		ll HL=1,HR=1LL<<60;
		while(Q--) {
			ll A,B,N;
			cin>>i>>A>>B;
			if(i==1) {
				cin>>N;
				ll CL,CR;
				if(N==1) {
					CL=1;
					CR=A;
				}
				else {
					CL=(A-B)*(N-2)+A+1;
					CR=(A-B)*(N-1)+A;
				}
				if(max(CL,HL)<=min(CR,HR)) {
					cout<<1<<" ";
					HL=max(CL,HL);
					HR=min(CR,HR);
				}
				else {
					cout<<0<<" ";
				}
			}
			else {
				if(HR==1LL<<60) {
					cout<<-1<<" ";
				}
				else {
					ll a=(HL<=A)?1:(HL-A+(A-B-1))/(A-B)+1;
					ll b=(HR<=A)?1:(HR-A+(A-B-1))/(A-B)+1;
					if(a==b) {
						cout<<a<<" ";
					}
					else {
						cout<<-1<<" ";
					}
				}
			}
		}
		cout<<endl;
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
