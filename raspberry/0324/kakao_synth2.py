import requests 
import io
from pydub import AudioSegment
from pydub.playback import play
import sys


URL = "https://kakaoi-newtone-openapi.kakao.com/v1/synthesize" 
HEADERS = {
"Content-Type" : "application/xml",
"Authorization" : "KakaoAK myrestapikey""
}

def make_text(text, name="WOMAN_READ_CALM"):
  return f"""
  <speak>
  <voice name = "{name}">{text}</voice>
  </speak>
  """
# DATA = """
# <speak>
# <voice name="WOMAN_READ_CALM">그는 그렇게 말했습니다.</voice>
# <voice name="MAN_DIALOG_BRIGHT">잘 지냈어? 나도 잘 지냈어.</voice>
# <voice name="WOMAN_DIALOG_BRIGHT" speechStyle="SS_ALT_FAST_1">금요일이 좋아
# 요.</voice>
# </speak>
# """

while True:
  text = input('> ')
  if text =='exit':
    break
  data = make_text(text)
  res = requests.post(URL,headers=HEADERS, data = data.encode('utf-8'))

  if res.status_code !=200:
    print(res)
    print(res.text)
    sys.exit(0)

  sound = io.BytesIO(res.content)
  song = AudioSegment.from_mp3(sound)
  play(song)
