# from gpiozero import LED, Button
# from signal import pause
# led = LED(19)
# button = Button(26)
# button.when_pressed = led.on
# button.when_released = led.off
# pause()
from gpiozero import LED, Button
from signal import pause
led = LED(20)
button = Button(21)
led.source = button #버튼의 상태에 따라 led가 반영됨 #레벨트리거 
pause()
