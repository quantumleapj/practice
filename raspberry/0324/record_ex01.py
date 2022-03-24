from os import path 

# file_path = 'home/workspace/picame/my_video.h264'
file_path='/home/pi/workspace/opencv/data/20220314_171400.mp4'

#디렉토리 경로 얻기
dir_path=path.dirname(file_path)
print('디렉토리 경로',dir_path)

#파일명 얻기
file_name = path.basename(file_path)
print('파일명',file_name)

#경로와 파일명 분리
result=path.split(file_path)
print('경로와 파일명 : ',result)

#확장자와 나머지 분리 
result=path.splitext(file_path)
print('확장자 분리',result)

# 확장명 변경
# dest_path = result[0]+'.mp4'
dest_path = result[0]+'.h264'
print('변환된 파일명: ',dest_path)

#MP4Box -add <src> <dst>
cmd = f"MP4Box -add '{file_path}' '{dest_path}'"
print(cmd)

