import RPi.GPIO as GPIO
import time

count = 0

def button_callback(channel):
  global count
  count +=1
  print("button pushed!",count)


#사용할 GPIO핀의 번호 설정
button_pin = 21

#GPIO핀 번호모드설정
GPIO.setmode(GPIO.BCM)
#버튼 GPIO핀 인앤아웃 설정, 풀업 설정 
GPIO.setup(button_pin,GPIO.IN,pull_up_down = GPIO.PUD_UP)
#이벤트 방식으로 라이징 신호 감지 
GPIO.add_event_detect(button_pin,GPIO.FALLING, callback = button_callback,bouncetime=300)

try:
  while 1:
    time.sleep(0.1)
except:
  GPIO.cleanup()