#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
		string S;
		FORR(a,chunks) S+=a;
		S+=" ";
		map<string,int> M;
		int i,N=S.size();
		string X;
		FOR(i,N) {
			if(S[i]=='-') {
				if(X.size()&&i+1<N&&(S[i+1]>='a'&&S[i+1]<='z')) {
					X+="-";
				}
				else {
					if(X.size()) {
						M[X]++;
						X="";
					}
				}
				
			}
			else if(S[i]==' ') {
				if(X.size()) {
					M[X]++;
					X="";
				}
			}
			else {
				X+=S[i];
			}
		}
		
		vector<int> ret;
		FORR(q,queries) ret.push_back(M[q]);
		return ret;
        
    }
};
