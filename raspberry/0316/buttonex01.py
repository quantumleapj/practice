from gpiozero import Button
button = Button(21)
while True:
  if button.is_pressed:
    print("Button is pressed")
  else:
    print("Button is not pressed")
#레벨트리거라서 출력이 계속나옴