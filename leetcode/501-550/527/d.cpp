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

ll ha[1010101];

std::random_device rnd;
std::mt19937 mt(rnd());

ll H[1010101];
int R[1010101];

using VT = vector<int>;

vector<int> Zalgo(VT s) {
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

class Solution {
public:
    vector<int> countSuffix(vector<int>& nums, vector<int>& target) {
		int N=nums.size(),M=target.size();
		int i;
        if(ha[0]==0) {
			FOR(i,100100) ha[i]=mt();
		}
        FOR(i,target.size()) {
			if(i==0) {
				R[i]=1;
			}
			else {
				R[i]=R[i-1]+1;
				if(target[i]>target[i-1]) R[i]=1;
			}
		}
		vector<int> V=nums;
		V.push_back(100001);
		FORR(a,target) V.push_back(a);
        FOR(i,N+M+1) H[i+1]=H[i]+ha[V[i]];
        
		vector<int> ret;
		auto Z=Zalgo(V);
		for(i=0;i+N<=M;i++) {
			int le=Z[N+i+1];
			int ri=min(N,R[i+N-1]);
			if(le==N) le--;
			if(H[N]==H[N+i+N+1]-H[N+i+1]) {
				ret.push_back(max(0,le+ri+1-N));
			}
			else ret.push_back(0);
		}
		return ret;
		
        
    }
};


