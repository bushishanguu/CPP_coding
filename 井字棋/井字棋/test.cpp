#define _CRT_SECURE_NO_WARNINGS 1
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		int i, j, sum;
		//�ж��к�Ϊrow
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
		//�ж��к�Ϊrow
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
		//�ж����ԽǺ�Ϊrow
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (row == sum)
			return true;
		//�жϷ��ԽǺ�Ϊrow
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