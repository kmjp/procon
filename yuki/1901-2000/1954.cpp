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


int H,W,M;
string S[505];
vector<int> Rs,Cs;
int RT[202],CT[202];
int A[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			S[y][x]=(S[y][x]=='#')^((y+x)%2);
		}
	}
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		if(x==1) {
			if(y<H) Rs.push_back(y);
		}
		else {
			if(y<W) Cs.push_back(y);
		}
	}
	Rs.push_back(H);
	Cs.push_back(W);
	int NR=Rs.size();
	int NC=Cs.size();
	sort(ALL(Rs));
	sort(ALL(Cs));
	FOR(y,H) RT[y]=lower_bound(ALL(Rs),y+1)-Rs.begin();
	FOR(x,W) CT[x]=lower_bound(ALL(Cs),x+1)-Cs.begin();
	FOR(y,H) FOR(x,W) A[RT[y]][CT[x]]=S[y][x];
	FOR(y,H) FOR(x,W) if(A[RT[y]][CT[x]]!=S[y][x]) {
		cout<<"No"<<endl;
		return;
	}
	FOR(x,NC) if(A[0][x]) {
		FOR(y,NR) A[y][x]^=1;
	}
	
	FOR(y,NR) {
		FOR(x,NC) if(A[y][x]!=A[y][0]) {
			cout<<"No"<<endl;
			return;
		}
	}
	
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
