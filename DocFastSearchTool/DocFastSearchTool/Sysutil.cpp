#define _CRT_SECURE_NO_WARNINGS 1
#include"Sysutil.h"

void DirectoryList(const string &path, vector<string> &subfile, vector<string> &subdir)
{
	//"C:\\Users\\Administrator\\Desktop\\55��\\*.*"
	string _path = path;
	_path += "\\*.*";//ͨ���

	struct _finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);
	if(handle == -1)
	{
		perror("_findfirst");
		return;
	}
	do
	{
		if (file.name[0] == '.')
			continue;
		//_A_SUBDIR
		//��һ���ļ���
		if (file.attrib&_A_SUBDIR)
			subdir.push_back(file.name);
		else
			subfile.push_back(file.name);


	} while (_findnext(handle, &file) == 0);

	////��ʾ�ĵ�
	//for (auto &e : subfile)
	//	cout << e << endl;
	////��ʾĿ¼
	//for(auto &e :subdir)
	//{
	//	cout << e << endl;
	//	//�ݹ���ʾĿ¼������ļ�
	//	vector<string> _subfile, _subdir;
	//	string tmp_path = path;
	//	tmp_path += "\\";
	//	tmp_path += e;
	//	DirectoryList(tmp_path,_subfile, _subdir);
	//}

	_findclose(handle);

}