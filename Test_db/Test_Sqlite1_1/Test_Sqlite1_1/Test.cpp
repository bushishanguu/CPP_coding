#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"./sqlite/sqlite3.h"
#pragma comment(lib,"./sqlite/sqlite3.lib")


//���ݿ�sqlite ��װ
class SqliteManager
{
public:
	SqliteManager() :m_db(nullptr)
	{}
	~SqliteManager()
	{}
public:
	//�����ݿ�
	void Open(const std::string& path)
	{
		char *zErrMsg = 0;
		int rc;
		/* Open database */
		rc = sqlite3_open("doc.db", &m_db);
		if (rc)
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
			exit(0);
		}
		else
		{
			fprintf(stderr, "Opened database successfully\n");
		}
	}
	//�ر����ݿ�
	void Close()
	{
		if (m_db)
		{
			int rc = sqlite3_close(m_db);
			if (rc != SQLITE_OK)
			{
				//LOG
			}
			else
			{
			}
		}
	}
	//ִ��sql���
	void ExecuteSql(const std::string& sql);
	//��ȡ����
	void GetTable(const std::string& sql, int& row, int& col, char**&ppRet);
public:
	SqliteManager(const SqliteManager&) = delete;
	SqliteManager& operator=(const SqliteManager&) = delete;
private:
	sqlite3* m_db; // ���ݿ����
};

void main()
{
	SqliteManager sm;
	string path = "";
	sm.Open(path);
	sm.Close();
	system("pause");
}





//
//static int callback_fun(void *data, int argc, char **argv, char **azColName)//���ʱ�ĵڶ�����ʽ
//{
//	int i;
//	fprintf(stderr, "%s: ", (const char*)data);
//	for (i = 0; i<argc; i++)
//	{
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//	printf("\n");
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	char *sql;
//	const char* data = "Callback function called";
//
//	/* Open database */
//	rc = sqlite3_open("doc.db", &db);
//	if (rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//
//	/* Create SQL statement */
//	sql = "SELECT * from my_tb";
//
//	char **ppRet = 0;
//	int row = 0, col = 0;
//	rc = sqlite3_get_table(db, sql, &ppRet, &row, &col, &zErrMsg);
//
//
//
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	else
//	{
//		fprintf(stdout, "Operation done successfully\n");
//	}
//	//���ʽ����
//	for (int i = 0; i <= row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			cout << ppRet[i*col + j] << "      ";
//		}
//		cout << endl;
//	}
//	//�ͷŽ����
//	sqlite3_free_table(ppRet);
//
//	sqlite3_close(db);
//	system("pause");
//	return 0;
//}
//
//





//static int callback_fun(void *data, int argc, char **argv, char **azColName)//��ʾ����ͨ���ص�����
//{
//	int i;
//	fprintf(stderr, "%s: ", (const char*)data);
//	for (i = 0; i<argc; i++)
//	{
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//	printf("\n");
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//	char *sql;
//	const char* data = "Callback function called";
//
//	/* Open database */
//	rc = sqlite3_open("doc.db", &db);
//	if (rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//
//	/* Create SQL statement */
//	sql = "SELECT * from my_tb";
//
//	/* Execute SQL statement */
//	rc = sqlite3_exec(db, sql, callback_fun, (void*)data, &zErrMsg);
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	else
//	{
//		fprintf(stdout, "Operation done successfully\n");
//	}
//	sqlite3_close(db);
//	system("pause");
//	return 0;
//}




//int main(int argc, char* argv[])//��������
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("doc.db", &db);
//
//	if (rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//
//	char *sql = "insert into my_tb values(null,'java.pdf','c:\\')";
//
//
//	rc = sqlite3_exec(db,sql, 0, 0, &zErrMsg);
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	else
//	{
//		fprintf(stdout, "Insert Data successfully\n");
//	}
//
//	sqlite3_close(db);
//	system("pause");
//}
//





//int main(int argc, char* argv[])//�������ݿ�  ���û����ֱ�Ӵ��� ����� ��򿪶�Ӧ�����ݿ�
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("doc.db", &db);
//
//	if (rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//   //���ִ�����ʽ
//	//char *sql = "create table tb_doc(id integer primary key autoincrement,doc_name,doc_path)";
//
//	//char sql[256] = { 0 };
//	//sprintf(sql, "create table %s(id integer primary key autoincrement,doc_name,doc_path)", "my_tb");
//
//	string sql = "create table you_tb(id integer primary key autoincrement,doc_name,doc_path)";
//
//	rc=sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	else
//	{
//		fprintf(stdout, "Table created successfully\n");
//	}
//
//	sqlite3_close(db);
//	system("pause");
//}











//void main()
//{
//	sqlite3 *db;
//	int rc = sqlite3_open("doc.db", &db);
//	if (rc != SQLITE_OK)
//	{
//		printf("open doc.db failed.\n");
//		return;
//	}
//	printf("open doc.db successed.\n");
//	sqlite3_close(db);
//	system("pause");
//}



//int main(int argc, char* argv[])
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("test.db", &db);
//
//	if (rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//	sqlite3_close(db);
//	system("pause");
//}