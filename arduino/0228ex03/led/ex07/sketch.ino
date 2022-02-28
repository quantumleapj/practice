#include <Led.h>

Led leds[4]={Led(3), Led(4),Led(5),Led(6)};
int out_no = 0;
void setup()
{

}

void loop()
{
  //ex1
  // int n;
  // for (n=0;n<4;n++){
  //   if(n==out_no){
  //     leds[n].on();
  //   }
  //   else{
  //     leds[n].off();
  //   }
  // }
  // out_no=(++out_no)%4;
  // // if (out_no>3){
  // //   out_no=0;
  // // }//이걸 안해준 이유가 있지 않을까? 맨 끝 비트만 계산하니까 오히려 빠르다든지..

  // delay(1000);


  //ex2
  for (int n=0;n<4;n++){
    leds[n].setValue(n==out_no);
  } 
  out_no = (++out_no)%4;
  delay(1000);
}