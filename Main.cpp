#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#elif __linux__
#include <unistd.h>
#endif
using namespace std;

#ifdef __linux__
void Sleep(int sleep_time) {
	usleep(sleep_time * 1000);
}
#endif

#ifdef _WIN32
string bin = "bin\\Windows\\adb.exe";
#elif __linux__
string bin = "./bin/Linux/adb";
#endif

void run(string button, string time) {
	string adb = bin + " shell input swipe " + button + " " + button + " " + time;
	char* command = (char*)adb.c_str();
	system(command);
	return;
}


string get_color(string file_name, string game_color) {
#ifdef _WIN32
	system("python get-color.py >game_color.data");
#elif __linux__
	system("python3 get-color.py >game_color.data");
#endif
	string color;
	ifstream colorin(file_name, ios::in);
	if (!colorin.is_open()) {
		cout << "读取文件失败" << endl;
		return "no";
	}
	getline(colorin, color);
	color.erase(remove(color.begin(), color.end(), ','), color.end());
	color.erase(remove(color.begin(), color.end(), '('), color.end());
	color.erase(remove(color.begin(), color.end(), ')'), color.end());
	if (color == game_color) {
		cout << "颜色正确\n";
		return "yes";
	}
	else {
		cout << "颜色不正确\n";
		return "no";
	}
}

