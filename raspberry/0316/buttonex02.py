from gpiozero import Button
from signal import pause
count =0
def say_hello():
  global count
  count +=1
  print("Hello!",count)
button = Button(21, bounce_time=0.06)
button.when_pressed = say_hello #참조값을 줌 #콜백함수 
#이건 프로퍼티 아니고 변수임. 스레드는 이미 윗줄에서 발생함. 눌러지는 사건이발생하면 호출해주는거 
# =say_hello()는 리턴값이없으니 None
pause() #버튼이 스레드 형식으로 동작하고있다 