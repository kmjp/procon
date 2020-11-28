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
int M[4];
vector<int> V[4];
char from[101][101][101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,4) cin>>M[i];
	if(M[0]+M[1]+M[2]+M[3]!=3*N) return _P("No\n");
	
	FOR(i,4) {
		FOR(j,M[i]) {
			cin>>x;
			V[i].push_back(x);
		}
	}
	
	MINUS(from);
	from[0][0][0][0]=0;
	int I[4];
	vector<int> cand;
	FOR(i,4) cand.push_back(i);
	
	FOR(i,N) {
		FOR(I[0],M[0]+1) FOR(I[1],M[1]+1) FOR(I[2],M[2]+1) {
			I[3]=3*i-I[0]-I[1]-I[2];
			if(I[3]>=0 && I[3]<=M[3] && from[I[0]][I[1]][I[2]][I[3]]!=-1) {
				do {
					int ok=1;
					if(I[cand[0]]==M[cand[0]] || V[cand[0]][I[cand[0]]]!=1) ok=0;
					if(I[cand[1]]==M[cand[1]] || V[cand[1]][I[cand[1]]]!=2) ok=0;
					if(I[cand[2]]==M[cand[2]] || V[cand[2]][I[cand[2]]]!=3) ok=0;
					
					if(ok) from[I[0]+(cand[3]!=0)][I[1]+(cand[3]!=1)][I[2]+(cand[3]!=2)][I[3]+(cand[3]!=3)]=cand[3];
					
				} while(next_permutation(ALL(cand)));
				
			}
		}
	}
	
	if(from[M[0]][M[1]][M[2]][M[3]]==-1) {
		cout<<"No"<<endl;
	}
	else {
		vector<int> ret;
		FOR(i,N) {
			x=from[M[0]][M[1]][M[2]][M[3]];
			ret.push_back(x+1);
			M[0]-=(x!=0);
			M[1]-=(x!=1);
			M[2]-=(x!=2);
			M[3]-=(x!=3);
		}
		reverse(ALL(ret));
		cout<<"Yes"<<endl;
		FORR(r,ret) cout<<r<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
