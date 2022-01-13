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


int H,W,A,Q;
map<int,int> R,RT,C,CT;

ll ret[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>H>>W>>A>>Q;
	FOR(i,Q) {
		int t,n,c;
		cin>>t>>n>>c;
		n--;
		if(t==1) {
			RT[n]=i;
			R[n]=c;
		}
		else {
			CT[n]=i;
			C[n]=c;
		}
	}
	
	vector<pair<int,int>> V;
	FORR2(a,t,RT) V.push_back({-t,a});
	FORR2(a,t,CT) V.push_back({-t,a+H});
	
	sort(ALL(V));
	int CH=H,CW=W;
	FORR2(a,x,V) {
		if(x<H) {
			ret[R[x]]+=CW;
			CH--;
		}
		else {
			x-=H;
			ret[C[x]]+=CH;
			CW--;
		}
	}
	
	for(i=1;i<=A;i++) cout<<ret[i]<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
