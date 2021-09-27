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
int P[555];

vector<int> R;
void go(int x) {
	swap(P[x],P[x+1]);
	R.push_back(x);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
		}
		R.clear();
		int step=0;
		
		for(i=N-1;i>=3;i--) {
			FOR(j,N) if(P[j]==i) break;
			if(j==i) continue;
			
			if(i==3&&j==2&&step==1) {
				go(1);
				go(2);
				j=1;
			}
			
			while(j<i) {
				if(step==j%2) {
					go(j);
					j++;
				}
				else if(step==0) {
					if(j==1) go(2);
					else go(0);
				}
				else {
					if(j==2) go(3);
					else go(1);
				}
				step^=1;
			}
		}
		
		while(1) {
			for(j=N-1;j>=0;j--) if(P[j]!=j) break;
			if(j<0) break;
			assert(j<3);
			swap(P[step],P[step+1]);
			R.push_back(step);
			step^=1;
		}
		
		
		
		
		cout<<R.size()<<endl;
		FOR(i,R.size()) {
			assert(R[i]%2==i%2);
			cout<<(R[i]+1)<<" ";
		}
		cout<<endl;
		FOR(i,N) assert(P[i]==i);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
