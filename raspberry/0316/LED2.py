
from gpiozero import LED
from signal import pause
red = LED(20)
red.blink() 
# red.blink(background=False)  # 이아래로는 영원히 실행안됨 
# red.blink(on_time=0.3, off_time=0.3) #더 빨라짐 
print('blink') #딱 한번만 출력됨
pause() #이부분을 주석처리하면 딱 한번만 실행된다
# pasue대신 9~10번줄 실행하면 똑같이 나옴 
#즉 red.blink는 스레드로 실행중! 
# while True: #(busy wating)
#   pass
#
