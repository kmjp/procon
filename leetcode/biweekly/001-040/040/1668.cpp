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
    int maxRepeating(string sequence, string word) {
		int ma=0;
		int N=sequence.size();
		int M=word.size();
		int i,j;
		FOR(i,N) {
			for(j=0;j+i<N;j++) {
				if(sequence[j+i]!=word[j%M]) break;
			}
			ma=max(ma,j);
		}
		cout<<"!"<<endl;
        return ma/M;
    }
};

