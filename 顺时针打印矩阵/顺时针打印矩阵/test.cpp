#define _CRT_SECURE_NO_WARNINGS 1
// ���Ȿ������, ��˼·������ȫ����. 
class Printer 
{ 
public: vector<int> 
		clockwisePrint(vector<vector<int> > mat, int n, int m) 
{    
			vector<int> ret;    
			int x1 = 0, y1 = 0;      //���Ͻ�����    
			int x2 = n-1, y2 = m-1;  //���½�����    
			// �����������ʾ��һ������(�ʼ�ľ���)   
			// Ȼ����Ҫ���ӡ����Ȧ������.    
			// ��ӡ���֮��, ��С���εĴ�С.     
			while(x1 <= x2 && y1 <= y2){        
				for(int j = y1; j <= y2; ++j)            
					ret.push_back(mat[x1][j]);        
				for(int i = x1+1; i < x2; ++i)           
					ret.push_back(mat[i][y2]);        
				for(int j = y2; x1 < x2 && j >= y1; --j) 
					//x1 < x2��ֻ���ڲ��ǵ�һ�ĺ���ʱ��ִ�����ѭ ��            
					ret.push_back(mat[x2][j]);        
				for(int i = x2-1; y1 < y2 && i > x1; --i)
					//y1 < y2��ֻ���ڲ��ǵ�һ������ʱ��ִ�����ѭ ��            
					ret.push_back(mat[i][y1]);        
				x1++; y1++;        
				x2--; y2--;    
			}    
			return ret; 
		} 
};