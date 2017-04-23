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

int Q;
string A,B;
int LA,LB;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B;
		
		if(A.size()<B.size()) {
			cout<<"Steven"<<endl;
		}
		else {
			LA=A.size();
			LB=B.size();
			string C=B+"$"+A;
			vector<int> Z=Zalgo(C);
			
			int len=LA-LB+1;
			vector<int> V;
			FOR(i,len) V.push_back(Z[i+LB+1]>=B.size());
			
			FOR(x,2) if(len>1) {
				vector<int> V2;
				if(len%2==1) {
					FOR(i,len-1) V2.push_back(V[i]|V[i+1]);
				}
				else {
					FOR(i,len-1) V2.push_back(V[i]&V[i+1]);
				}
				swap(V,V2);
				len--;
			}

			if(len%2==1) {
				if(V[len/2]) cout<<"Amanda"<<endl;
				else if(len>=3 && V[len/2-1] && V[len/2+1]) cout<<"Amanda"<<endl;
				else cout<<"Steven"<<endl;
			}
			else {
				if(V[len/2]&&V[len/2-1]) cout<<"Amanda"<<endl;
				else cout<<"Steven"<<endl;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
