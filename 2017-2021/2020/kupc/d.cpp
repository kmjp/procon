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
vector<int> V[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N%2==0) {
		if(N==2) {
			cout<<"impossible"<<endl;
		}
		else {
			cout<<N/2<<endl;
			FOR(i,N/2) {
				cout<<2<<" "<<(i*2+1)<<" "<<(2*N-(i*2+1))<<endl;
			}
			
		}
	}
	else {
		
		for(x=3;x<N;x+=2) if(N%x==0) {
			y=N/x;
			FOR(i,x) {
				FOR(j,x) {
					V[j].push_back((i*x*2+(i+j)%x*2+1));
				}
			}
			int L=x*x*2+1,R=2*N-1;
			i=0;
			while(L<R) {
				i%=2*x;
				if(i<x) y=i;
				else y=2*x-1-i;
				V[y].push_back(L);
				V[y].push_back(R);
				L+=2,R-=2;
				i++;
			}
			cout<<x<<endl;
			FOR(i,x) {
				cout<<V[i].size();
				FORR(v,V[i]) cout<<" "<<v;
				cout<<endl;
			}
			return;
			
			
		}
		
		cout<<"impossible"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
