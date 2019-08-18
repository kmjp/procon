
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

    int countCharacters(vector<string>& words, string chars) {
		int ret=0;
		int C[256]={};
		FORR(c,chars) C[c]++;
		FORR(w,words) {
			int D[256]={};
			int ng=0;
			FORR(c,w) {
				D[c]++;
				if(D[c]>C[c]) ng=1;
			}
			if(ng==0) ret+=w.size();
		}
		return ret;
        
    }

};

