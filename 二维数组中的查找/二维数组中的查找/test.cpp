#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;
		int rows = array.size();
		int cols = array[0].size();

		int x = 0;
		int y = cols - 1;
		bool found = false;
		while (x >= 0 && y >= 0 && x<rows&&y<cols)
		{
			if (array[x][y] == target)
			{
				return true;
			}
			else if (array[x][y]<target)
			{
				x++;
			}
			else
			{
				y--;
			}
		}
		return found;

	}
};