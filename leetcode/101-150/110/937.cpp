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
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> B,C;
        vector<pair<string,string>> A;
        FORR(c,logs) {
			if(c.back()>='a' && c.back()<='z') A.push_back({c.substr(c.find(' ')),c});
			else B.push_back(c);
		}
		sort(ALL(A));
		FORR(a,A) C.push_back(a.second);
		FORR(a,B) C.push_back(a);
		return C;
    }
};
