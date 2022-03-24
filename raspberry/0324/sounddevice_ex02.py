import sounddevice as sd
import soundfile as sf
from io import BytesIO
fs = 44100 # Sample rate
seconds = 3 # Duration of recording
myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=1)
sd.wait() # Wait until recording is finished
# sf.write('output.wav', myrecording, fs) # Save as WAV file

mem_wav = BytesIO()
sf.write(mem_wav, myrecording, fs, format="wav")
print(mem_wav.tell())
mem_wav.seek(0)

