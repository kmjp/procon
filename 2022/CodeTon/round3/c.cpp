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

int T,N;
string A,B;
int S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N) S[i]=0;
		vector<pair<int,int>> V;
		int num=0;
		FOR(i,N) if(A[i]=='1') {
			num^=1;;
			S[i]=1;
			V.push_back({i,i});
		}
		FOR(i,N) B[i]^=(S[i]^num);
		int sum=0;
		FOR(i,N) sum+=B[i]-'0';
		
		if(sum==0) {
			;
		}
		else if(sum==N) {
			V.push_back({0,0});
			V.push_back({1,N-1});
			V.push_back({0,N-1});
		}
		else {
			cout<<"NO"<<endl;
			continue;
		}
		
		
		cout<<"YES"<<endl;
		cout<<V.size()<<endl;
		FORR2(a,b,V) cout<<a+1<<" "<<b+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
