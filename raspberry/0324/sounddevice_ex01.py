import sounddevice as sd
duration = 5.5 # seconds
def callback(indata, outdata, frames, time, status):
  if status:
    print(status)
  outdata[:] = indata
with sd.Stream(channels=1, callback=callback):
  sd.sleep(int(duration * 1000))
