#동영상 파일 연결 

import cv2
cap = cv2.VideoCapture('./data/vtest.avi') # 1번 카메라
frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
print('frame_size = ', frame_size)
fps = int(cap.get(cv2.CAP_PROP_FPS)) #동영상이 초당 몇 프레임 재생해야 하는지 확인
print('fps=',fps) # 10이다. 1000중 100씩 기다려야 10됨
while True:
  retval, frame = cap.read() # 프레임 캡처
  if not retval: break
  cv2.imshow('frame', frame)
  key = cv2.waitKey(100) #100으로 교체
  if key == 27: break # ESC키를 누른 경우 루프 탈출
if cap.isOpened():
  cap.release()
cv2.destroyAllWindows()
