#include "CoffeeVendingMachine.h"
#include <iostream>
using namespace std;

#define tong_size 3
#define MAX 10

void CoffeeVendingMachine :: fill(){
  // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통
  for (int i = 0 ; i < tong_size ; i++ ){
    tong[i].fill(MAX);//최대 크기인 10만큼 각 통을 채움
  }
  show();//채운 다음 용량 출력
}
 // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
void CoffeeVendingMachine :: selectEspresso(){
  if(!(tong[0].consume(1) && tong[1].consume(1))) //하나라도 false인 경우 (하나라도 false면 true가 됨)
    cout << "소모할 수 없습니다."<<endl;
  else {
    cout << "에스프레소 드세요."<<endl;
  }
}

 // 아메리카노를 선택한 경우, 커피 1, 물 2 소모
 void CoffeeVendingMachine :: selectAmericano(){
   if(!(tong[0].consume(1) && tong[1].consume(2))) //하나라도 false인 경우 (하나라도 false면 true가 됨)
    cout << "소모할 수 없습니다."<<endl;
  else {
    cout << "아메리카노 드세요."<<endl;
  }
 }

// 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
 void  CoffeeVendingMachine ::selectSugarCoffee(){  
   if(!(tong[0].consume(1) && tong[1].consume(2) && tong[2].consume(1))) //하나라도 false인 경우 (하나라도 false면 true가 됨)
    cout << "소모할 수 없습니다."<<endl;
  else {
    cout << "설탕커피 드세요."<<endl;
  }
} 

// 현재 커피, 물, 설탕의 잔량 출력
void CoffeeVendingMachine :: show(){

  cout << "커피 "<< tong[0].getSize() << " 물 "<< tong[1].getSize() << " 설탕 "<< tong[2].getSize()<< endl;
} 

void CoffeeVendingMachine :: run(){
  int num = 0;
  cout << "** 커피 자판기 작동 시작 **" <<endl;
  while(1){
      cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기 (-1 프로그램 종료))>>" ; 
       cin >> num;
     switch(num){
       case -1 : 
        return;
       
       case 1 : 
         selectEspresso(); //에스프레소 선택
         break;

        case 2 : 
         selectAmericano(); //아메리카노 선택
         break;

        case 3 : 
         selectSugarCoffee(); //설탕커피 선택
         break;

        case 4 : 
         show(); //잔량보기
         break;

        case 5 : 
         fill(); //채우기
         break;

        default :
          cout << "다시 입력하세요!" << endl;      
     }    
  }
}
