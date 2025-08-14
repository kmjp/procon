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

int N;
string S[101];
int T[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<string> R;
	cin>>N;
	FOR(i,N) cin>>S[i]>>T[i];
	FOR(i,10000) {
		string V="0000";
		V[0]+=i/1000;
		V[1]+=i/100%10;
		V[2]+=i/10%10;
		V[3]+=i%10;
		
		FOR(j,N) {
			int dif=0;
			FOR(x,4) dif+=S[j][x]!=V[x];
			if(T[j]==1&&dif) break;
			if(T[j]==2&&dif!=1) break;
			if(T[j]==3&&dif<=1) break;
		}
		if(j==N) R.push_back(V);
	}
	
	if(R.size()>1) {
		cout<<"Can't Solve"<<endl;
	}
	else {
		cout<<R[0]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
