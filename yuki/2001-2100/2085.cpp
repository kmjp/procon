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

queue<int> merge(int L,int R) {
	queue<int> V;
	if(L+1==R) {
		V.push(L);
		return V;
	}
	auto P=merge(L,(L+R)/2);
	auto Q=merge((L+R)/2,R);
	
	while(P.size()||Q.size()) {
		if(P.empty()) {
			V.push(Q.front());
			Q.pop();
		}
		else if(Q.empty()) {
			V.push(P.front());
			P.pop();
		}
		else {
			cout<<"? "<<P.front()<<" "<<Q.front()<<endl;
			int r;
			cin>>r;
			if(r==1) {
				V.push(P.front());
				P.pop();
			}
			else {
				V.push(Q.front());
				Q.pop();
			}
		}
	}
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	auto p=merge(1,N+1);
	cout<<"!"<<endl;
	cout<<p.size()-1<<endl;
	while(p.size()) {
		cout<<p.front()<<" ";
		p.pop();
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
