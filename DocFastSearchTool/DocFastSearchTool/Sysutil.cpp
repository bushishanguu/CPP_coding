#include"Sysutil.h"

//���ù��λ��
void SetCurPos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {y, x};
	SetConsoleCursorPosition(handle, pos);
}
//���ع��
void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info = {100, 0};
	SetConsoleCursorInfo(handle, &cursor_info);
}
//����  ||
void DrawCol(int x, int y)
{
	for(int i=0; i<HEIGHT; ++i)
	{
		SetCurPos(x+i, y);
		printf("||");
	}
}

//���� =
void DrawRow(int x, int y)
{
	for(int i=0; i<WIDTH-4; ++i)
	{
		SetCurPos(x, y+i);
		printf("=");
	}
}

void SystemEnd()
{
	SetCurPos(HEIGHT-1, (WIDTH-4-strlen("�밴��������� . . ."))/2);
}

//��ϵͳ��ܽ���
void DrawFrame(char *title)
{
	//���ñ���
	char buf[MAX_BUF_SIZE] = {0};
	sprintf(buf, "title %s", title);
	system(buf);

	//���ý���Ŀ�Ⱥ͸߶�
	memset(buf, 0, MAX_BUF_SIZE);
	sprintf(buf, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(buf);

	//������ɫ

	//����ϵͳ����
	DrawCol(0, 0);  //�����
	DrawCol(0, WIDTH-2); //�ұ���
	DrawRow(0, 2);
	DrawRow(2, 2);
	DrawRow(4, 2);

	DrawRow(HEIGHT-6, 2);
	DrawRow(HEIGHT-4, 2);
	DrawRow(HEIGHT-2, 2);
}

extern char *title;
void DrawMenu()
{
	//���ñ���
	SetCurPos(1, (WIDTH-4-strlen(title))/2);
	printf("%s", title);

	//�������� ·��
	SetCurPos(3, 2);
	printf("%-30s%-85s", "����", "·��");

	//���� exit �˳�ϵͳ
	SetCurPos(HEIGHT-3, (WIDTH-4-strlen("exit �˳�ϵͳ ."))/2);
	printf("%s","exit �˳�ϵͳ .");

	//���� ����:>
	SetCurPos(HEIGHT-5, 2);
	printf("%s","������:>");
}

////////////////////////////////////////////////////////////////////////////////////////
void DirectoryList(const string &path, vector<string> &subfile, vector<string> &subdir)
{
	//"G:\\���ݽṹ\\���ݽṹ2018  ppt\\*.*";
	string _path = path;
	_path += "\\*.*";  //ͨ���  * ��%

	struct _finddata_t file;

	long handle = _findfirst(_path.c_str(), &file);
	if(handle == -1)
	{
		perror("_findfirst");
		return;
	}

	do
	{
		if(file.name[0] == '.')
			continue;

		//_A_SUBDIR
		//��һ���ļ���
		if(file.attrib & _A_SUBDIR)     
			subdir.push_back(file.name);
		else
			subfile.push_back(file.name);
	}while(_findnext(handle, &file) == 0);

#if 0
	//��ʾ�ĵ�
	for(auto &e : subfile)
		cout<<e<<endl;

	//��ʾĿ¼
	for(auto &e : subdir)
	{
		cout<<e<<endl;
		//�ݹ���ʾĿ¼������ļ�
		vector<string> _subfile, _subdir;

		//"C:\\Users\\baoso\\Desktop\\55��\\test\\�׶��Կ����Ծ�\\C����";
		string tmp_path = path;
		tmp_path += "\\";
		tmp_path += e;
		DirectoryList(tmp_path, _subfile, _subdir);
	}
#endif
	_findclose(handle);
}