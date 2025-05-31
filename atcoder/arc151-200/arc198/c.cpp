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
int A[101],B[101];
vector<int> E[2][2];

vector<pair<int,int>> ret;
void go(int a,int b) {
	assert(a<b);
	ret.push_back({a+1,b+1});
	swap(A[a],A[b]);
	A[a]--;
	A[b]++;
	int i;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=0;
	FOR(i,N) {
		cin>>A[i];
		x+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		x-=B[i];
		E[A[i]%2][B[i]%2].push_back(i);
	}
	if(x) {
		cout<<"No"<<endl;
		return;
	}
	
	if(N==2) {
		if(A[0]!=B[0]) {
			go(0,1);
		}
		if(A[0]!=B[0]) {
			cout<<"No"<<endl;
			return;
		}
	}
	else {
		for(i=N-1;i>=2;i--) {
			while(A[i]!=B[i]) {
				x=A[i]-B[i];
				if(x>0) {
					int ma=min(x+1,i);
					FOR(j,ma) {
						go(i-1-j,i-j);
					}
					go(i-ma,i);
					continue;
				}
				if(x<0) {
					int ma=min(abs(x)+1,i);
					go(i-ma,i);
					FOR(j,ma) {
						go(i-ma+j,i-ma+j+1);
					}
				}
			}
		}
		while(A[0]<B[0]) {
			go(0,1);
			go(0,2);
			go(1,2);
			go(0,2);
		}
		while(A[0]>B[0]) {
			go(1,2);
			go(0,2);
			go(1,2);
			go(0,1);
		}
	}
	
	
	FOR(i,N) assert(A[i]==B[i]);
	cout<<"Yes"<<endl;
	cout<<ret.size()<<endl;
	FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
