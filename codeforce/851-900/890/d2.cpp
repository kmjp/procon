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
int N;

int bigger(int L,int R) {
	int a,b;
	if(L+2==R+1) a=0;
	else {
		cout<<"? "<<(L+2)<<" "<<(R+1)<<endl;
		cin>>a;
	}
	cout<<"? "<<(L+1)<<" "<<(R+1)<<endl;
	cin>>b;
	if(b-a==(R-L)) return L;
	else return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V;
		
		FOR(i,N) V.push_back(i);
		while(V.size()>1) {
			vector<int> W;
			for(i=0;i<V.size();i+=2) {
				if(i+1<V.size()) W.push_back(bigger(V[i],V[i+1]));
				else W.push_back(V[i]);
			}
			V=W;
		}
		cout<<"! "<<V[0]+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
