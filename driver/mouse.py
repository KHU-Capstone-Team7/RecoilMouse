import serial
import time
from pynput import mouse

# ESP32와의 직렬 통신 설정
ser = serial.Serial('COM6', 9600)

# 마우스 클릭 이벤트 핸들러 정의
def on_click(x, y, button, pressed):
    if pressed:  # 마우스 버튼이 눌렸을 때만 감지
        ser.write(b'click\n')

# 마우스 리스너 설정
with mouse.Listener(on_click=on_click) as listener:
    listener.join()
