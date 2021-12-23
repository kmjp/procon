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
string X;
set<int> ones;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	X=string(N,'0')+X;
	X=X.substr(X.size()-N);
	
	FOR(i,N) if(X[i]=='1') ones.insert(i);
	string R="1";
	FOR(i,N) {
		ones.erase(i);
		if(X[i]=='1') {
			if(i==N-1) break;
			if(ones.empty()) {
				R.push_back('0');
				i++;
				while(i<N-1) {
					R.push_back('1');
					i++;
				}
				break;
			}
			R.push_back('1');
		}
		else {
			if(ones.size()==1&&*ones.begin()==N-1) break;
			x=*ones.rbegin();
			ones.erase(x);
			R+='0';
			X[x]='0';
			for(j=x+1;j<N;j++) ones.insert(j), X[j]='1';
		}
	}
	reverse(ALL(R));
	while(R.size()&&R.back()=='0') R.pop_back();
	reverse(ALL(R));
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
