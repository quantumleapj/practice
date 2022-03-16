from gpiozero import Button
from signal import pause
from datetime import datetime
def say_hello():
  print("Hello!",datetime.now())
def say_goodbye():
  print("Goodbye!",datetime.now())
button = Button(21,bounce_time=0.03)
button.when_pressed = say_hello
button.when_released = say_goodbye
pause()
