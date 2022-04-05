#include "Container.h"
#include <iostream>
using namespace std;
#define MAX 10

Container:: Container() {
   size = MAX; 
}
void Container:: fill(int n){
 if(size+n > MAX) size = MAX; //용량 초과하는 경우는 10으로 지정
 else size += n;
  
} // n 만큼 채우기

bool Container:: consume(int n){
 if(size < n) return false;  //현 용량보다 많은 양을 소모할려고 하는 경우 false 리턴
 else {
   size -= n; //size를 n만큼 감소시키고  
   return true;//true 리턴해주기 
 } 
} // n 만큼 소모하기

int Container::  getSize(){
  return size;
} // 현재 크기 리턴

