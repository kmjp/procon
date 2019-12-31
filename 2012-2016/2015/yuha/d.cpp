#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
map<string,int> MM;
string S[21];
int M,C,D;
int mat[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		MM[S[i]]=i;
	}
	cin>>M;
	FOR(i,M) {
		cin>>s>>t;
		mat[MM[s]][MM[t]]=1;
		mat[MM[t]][MM[s]]=1;
	}
	cin>>s>>t;
	C=MM[s];
	D=MM[t];
	
	string res="{";
	int num=1010;
	for(int mask1=0;mask1<1<<N;mask1++) {
		if((mask1&(1<<C))==1) continue;
		if((mask1&(1<<D))==1) continue;
		for(int mask2=0;mask2<1<<N;mask2++) {
			if((mask2&(1<<C))==1) continue;
			if((mask2&(1<<D))==1) continue;
			if(__builtin_popcount(mask1)+__builtin_popcount(mask2)>num) continue;
			
			vector<int> V,V2;
			FOR(i,N) if(mask1&(1<<i)) V.push_back(i);
			FOR(i,N) if(mask2&(1<<i)) V2.push_back(i);
			do {
				do {
					int mat2[10][10];
					memmove(mat2,mat,sizeof(mat));
					int ng=0;
					
					if(V.size()==0) {
						mat2[C][D]--;
						mat2[D][C]--;
					}
					else {
						mat2[C][V[0]]--;
						mat2[V[0]][C]--;
						mat2[D][V.back()]--;
						mat2[V.back()][D]--;
						FOR(i,V.size()-1) mat2[V[i]][V[i+1]]--,mat2[V[i+1]][V[i]]--;
					}
					if(V2.size()==0) {
						mat2[C][D]--;
						mat2[D][C]--;
					}
					else {
						mat2[C][V2[0]]--;
						mat2[V2[0]][C]--;
						mat2[D][V2.back()]--;
						mat2[V2.back()][D]--;
						FOR(i,V2.size()-1) mat2[V2[i]][V2[i+1]]--,mat2[V2[i+1]][V2[i]]--;
					}
					FOR(x,N) FOR(y,N) if(mat2[x][y]<0) ng=1;
					
					if(ng==1) continue;
					
					string t=S[C];
					FOR(i,V.size()) t+=S[V[i]];
					t+=S[D];
					FOR(i,V2.size()) t+=S[V2[V2.size()-1-i]];
					
					if(__builtin_popcount(mask1)+__builtin_popcount(mask2)<num) {
						res=t;
						num=__builtin_popcount(mask1)+__builtin_popcount(mask2);
					}
					else if(res>t) {
						res=t;
					}
					
				} while(next_permutation(ALL(V2)));
			} while(next_permutation(ALL(V)));
		}
	}
	cout<<res<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
