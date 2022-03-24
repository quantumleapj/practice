import subprocess
from os import path

def convert_to_mp4(src):
  dst=path.splitext(src)[0]+'.mp4'
  cmd = f"MP4Box -add 'src' 'dst'"
  subprocess.run(cmd, shell=True)
  return dst

# dst = convert_to_mp4('my_video2.h264')
dst = convert_to_mp4('vtest.avi')
print('변환 파일:',dst)
