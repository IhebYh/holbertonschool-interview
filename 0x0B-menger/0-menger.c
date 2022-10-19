#include "menger.h"

/**
 * menger - draws 2-D menger square
 * @level: menger square has side legnth 3^level
 */
void menger(int level)
{
	int n, row, col, _row, _col, ch;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			_row = row;
			_col = col;
			ch = '#';
			while (_row || _col)
			{
				if (_row % 3 == 1 && _col % 3 == 1)
					ch = ' ';
				_row /= 3;
				_col /= 3;
			}
			putchar(ch);
		}
		putchar('\n');
	}
}
