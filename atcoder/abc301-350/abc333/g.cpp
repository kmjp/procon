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

string S;
ll R,V,N;

int cmp(pair<__int128,__int128> a,pair<__int128,__int128> b) {
	__int128 x=(__int128)a.first*b.second;
	__int128 y=(__int128)b.first*a.second;
	if(x==y) return 0;
	if(x<y) return -1;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>N;
	S+="0000000000000000";
	FOR(i,18) R=R*10+(S[i+2]-'0');
	V=1000000000000000000LL;
	ll A1=0,B1=1;
	ll A2=1,B2=1;
	
	while(1) {
		ll A3=A1+A2;
		ll B3=B1+B2;
		if(B3>N) {
			__int128 d1=(__int128)R*B1-(__int128)A1*V;
			__int128 e1=(__int128)V*B1;
			__int128 d2=(__int128)A2*V-(__int128)R*B2;
			__int128 e2=(__int128)V*B2;
			
			
			if(cmp({d1,e1},{d2,e2})<=0) {
				cout<<A1<<" "<<B1<<endl;
			}
			else {
				cout<<A2<<" "<<B2<<endl;
			}
			return;
		}
		else {
			x=cmp({A3,B3},{R,V});
			if(x==0) {
				cout<<A3<<" "<<B3<<endl;
				return;
			}
			else if(x==-1) {
				//100‰ñ
				if(B2*100+B1<=N&&cmp({A2*100+A1,B2*100+B1},{R,V})<0) {
					A1=A2*100+A1;
					B1=B2*100+B1;
				}
				else {
					A1=A3;
					B1=B3;
				}
			}
			else if(x==1) {
				//100‰ñ
				if(B1*100+B2<=N&&cmp({A1*100+A2,B1*100+B2},{R,V})>0) {
					A2=A1*100+A2;
					B2=B1*100+B2;
				}
				else {
					A2=A3;
					B2=B3;
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
