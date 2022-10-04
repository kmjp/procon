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
ll A,B;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>S;
		FORR(c,S) c-='0';
		ll ret=1LL<<60;
		if(A==0&&B==0) ret=0;
		FOR(i,4) {
			
			if(S[0]&&A>0&&B==0) chmin(ret,abs(A));
			if(S[1]&&A>0&&A==B) chmin(ret,abs(A));
			if(S[0]) {
				if(S[1]&&A>=0&&B>=0&&B<=A) chmin(ret,abs(A));
				if(S[2]&&A>=0&&B>=0) chmin(ret,abs(A)+abs(B));
				if(S[3]&&B>=0&&A+B>=0) chmin(ret,abs(B)+abs(A+B));
				if(S[5]&&B<=0&&A>=B) chmin(ret,abs(B)+abs(A-B));
				if(S[7]&&A>=0&&B<=0&&abs(A)>=abs(B)) chmin(ret,abs(A));
			}
			if(S[1]&&S[3]&&B>0&&abs(A)<=abs(B)&&(A+B)%2==0) chmin(ret,abs(B));
			
			int dx[4]={1,0,-1,0};
			int dy[4]={0,1,0,-1};
			FOR(j,4) if(S[j*2]) {
				ll A2=A-dx[j];
				ll B2=B-dy[j];
				if((A2+B2)%2) continue;
				if(S[1]&&S[3]&&B2>=0&&abs(A2)<=abs(B2)) chmin(ret,abs(B2)+1);
				if(S[1]&&S[7]&&A2>=0&&abs(A2)>=abs(B2)) chmin(ret,abs(A2)+1);
				if(S[5]&&S[3]&&A2<=0&&abs(A2)>=abs(B2)) chmin(ret,abs(A2)+1);
				if(S[5]&&S[7]&&B2<=0&&abs(A2)<=abs(B2)) chmin(ret,abs(B2)+1);
			}
			
			
			swap(A,B);
			B=-B;
			rotate(S.begin(),S.begin()+2,S.end());
		}
		
		if(ret==1LL<<60) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
