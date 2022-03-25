
import requests
import json
from gpiozero import MotionSensor, LED
from signal import pause

# pir.when_motion = 
# pir.when_no_motion = 

key_path='/home/pi/workspace/iot_server/access_token.txt'

def send_talk(text, mobile_web_url, web_url = None):
  if not web_url:
    web_url = mobile_web_url

  with open(key_path,"r") as f:
    token=f.read()

  talk_url = "https://kapi.kakao.com/v2/api/talk/memo/default/send"
  header={"Authorization":f"Bearer {token}"}

  text_template={
    'object_type':'text',
    'text':text,
    'link':{
      'web_url':web_url,
      'mobile_web_url':mobile_web_url
    }
  }
  payload= {'template_object':json.dumps(text_template)}
  res=requests.post(talk_url, data=payload,headers=header)
  return res.json()

def motion_detect():
  print('motion_detect')
  led.on()
  res = send_talk('침입 발생','http://아이피:8000/mjpeg?mode=stream')
  if res.get('result_code')!=0:
    print('전송 실패: ',res.msg, res.code)

pir = MotionSensor(16)
led=LED(20)

pir.when_motion = motion_detect
pir.when_no_motion = led.off

pause()
