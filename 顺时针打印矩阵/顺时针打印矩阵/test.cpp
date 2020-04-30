#define _CRT_SECURE_NO_WARNINGS 1
// 问题本身不复杂, 将思路考虑周全即可. 
class Printer 
{ 
public: vector<int> 
		clockwisePrint(vector<vector<int> > mat, int n, int m) 
{    
			vector<int> ret;    
			int x1 = 0, y1 = 0;      //左上角坐标    
			int x2 = n-1, y2 = m-1;  //右下角坐标    
			// 这两个坐标表示了一个矩形(最开始的矩阵)   
			// 然后按照要求打印最外圈的数据.    
			// 打印完毕之后, 缩小矩形的大小.     
			while(x1 <= x2 && y1 <= y2){        
				for(int j = y1; j <= y2; ++j)            
					ret.push_back(mat[x1][j]);        
				for(int i = x1+1; i < x2; ++i)           
					ret.push_back(mat[i][y2]);        
				for(int j = y2; x1 < x2 && j >= y1; --j) 
					//x1 < x2：只有在不是单一的横行时才执行这个循 环            
					ret.push_back(mat[x2][j]);        
				for(int i = x2-1; y1 < y2 && i > x1; --i)
					//y1 < y2：只有在不是单一的竖列时才执行这个循 环            
					ret.push_back(mat[i][y1]);        
				x1++; y1++;        
				x2--; y2--;    
			}    
			return ret; 
		} 
};