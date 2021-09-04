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

int H,W,N;
int A[101010],B[101010];
vector<int> Y,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		Y.push_back(A[i]);
		X.push_back(B[i]);
	}
	sort(ALL(Y));
	sort(ALL(X));
	Y.erase(unique(ALL(Y)),Y.end());
	X.erase(unique(ALL(X)),X.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(Y),A[i])-Y.begin()+1;
		B[i]=lower_bound(ALL(X),B[i])-X.begin()+1;
		cout<<A[i]<<" "<<B[i]<<endl;
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
