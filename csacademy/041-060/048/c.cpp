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

int N;
string S;
int cnt[10];

void small() {
	sort(ALL(S));
	string ret="z";
	int i;
	do {
		if(S[0]!='0') {
			int v=0;
			FOR(i,S.size()) v=v*10+S[i]-'0';
			
			if(v%8==0) ret=min(ret,S);
		}
		
	} while(next_permutation(ALL(S)));
	
	if(ret=="z") ret="-1";
	cout<<ret<<endl;
	
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) cnt[c-'0']++;
	
	if(S.size()<=3) {
		small();
		return;
	}
	
	string ret="z";
	FOR(x,10) if(cnt[x]) {
		cnt[x]--;
		FOR(y,10) if(cnt[y]) {
			cnt[y]--;
			FOR(z,10) if(cnt[z]) {
				cnt[z]--;
				
				if((x*100+y*10+z)%8) goto nex;
				if(x==0 && N==3) goto nex;
				if(cnt[0] && cnt[0]==N-3) goto nex;
				
				{
					string cand="";
					FOR(i,10) cand += string(cnt[i],'0'+i);
					
					if(cand.size() && cand[0]=='0') {
						FOR(i,cand.size()) if(cand[i]!='0') {
							swap(cand[0],cand[i]);
							break;
						}
					}
					cand += '0'+x;
					cand += '0'+y;
					cand += '0'+z;
					ret=min(ret,cand);
				}
				
				nex:
				cnt[z]++;
			}
			cnt[y]++;
		}
		cnt[x]++;
	}
	if(ret=="z") ret="-1";
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
