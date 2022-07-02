import os

from PIL import Image

import sys,platform

if sys.platform == "linux" :
	os.system("rm -rf zmxy.png")

if sys.platform == "win32" :
	os.system("bin\\Windows\\adb.exe shell /system/bin/screencap -p /sdcard/Download/zmxy.png")
	os.system("bin\\Windows\\adb.exe pull /sdcard/Download/zmxy.png . >nul")
elif sys.platform == "linux" :
	os.system("./bin/Linux/adb shell /system/bin/screencap -p /sdcard/Download/zmxy.png")
	os.system("./bin/Linux/adb pull /sdcard/Download/zmxy.png . >nul")

img_src = Image.open('zmxy.png')

img_src = img_src.convert('RGBA')

src_strlist = img_src.load()

data = src_strlist[2380,100]

print(data)
