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
ll A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		
		FOR(i,N) {
			if(A[i]*B[0]!=A[0]*B[i]) {
				cout<<"Yes"<<endl;
				vector<ll> X={A[0],B[0],A[i],B[i]};
				vector<ll> V={};
				FORR(x,X) {
					V.push_back(x);
					V.push_back(x+1);
					V.push_back(x-1);
					V.push_back(-x);
					V.push_back(-x+1);
					V.push_back(-x-1);
				}
				V.push_back(A[0]+B[0]);
				V.push_back(-(A[0]+B[0]));
				V.push_back(A[i]+B[i]);
				V.push_back(-(A[i]+B[i]));
				V.push_back(A[0]+B[i]);
				V.push_back(-(A[0]+B[i]));
				V.push_back(A[i]+B[0]);
				V.push_back(-(A[i]+B[0]));
				FORR(x,V) FORR(y,V) {
					if(A[0]*x+A[i]*y>0&&B[0]*x+B[i]*y<0) {
						FOR(j,N) {
							if(j==0) cout<<x<<" ";
							else if(j==i) cout<<y<<" ";
							else cout<<0<<" ";
						}
						cout<<endl;
						goto out;
					}
				}
				assert(0);
				out:
				break;
			}
		}
		if(i==N) {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