int main() {
#ifdef __linux__
	ifstream testin("Linux.data");
	if (!testin.is_open()) {
		system("mv config-data.ini config-data.ini.bak");
		system("iconv -c -f GB2312 -t UTF-8 config-data.ini.bak  > config-data.ini");
		system("mv config.ini config.ini.bak");
		system("iconv -c -f GB2312 -t UTF-8 config.ini.bak  > config.ini");
		testin.close();
		ofstream testout("Linux.data");
		testout << "Yes";
		testout.close();
		system("rm -rf config-data.ini.bak");
		system("rm -rf config.ini.bak");
	}
	else testin.close();
#endif
	ifstream cfgin("config.ini");
	string jn1, jn2, jn3, jn4, jn5, wushuang, fabao, menu, setting, restart, restart_sure, go_left, go_right, tiaoyue, data_color;
	string config_in;
	while (true) {
		getline(cfgin, config_in);
		if (config_in == "结束读取") {
			cfgin.close();
			break;
		}

		if (config_in == "技能1") {
			getline(cfgin, jn1);
			continue;
		}

		if (config_in == "技能2") {
			getline(cfgin, jn2);
			continue;
		}

		if (config_in == "技能3") {
			getline(cfgin, jn3);
			continue;
		}

		if (config_in == "技能4") {
			getline(cfgin, jn4);
			continue;
		}

		if (config_in == "技能5") {
			getline(cfgin, jn5);
			continue;
		}

		if (config_in == "菜单") {
			getline(cfgin, menu);
			continue;
		}

		if (config_in == "设置") {
			getline(cfgin, setting);
			continue;
		}

		if (config_in == "重新开始") {
			getline(cfgin, restart);
			continue;
		}

		if (config_in == "确认重新开始") {
			getline(cfgin, restart_sure);
			continue;
		}

		if (config_in == "左走键") {
			getline(cfgin, go_left);
			continue;
		}

		if (config_in == "右走键") {
			getline(cfgin, go_right);
			continue;
		}

		if (config_in == "无双") {
			getline(cfgin, wushuang);
			continue;
		}

		if (config_in == "法宝") {
			getline(cfgin, fabao);
			continue;
		}

		if (config_in == "跳跃") {
			getline(cfgin, tiaoyue);
			continue;
		}

		if (config_in == "地图颜色") {
			cout << "读取到地图颜色" << endl;
			getline(cfgin, data_color);
			cout << "颜色为:" << data_color << endl;
			continue;
		}
	}
	while (true) {
		int wait_times = 0;
		while (true) {
			Sleep(2000);
			//	罗刹宫殿2
			//	string back_color = get_color("game_color.data","85 102 255 255");
			string back_color = get_color("game_color.data", data_color);
			wait_times += 1;
			if (wait_times > 4) {
#ifdef __linux__
				system("play error.wav");
				system("clear");
				cout << "游戏出现异常!\n";
				cout << "解决异常后重新开始游戏，即可继续脚本\n";
				while(true){
					if(get_color("game_color.data", data_color) == "yes") break;
				}
#elif _WIN32
				PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				cout << "游戏出现异常!\n";
				cout << "解决异常后重新开始游戏，即可继续脚本\n";
				while(true){
					if(get_color("game_color.data", data_color) == "yes") break;
				}

#endif
				wait_times = 0;
				continue;
			}
			if (back_color == "yes") break;
			if (back_color == "no") continue;
		}
		string diy, diy_x, diy_y;
		string data_in;
		string time;
		int for_time;
		int wait_time;
		ifstream fin("config-data.ini");
		while (true) {
			fin >> data_in;
			if (data_in == "技能1") {
				fin >> time;
				run(jn1, time);
				continue;
			}
			if (data_in == "技能2") {
				fin >> time;
				run(jn2, time);
				continue;
			}
			if (data_in == "技能3") {
				fin >> time;
				run(jn3, time);
				continue;
			}
			if (data_in == "技能4") {
				fin >> time;
				run(jn4, time);
				continue;
			}
			if (data_in == "技能5") {
				fin >> time;
				run(jn5, time);
				continue;
			}
			if (data_in == "无双") {
				run(wushuang, "50");
				continue;
			}
			if (data_in == "法宝") {
				run(fabao, "50");
				continue;
			}
			if (data_in == "跳跃") {
				run(tiaoyue, "50");
				continue;
			}
			if (data_in == "菜单") {
				run(menu, "50");
				Sleep(500);
				continue;
			}
			if (data_in == "设置") {
				run(setting, "50");
				Sleep(300);
				continue;
			}
			if (data_in == "重新开始") {
				run(restart, "50");
				Sleep(300);
				continue;
			}
			if (data_in == "确认重新开始") {
				run(restart_sure, "50");
				continue;
			}
			if (data_in == "往左走") {
				fin >> time;
				run(go_left, time);
				continue;
			}
			if (data_in == "往右走") {
				fin >> time;
				run(go_right, time);
				continue;
			}
			if (data_in == "等待") {
				fin >> wait_time;
				Sleep(wait_time);
				continue;
			}
			if (data_in == "自定义") {
				fin >> diy_x >> diy_y;
				fin >> time;
				diy = diy_x + " " + diy_y;
				run(diy, time);
			}
			if (data_in == "循环") {
				cout << "检测到循环\n";
				fin >> for_time;
				ofstream linshi_out("for.data");
				while (true) {
					getline(fin, data_in);
					if (data_in != "结束循环") {
						cout << data_in << endl;
						linshi_out << data_in << endl;
					}
					else {
						linshi_out << "结束循环" << endl;
						linshi_out.close();
						//system("read -n 1 echo");
						break;
					}
				}
				for (int i = 1; i <= for_time; i++) {
					cout << endl;
					cout << "正在进行第 " << i << " 次循环\n";
					ifstream linshi_in("for.data");
					while (true) {
						linshi_in >> data_in;
						if (data_in == "技能1") {
							linshi_in >> time;
							run(jn1, time);
							continue;

						}
						if (data_in == "技能2") {
							linshi_in >> time;
							run(jn2, time);
							continue;

						}
						if (data_in == "技能3") {
							linshi_in >> time;
							run(jn3, time);
							continue;

						}
						if (data_in == "技能4") {
							linshi_in >> time;
							run(jn4, time);
							continue;
						}
						if (data_in == "技能5") {
							linshi_in >> time;
							run(jn5, time);
							continue;
						}
						if (data_in == "无双") {
							run(wushuang, "50");
							continue;
						}
						if (data_in == "法宝") {
							run(fabao, "50");

						}
						if (data_in == "跳跃") {
							run(tiaoyue, "50");
							continue;
						}
						if (data_in == "菜单") {
							run(menu, "50");
							Sleep(500);
							continue;
						}
						if (data_in == "设置") {
							run(setting, "50");
							Sleep(300);
							continue;
						}
						if (data_in == "重新开始") {
							run(restart, "50");
							Sleep(300);
							continue;
						}
						if (data_in == "确认重新开始") {
							run(restart_sure, "50");
							continue;
						}
						if (data_in == "往左走") {
							linshi_in >> time;
							run(go_left, time);
							continue;
						}
						if (data_in == "往右走") {
							linshi_in >> time;
							run(go_right, time);
							continue;
						}
						if (data_in == "等待") {
							linshi_in >> wait_time;
							Sleep(wait_time);
							continue;
						}
						if (data_in == "结束循环") {
							linshi_in.close();
							break;
						}
					}
				}
#ifdef _WIN32
				system("del for.data");
#elif __linux__
				system("rm -rf for.data");
#endif
				cout << "\n循环结束\n";
			}
			else if (data_in == "结束") {
				fin.close();
				break;
			}
		}
	}
	return 0;
}
