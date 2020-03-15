#define _CRT_SECURE_NO_WARNINGS 1
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		int i, j, sum;
		//判断行和为row
		for (i = 0; i < row; ++i)
		{
			sum = 0;
			for (j = 0; j < row; ++j)
			{
				sum += board[i][j];
			}
			if (row == sum)
				return true;
		}
		//判断列和为row
		for (i = 0; i < row; ++i)
		{
			sum = 0;
			for (j = 0; j < row; ++j)
			{
				sum += board[j][i];
			}
			if (row == sum)
				return true;
		}
		//判断正对角和为row
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (row == sum)
			return true;
		//判断反对角和为row
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (row == sum)
			return true;
		return false;
	}
	
};