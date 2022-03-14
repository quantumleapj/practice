from asyncio.windows_events import NULL
import cv2
from datetime import datetime

# cap = cv2.VideoCapture(0) # 0번 카메라
cap = cv2.VideoCapture(1) # 1번 카메라
frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)),
int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
print('frame_size = ', frame_size)
# fourcc = cv2.VideoWriter_fourcc(*'DIVX')
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out=None

def start_rec():
  global out

  if out:return # r두번누른경우

  start = datetime.now()
  fname = start.strftime('./data/%Y%m%d_%H%M%S.mp4')
  out = cv2.VideoWriter(fname, fourcc, 20.0, frame_size)
  print('started recoding')

def stop_rec():
  global out

  if not out:return

  out.release()
  out=None
  print('stopped recoding')

while True:
  retval, frame = cap.read() # 프레임 캡처
  if not retval: break
  if out :
    out.write(frame)
  cv2.imshow('frame', frame)
  key = cv2.waitKey(50) # 1/20 = 0.05초 = 50MS 

  if key == 27 : break # ESC

  if key == 82 or key==114: # r
    print('r pressed')
    start_rec()

  if key == 83 or key==115: # s
    print('s pressed')
    stop_rec()

if cap.isOpened():
  cap.release()    
cv2.destroyAllWindows()
