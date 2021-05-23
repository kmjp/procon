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
deque<int> Q;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	for(i=1;i<=N;i++) {
		char c=S[i-1];
		if(c=='L') Q.push_front(i);
		if(c=='R') Q.push_back(i);
		if(c=='A'||c=='D') {
			if(Q.size()==0) {
				cout<<"ERROR"<<endl;
			}
			else if(c=='A') {
				cout<<Q[0]<<endl;
				Q.pop_front();
			}
			else {
				cout<<Q[Q.size()-1-0]<<endl;
				Q.pop_back();
			}
		}
		if(c=='B'||c=='E') {
			if(Q.size()<2) {
				cout<<"ERROR"<<endl;
			}
			else if(c=='B') {
				x=Q[0];
				cout<<Q[1]<<endl;
				Q.pop_front();
				Q.pop_front();
				Q.push_front(x);
			}
			else {
				x=Q[Q.size()-1-0];
				cout<<Q[Q.size()-1-1]<<endl;
				Q.pop_back();
				Q.pop_back();
				Q.push_back(x);
			}
		}
		if(c=='C'||c=='F') {
			if(Q.size()<3) {
				cout<<"ERROR"<<endl;
			}
			else if(c=='C') {
				x=Q[0];
				y=Q[1];
				cout<<Q[2]<<endl;
				Q.pop_front();
				Q.pop_front();
				Q.pop_front();
				Q.push_front(y);
				Q.push_front(x);
			}
			else {
				x=Q[Q.size()-1-0];
				y=Q[Q.size()-1-1];
				cout<<Q[Q.size()-1-2]<<endl;
				Q.pop_back();
				Q.pop_back();
				Q.pop_back();
				Q.push_back(y);
				Q.push_back(x);
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
