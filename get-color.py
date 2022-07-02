import os

from PIL import Image

os.system("rm -rf zmxy.png")

os.system("adb shell /system/bin/screencap -p /sdcard/Download/zmxy.png")

os.system("adb pull /sdcard/Download/zmxy.png . >nul")

img_src = Image.open('zmxy.png')

img_src = img_src.convert('RGBA')

src_strlist = img_src.load()

data = src_strlist[2380,100]

print(data)
