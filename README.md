## Windows运行方法:
````bash
配置完成后，直接打开Main.exe
````
## Linux运行方法:

配置完环境后
````bash
cd '路径\DIY_zmxy'
````
````bash
g++ 造梦西游ol脚本_win_orlinux.cpp
````
````bash
./a.out
````


# Windows环境要求: python3
# Linux环境要求: sox python3 g++

### sox安装方法:
Debain系:
````bash
sudo apt install sox
````
Arch系:
````bash
sudo pacman -S sox
````


# python库需求: Pillow

### 安装方法:
````bash
pip3 install Pillow
````

# 手机需求:打开 USB调试 和 USB调试(安全设置)

## 打开方法

[华为手机](https://help.airdroid.com/hc/zh-cn/articles/360044847394-%E5%8D%8E%E4%B8%BA%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[小米手机](https://help.airdroid.com/hc/zh-cn/articles/360045329413-%E5%B0%8F%E7%B1%B3%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[OPPO手机](https://help.airdroid.com/hc/zh-cn/articles/360045675654-Oppo%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[VIVO手机](https://help.airdroid.com/hc/zh-cn/articles/360045661674-vivo%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[Realme手机](https://help.airdroid.com/hc/zh-cn/articles/4412937828251-Realme%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[三星手机](https://help.airdroid.com/hc/zh-cn/articles/360045374013-%E4%B8%89%E6%98%9F%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)

[锤子手机](https://help.airdroid.com/hc/zh-cn/articles/360045202593-%E9%94%A4%E5%AD%90%E6%89%8B%E6%9C%BA%E5%A6%82%E4%BD%95%E5%BC%80%E5%90%AFUSB%E8%B0%83%E8%AF%95-)
# config.ini文件说明

## 用途:读取按键位置(原config.ini为文件模板)

### 格式: 按键名 参数
|按键名|参数|
| --- | --- |
|技能1| 按键坐标(x y) |
|技能2| 按键坐标(x y) |
|技能3| 按键坐标(x y) |
|技能4| 按键坐标(x y) |
|技能5| 按键坐标(x y) |
|左走键| 按键坐标(x y) |
|右走键| 按键坐标(x y) |
|跳跃| 按键坐标(x y) |
|菜单| 按键坐标(x y) |
|设置| 按键坐标(x y) |
|重新开始| 按键坐标(x y) |
|确认重新开始| 按键坐标(x y) |
|法宝| 按键坐标(x y) |
|无双| 按键坐标(x y) |
#### 特殊指令
|指令名|参数|
| --- | --- |
|地图颜色| 进地图后用 get-color.py 获取(用于确认关卡进入是否成功) |
|结束读取| 无参数(不加无法运行) |

# config_data.ini文件说明(原config-data.ini为哪吒刷暴章模板模板)

## 用途:设置地图内打怪脚本

### 格式: 操作 参数
|操作|参数|
| --- | --- |
|技能1| 按下时间 |
|技能2| 按下时间 |
|技能3| 按下时间 |
|技能4| 按下时间 |
|技能5| 按下时间 |
|往左走| 按下时间 |
|往右走| 按下时间 |
|跳跃| 按下时间 |
|自定义| X坐标 Y坐标 按下时间 |
|菜单| 无参数(默认50毫秒) |
|设置| 无参数(默认50毫秒) |
|重新开始| 无参数(默认50毫秒) |
|确认重新开始| 无参数(默认50毫秒) |
|法宝| 无参数(默认50毫秒) |
|无双| 无参数(默认50毫秒) |
|等待| 时间(单位:毫秒) |
|循环| 循环次数 |
|结束循环| 无参数(用来结束读取循环的内容) |
|结束读取| 无参数(不加无法运行) |
