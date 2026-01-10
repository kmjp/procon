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

int H,W;
ll A[101010],B[101010];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	map<int,int> As,Bs;
	FOR(i,H) cin>>A[i];
	FOR(i,W) cin>>B[i];
	sort(A,A+H);
	sort(B,B+W);
	ll retma=0;
	int CH=0,CW=0;
	while(CH<H&&CW<W) {
		if(A[CH]<=B[CW]) (retma+=A[CH++]*(W-CW))%=mo;
		else (retma+=B[CW++]*(H-CH))%=mo;
	}
	
	ll retmi=0;
	CH=H,CW=W;
	while(CH||CW) {
		if(CH&&CW) {
			if(A[CH-1]==B[CW-1]) {
				retmi+=A[--CH];
				CW--;
			}
			else if(A[CH-1]>B[CW-1]) {
				retmi+=A[--CH];
			}
			else {
				retmi+=B[--CW];
			}
		}
		else if(CH) {
			retmi+=A[--CH];
		}
		else {
			retmi+=B[--CW];
		}
	}
	
	
	cout<<retmi%mo<<endl;
	cout<<retma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
