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

int H,W;
string S[101];
string T[101];
int K;
int R[10100],C[10100];
string A[10101],B[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		T[y]=S[y];
	}
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if((y==0||S[y-1][x]=='#')&&y+1<H&&S[y+1][x]=='.') V.push_back({y+1,x+1});
		if((x==0||S[y][x-1]=='#')&&x+1<W&&S[y][x+1]=='.') V.push_back({y+1,x+1});
	}
	V.erase(unique(ALL(V)),V.end());
	
	cin>>K;
	if(K!=V.size()) {
		cout<<"No"<<endl;
		return;
	}
	FOR(i,K) {
		cin>>B[i]>>A[i];
		y=V[i].first-1,x=V[i].second-1;
		if((y==0||S[y-1][x]=='#')&&y+1<H&&S[y+1][x]=='.') {
			FOR(j,A[i].size()) {
				if(y+j>=H) {
					cout<<"No"<<endl;
					return;
				}
				T[y+j][x]=A[i][j];
			}
		}
		else {
			if(A[i]!="-") {
				cout<<"No1"<<endl;
				return;
			}
		}
		
		if((x==0||S[y][x-1]=='#')&&x+1<W&&S[y][x+1]=='.') {
			FOR(j,B[i].size()) {
				if(x+j>=W) {
					cout<<"No"<<endl;
					return;
				}
				T[y][x+j]=B[i][j];
			}
		}
		else {
			if(B[i]!="-") {
				cout<<"No2"<<endl;
				return;
			}
		}
	}
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='#'&&T[y][x]!=S[y][x]) {
			cout<<"No"<<endl;
			return;
		}
		if(T[y][x]=='.') {
			cout<<"No"<<endl;
			return;
		}
	}
	FOR(i,K) {
		cin>>A[i]>>B[i];
		y=V[i].first-1,x=V[i].second-1;
		if((y==0||S[y-1][x]=='#')&&y+1<H&&S[y+1][x]=='.') {
			FOR(j,A[i].size()) {
				if(T[y+j][x]!=A[i][j]) {
					cout<<"No"<<endl;
					return;
				}
			}
			if(y+j<H&&T[y+j][x]!='#') {
				cout<<"No"<<endl;
				return;
				
			}
		}
		
		if((x==0||S[y][x-1]=='#')&&x+1<W&&S[y][x+1]=='.') {
			FOR(j,B[i].size()) {
				if(T[y][x+j]!=B[i][j]) {
					cout<<"No"<<endl;
					return;
				}
			}
			if(x+j<W&&T[y][x+j]!='#') {
				cout<<"No"<<endl;
				return;
				
			}
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
