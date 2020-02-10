#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"Sysutil.h"
void Test_DirectoryList()
{
	string path = "C:\\Users\\Administrator\\Desktop\\55°à";
	vector<string> subfile, subdir;
	DirectoryList(path, subfile, subdir);

	for (auto &e : subfile)
		cout << e << endl;
	for (auto &e : subdir)
		cout << e << endl;
}

int main(int argc, char *argv[])
{
	Test_DirectoryList();
	system("pause");
	return 0;
}