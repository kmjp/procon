#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[101];
int last[101];
string R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) {
		cin>>A[i];
		N+=A[i];
	}
	
	if(*max_element(A,A+K)>*min_element(A,A+K)*2) return _P("-1\n");
	MINUS(last);
	while(R.size()<N) {
		/*
		cout<<"!"<<R.size()<<" ";
		FOR(i,4) cout<<A[i]<<" ";
		cout<<endl;
		*/
		string tar;
		tar.push_back(120);
		for(int len=1;len<=K;len++) {
			if(R.size()+len<K) continue;
			if(R.size()+len>N) continue;
			
			int B[101];
			int did[101]={};
			FOR(i,K) B[i]=A[i];
			FOR(i,K-len) did[R[R.size()-1-i]]=1;
			string cand;
			FOR(i,K) if(did[i]==0) cand.push_back(i),B[i]--;
			x=*max_element(B,B+K);
			y=*min_element(B,B+K);
			if(y<0 || x>2*y+1) continue;
			
			if(x==2*y+1) {
				string AA,BB,CC;
				FOR(i,K) if(did[i]==0) {
					if(B[i]==x) AA.push_back(i);
					else if(B[i]==y) BB.push_back(i);
					else CC.push_back(i);
				}
				int ok=1;
				FOR(i,K) if(did[i]==0 && B[i]==x) {
					FOR(j,K) if(did[i]&&B[j]==y) ok=0;
				}
				if(ok==0) continue;
				cand.clear();
				while(AA.size()+BB.size()+CC.size()) {
					if(AA.size()) {
						if(CC.size()&&CC[0]<AA[0]) {
							cand+=CC[0];
							CC.erase(CC.begin());
						}
						else {
							cand+=AA[0];
							AA.erase(AA.begin());
						}
					}
					else if(BB.size()) {
						if(CC.size()&&CC[0]<BB[0]) {
							cand+=CC[0];
							CC.erase(CC.begin());
						}
						else {
							cand+=BB[0];
							BB.erase(BB.begin());
						}
					}
					else {
						cand+=CC[0];
						CC.erase(CC.begin());
					}
				}
				
			}
			tar=min(tar,cand);
		}
		
		//cout<<"#"<<tar.size()<<endl;
		R+=tar;
		FORR(a,tar) A[a]--;
	}
	
	FORR(c,R) cout<<((int)c+1)<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
