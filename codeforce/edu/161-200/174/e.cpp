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

int T,N;
string S;
int A,B,AB,BA;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		cin>>A>>B>>AB>>BA;
		vector<int> V[2][2];
		int C[2]={};
		x=-1;
		FORR(c,S) {
			C[c-'A']++;
			if(x==-1) {
				x=c-'A';
				y=1;
			}
			else if(c-'A'==(x+y)%2) {
				y++;
			}
			else {
				V[x][y%2].push_back(y);
				x=c-'A';
				y=1;
				
			}
		}
		V[x][y%2].push_back(y);
		
		int p=0;
		FOR(i,2) FORR(v,V[i][1]) p+=v/2;
		FOR(i,2) {
			sort(ALL(V[i][0]));
			FORR(v,V[i][0]) {
				if(i==0) {
					x=min(v/2,AB);
					v-=2*x;
					AB-=x;
					C[0]-=x;
					C[1]-=x;
				}
				else {
					x=min(v/2,BA);
					v-=2*x;
					BA-=x;
					C[0]-=x;
					C[1]-=x;
				}
			}
		}
		FOR(i,2) {
			FORR(v,V[i][0]) {
				if(i==0) {
					x=min(max(v/2-1,0),BA);
					v-=2*x;
					BA-=x;
					C[0]-=x;
					C[1]-=x;
				}
				else {
					x=min(max(v/2-1,0),AB);
					v-=2*x;
					AB-=x;
					C[0]-=x;
					C[1]-=x;
				}
			}
		}
		x=min(p,AB+BA);
		C[0]-=x;
		C[1]-=x;
		if(C[0]<=A&&C[1]<=B) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
