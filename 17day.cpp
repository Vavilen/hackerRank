#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Calculator {
public:
    int power(int, int) throw (exception);
};

int Calculator::power(int n, int p) throw (exception) {
    if (n >= 0 && p >= 0) {
        return pow(n, p);
    } else {
        throw invalid_argument("n and p should be non-negative");
    }
}


int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl;
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

}
