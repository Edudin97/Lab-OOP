#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int OPEN_VAL = 0;
const int CLOSE_VAL = 1;
const int START_VAL = -1;

class T_cell
{
public:
	int a;
	int b;
	T_cell(int i, int j) : a(i), b(j) {}
	bool operator==(const T_cell& c) { return a == c.a && b == c.b; }
	bool operator!=(T_cell c) { return !(*this == c); }
};

class T_path_node
{
public:
	T_cell  prev_cell;
	T_cell  cur_cell;
	T_path_node (T_cell  prev_cell, T_cell  cur_cell) : prev_cell(prev_cell), cur_cell(cur_cell) {}
};

ostream& operator<<(ostream& os, const T_cell& cell)
{
	os << "(" << cell.a << ", " << cell.b << ")";
	return os;
}


typedef stack<T_path_node>  T_path_stack;

bool fill_stack(T_path_stack& path_stack)
{
	const int m = 9;
	const int n = 9;
	int labirint[m][n] = { {1, 1,  1, 1,  1, 0, 1, 1, 1},
						  {1, 1,  0, 0,  1, 0, 1, 0, 1},
						  {1, 0,  1, 0,  0, 0, 1, 0, 1},
						  {1, 0,  1, 0,  1, 0, 1, 0, 1},
						  {1, 0,  0, 0,  0, 0, 1, 0, 1},
						  {1, 0,  1, 1,  1, 1, 1, 0, 1},
						  {1, 0,  0, 1,  0, 0, 0, 0, 1},
						  {1, 1,  0, 0,  0, 1, 1, 1, 1},
						  {1, 1,  1, 1, -1, 1, 1, 1, 1} };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << " " << labirint[i][j];
		cout << endl;
	}

	//Äëÿ êàæäîãî çíà÷åíèÿ â êëåòêå îò START_VAL è ìåíüøå çàïîëíÿåì ñîñåäíèå êëåòêè
	//ñî çíà÷åíèåì OPEN_VAL çíà÷åíèåì íà åäèíèöó ìåíüøå, ÷åì â òåêóùåé êëåòêå.
	//Ïðîöåññ çàêàí÷èâàåòñÿ, êîãäà ìû çàïîëíÿåì êëåòêó, ñòîÿùóþ ñ êðàþ, ëèáî, åñëè 
	//ïðè î÷åðåäíîì ïðîõîäå ìû íå çàïîëíèëè íè îäíîé êëåòêè.    
	for (int cur_cell_val = START_VAL; ; --cur_cell_val)
	{   
		int  start_stack_size = path_stack.size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (labirint[i][j] == cur_cell_val)
				{
					// Îáõîäèì ñîñåäíèå êëåòêè.
					for (int  i_sosed = std::max(i - 1, 0);
						i_sosed <= std::min(i + 1, m - 1); ++i_sosed)
					{
						for (int  j_sosed = std::max(j - 1, 0);
							j_sosed <= std::min(j + 1, n - 1); ++j_sosed)
						{
							// Åñëè ñòîëáöû èëè ñòðîêè ñîâïàäàþò è êëåòêà ñâîáîäíà, òî:
							if ((i_sosed == i || j_sosed == j)
								&& labirint[i_sosed][j_sosed] == OPEN_VAL)
							{
								labirint[i_sosed][j_sosed] = cur_cell_val - 1;
								path_stack
									.push(
										T_path_node(
											T_cell(i, j),
											T_cell(i_sosed, j_sosed)
										)
									);

								//Åñëè êëåòêà êðàéíÿÿ, òî:
								if (i_sosed == 0 || i_sosed == m - 1
									|| j_sosed == 0 || j_sosed == n - 1)
								{
									return true;
								}
							}
						}                
					}
				}
			}       
		}     
		if (path_stack.size() == start_stack_size) return false;
	}
}

void print_path(T_path_stack  path_stack)
{
	cout << "Ìàðøðóò â ëàáèðèíòå îò âûõîäà äî ñòàðòîâîé êëåòêè:" << endl;
	for (;;)
	{
		T_cell  prev_cell = path_stack.top().prev_cell;
		std::cout << path_stack.top().cur_cell << std::endl;
		if (path_stack.size() == 1)
		{
			std::cout << path_stack.top().prev_cell << std::endl;
			return;
		}
		while (path_stack.top().cur_cell != prev_cell)
		{
			path_stack.pop();
		}
	}
}

int main()
{
	setlocale(0, "");
	T_path_stack  path_stack;

	if (!fill_stack(path_stack))
	{
		std::cout << "Íåò âûõîäà!" << std::endl;
	}
	else
	{
		print_path(path_stack);
	}
	return 0;
}
