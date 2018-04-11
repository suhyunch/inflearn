#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main(){
     //랜덤 테이블
     srand((unsigned int )time(0));
     int iLotto[45]={};
/*내 알고리즘
     for(int i=0; i<6; i++){
          while(1){
               int tmp=rand()%45+1;
               if(!iLotto[tmp]) {
                    cout << tmp <<endl;
                    iLotto[tmp]=1;
                    break;
               }
          }

     }
     */
     for(int i=0; i<45; i++){
          iLotto[i]=i+1;
     }

/*     //Swap알고리즘 1 2의 값을 서로 바꾼 것.
     int iNum1=1, iNum2=2, iNum3;
     iNum3=iNum1;
     iNum1=iNum2;
     iNum2=iNum3;
*/
     //Shuffle
     int iTemp, idx1, idx2;

     for(int i=0; i<100; i++){
          idx1=rand()%45;
          idx2=rand()%45;
          iTemp=iLotto[idx1];
          iLotto[idx1]=iLotto[idx2];
          iLotto[idx2]=iTemp;
     }

     for(int i=0; i<6;i++){
          cout << iLotto[i]<<endl;
     }
     cout << "Bonus Number : " << iLotto[6] <<endl;
     return 0;
}
