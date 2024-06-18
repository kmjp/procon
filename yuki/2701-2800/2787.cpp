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

ll N,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B>>C;
	vector<ll> A;
	while(N) {
		A.push_back(N%B);
		N/=B;
	}
	
	
	reverse(ALL(A));
	ll ret=2;
	while(A.size()&&ret<=C) {
		if(A.back()==0) {
			for(i=A.size()-1;i>=0;i--) {
				if(A[i]) {
					A[i]--;
					break;
				}
				else {
					A[i]=B;
				}
			}
			if(i==-1) break;
			ret+=2;
			
			B++;
		}
		else {
			ret+=A.back()*2;
			B+=A.back();
			A.back()=0;
		}
		
	}
	
	cout<<"Yes"<<endl;
	if(ret>C) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		cout<<ret<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
