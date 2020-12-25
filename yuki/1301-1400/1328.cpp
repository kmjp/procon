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
int A[202020],B[202020];
int Y[202020];

vector<int> C[2][2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>s;
		A[i]=s=="B";
		cin>>s;
		B[i]=s=="B";
		cin>>Y[i];
		C[A[i]][B[i]][Y[i]].push_back(i+1);
	}
	
	int a=0,b=0;
	vector<int> R;
	while(a+b<N) {
		if(C[1][0][a].size()&&C[0][1][b].empty()&&C[1][1][b].empty()) {
			R.push_back(C[1][0][a].back());
			C[1][0][a].pop_back();
			b++;
		}
		else if(C[0][1][b].size()&&C[0][0][a].empty()&&C[1][0][a].empty()) {
			R.push_back(C[0][1][b].back());
			C[0][1][b].pop_back();
			a++;
		}
		else if(C[1][1][b].size()==1&&C[0][1][b].empty()) {
			R.push_back(C[1][1][b][0]);
			C[1][1][b].clear();
			b++;
		}
		else if(C[0][0][a].size()==1&&C[1][0][a].empty()) {
			R.push_back(C[0][0][a][0]);
			C[0][0][a].clear();
			a++;
		}
		else {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	FOR(i,N) {
		if(i) cout<<" ";
		cout<<R[i];
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
