#include <iostream>
#include <sys/stat.h>
#include <filesystem>
#include <string>
#include <fstream>
#include <Windows.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>

using namespace std;
namespace fs = std::filesystem;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	std::locale::global(std::locale("Russian"));
	const int COUNT_IMG = 78589;
	string path_photo = "R:\\Photo and Videos\\disc 1000\\JPEG Image (.jpg)";
	string path_photo_tmp = "D:\\New folder";
	string path_file_last = "last.txt";
	ifstream f_l_i(path_file_last);
	int last = 0;
	if (f_l_i.is_open()) {
		f_l_i >> last;
	}
	f_l_i.close();
	
	for (int i = last; i <= COUNT_IMG; ++i) {
		int x = i, n = 1;		
		string tmp;
		while ((x /= 10) > 0) n++;
		for (int j = 0; j < 5 - n; ++j) tmp += '0';
		rename((path_photo + "\\Τΰιλ " + tmp + to_string(i)+".jpg").c_str(), (path_photo + "\\" + to_string(i)+".jpg").c_str());
		tmp = "\\" + to_string(i) + ".jpg";
		error_code ec;
		int size = fs::file_size(path_photo + tmp, ec) / 1024;
		if (size >= 100) {
			fs::create_directories(path_photo + "\\fol");
			rename((path_photo + tmp).c_str(), (path_photo + "\\fol" + tmp).c_str());
		}	
		ofstream f(path_file_last);
		f << i + 1;
		f.close();
	}
	/*string path;
	int num = 2;
	path = to_string(num) + ".jpg";
	cout << fs::file_size(path)/1024;
	string old_p = "S:\\Users\\griki\\Source\\Repos\\sort_img\\2.jpg";
	string new_p = "S:\\Users\\griki\\Source\\Repos\\New folder\\2.jpg";
	rename(old_p.c_str(), new_p.c_str());
	fs::create_directories("D:\\m\\n pnn\\r\\s\\n\\t");*/
}