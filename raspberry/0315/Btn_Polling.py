import RPi.GPIO as GPIO
import time
button_pin = 21

GPIO.setmode(GPIO.BCM)

GPIO.setup(button_pin,GPIO.IN,pull_up_down=GPIO.PUD_UP)


try:
  while 1:
    if GPIO.input(button_pin) ==GPIO.LOW: #풀업이라 버튼눌렀을때가 
      print("button pushed!")

    time.sleep(0.1)
except:
  GPIO.cleanup()