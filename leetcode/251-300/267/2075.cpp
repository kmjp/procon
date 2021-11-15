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
    string decodeCiphertext(string encodedText, int H) {
        int W=encodedText.size()/H;
        string S;
        int x,y;
        cout<<H<<" "<<W<<" "<<encodedText.size()<<endl;
        FOR(x,W) {
			FOR(y,H) if(x+y<W) S+=encodedText[y*W+x+y];
		}
		while(S.size()&&S.back()==' ') S.pop_back();
		return S;
    }
};
