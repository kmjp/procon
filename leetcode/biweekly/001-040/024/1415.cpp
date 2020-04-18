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


class Solution {
public:
    string getHappyString(int n, int k) {
		vector<string> C;
		C.push_back("a");
		C.push_back("b");
		C.push_back("c");
		for(int i=2;i<=n;i++) {
			vector<string> D;
			FORR(c,C) {
				if(c.back()!='a') D.push_back(c+"a");
				if(c.back()!='b') D.push_back(c+"b");
				if(c.back()!='c') D.push_back(c+"c");
			}
			swap(C,D);
		}
		
		if(k<=C.size()) return C[k-1];
		else return "";
    }
};

