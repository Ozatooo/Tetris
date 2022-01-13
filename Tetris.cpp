#include <iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <windows.h>
#include <conio.h>

#define UP 72 
#define DOWN 80
#define LEFT 77
#define RIGHT 75
#define ESC 27

// 		if (map[old_position[0]+1][old_position[1]] == "X" || map[old_position[0]][old_position[1]+1] == "X" || map[old_position[2]+1][old_position[3]] == "X" || map[old_position[2]][old_position[3]+1] == "X" || map[old_position[4]+1][old_position[5]] == "X" || map[old_position[4]][old_position[5]+1] == "X" || map[old_position[6]+1][old_position[7]] == "X" || map[old_position[6]][old_position[7]+1] == "X")

using namespace std;

class tetris {
	public:
		string map[20][10];
		int shape_number;
		int x = 0;
		int y = 1;
		int t = 0;
		int old_position[8];
		int draw = 0;
		int b_draw = 0;
		int lv = 8;
		int speed = 0;
		int points = 0;
		int p_x = 0;
		int e_x = 0;
		bool end = false;
		bool shape_exist = false;
		unsigned char arrow;
		



	void bulid_map()
	{
		for (int i = 0; i < 20; i++)
		{
			cout << "|";
			for (int j = 0; j < 10; j++)
			{
				map[i][j] = " ";
				cout << map[i][j];
			}
			cout <<"|"<< endl;
		}
		cout << "````````````";
	}
	void show_map() 
	{
		system("cls");
		for (int i = 0; i < 20; i++)
		{
			cout << "|";
			for (int j = 0; j < 10; j++)
			{
				cout << map[i][j];
			}
			cout << "|" << endl;
		}
		cout << "````````````" << endl << endl;
		cout << " Points: " << points << endl << endl << p_x << "  " << e_x << endl << endl << endl << endl << endl;
	}
	void arrows() 
	{
		if (arrow == LEFT)
		{
			if (e_x <= 8)
			{
				x++;
				p_x++;
				e_x++;
			}
			
		}
		else if (arrow == RIGHT )
		{
			if (p_x >= 1)
			{
				x--;
				p_x--;
				e_x--;
			}
			
		}
		
	}
	
	void draw_shape() 
	{
		srand(time(0));

		if (draw == 0)
		{
			srand(time(0));
			draw = 4;
			
		}
		else if (draw == 1)
		{
			b_draw = 1;
			shape_1();
		}
		else if (draw == 2)
		{	
			b_draw = 2;
			shape_2();
		}
		else if (draw == 3)
		{
			b_draw = 3;
			shape_3();
		}
		else if (draw == 4)
		{
			b_draw = 4;
			shape_4();
		}
		else if (draw == 5)
		{
			b_draw = 5;
			shape_5();
		}
		
	}
	void check_all() {
		
		bool point = true;
		for (int i = 19; i > 0; i--)
		{
			point = true;
			for (int j = 0; j < 10; j++)
			{
				if(map[i][j] != "X")
				{
					point = false;
				}
			}

			if (point == true)
			{
				
				for (int j = 0; j < 10; j++)
				{
					//end = true;

					map[i][j] = " ";
					points++;
				}
				check_all();
			}
		}
	}

	void x_old_pos() {
		map[old_position[0]][old_position[1]] = " ";
		map[old_position[2]][old_position[3]] = " ";
		map[old_position[4]][old_position[5]] = " ";
		map[old_position[6]][old_position[7]] = " ";

		map[old_position[0]][old_position[1] + x] = "X";
		map[old_position[2]][old_position[3] + x] = "X";
		map[old_position[4]][old_position[5] + x] = "X";
		map[old_position[6]][old_position[7] + x] = "X";

		cout << map[old_position[0]][old_position[1] + x];
		cout << map[old_position[2]][old_position[3] + x];
		cout << map[old_position[4]][old_position[5] + x];
		cout << map[old_position[6]][old_position[7] + x];

		old_position[1] = old_position[1] + x;
		old_position[3] = old_position[3] + x;
		old_position[5] = old_position[5] + x;
		old_position[7] = old_position[7] + x;
	}

	void x_y_old_pos()
	{
		map[old_position[0]][old_position[1]] = " ";
		map[old_position[2]][old_position[3]] = " ";
		map[old_position[4]][old_position[5]] = " ";
		map[old_position[6]][old_position[7]] = " ";

		map[old_position[0] + y][old_position[1] + x] = "X";
		map[old_position[2] + y][old_position[3] + x] = "X";
		map[old_position[4] + y][old_position[5] + x] = "X";
		map[old_position[6] + y][old_position[7] + x] = "X";


		cout << map[old_position[0] + y][old_position[1] + x];
		cout << map[old_position[2] + y][old_position[3] + x];
		cout << map[old_position[4] + y][old_position[5] + x];
		cout << map[old_position[6] + y][old_position[7] + x];


		old_position[0] = old_position[0] + y;
		old_position[1] = old_position[1] + x;
		old_position[2] = old_position[2] + y;
		old_position[3] = old_position[3] + x;
		old_position[4] = old_position[4] + y;
		old_position[5] = old_position[5] + x;
		old_position[6] = old_position[6] + y;
		old_position[7] = old_position[7] + x;
	}

	void check_1() 
	{

		if (map[old_position[2]+1][old_position[3]] == "X" || map[old_position[6]+1][old_position[7]] == "X")
		{
			t = 18;
			draw = 0;
		}
	}
	void check_2()
	{
		if (map[old_position[0] + 1][old_position[1]] == "X" || map[old_position[2] + 1][old_position[3]] == "X" || map[old_position[4] + 1][old_position[5]] == "X" || map[old_position[6] + 1][old_position[7]] == "X")
		{
			t = 18;
			draw = 0;
		}
	}
	void check_3()
	{
		if (map[old_position[6]+1][old_position[7]] == "X" )
		{
			t = 15;
			draw = 0;
		}
	}
	void check_4()
	{
		if (map[old_position[6] + 1][old_position[7]] == "X" || map[old_position[2] + 1][old_position[3]] == "X" || map[old_position[0] + 1][old_position[1]] == "X")
		{
			t = 15;
			draw = 0;
		}
	}

	void check_5()
	{
		if (map[old_position[6] + 1][old_position[7]] == "X" || map[old_position[4] + 1][old_position[5]] == "X" )
		{
			t = 15;
			draw = 0;
		}
	}
	//old_position[0] = 1;
	//old_position[1] = 4;
	//old_position[2] = 2;
	//old_position[3] = 4;
	//old_position[4] = 3;
	//old_position[5] = 4;
	//old_position[6] = 3;
	//old_position[7] = 5;

	void shape_1()
	{


		if (shape_exist == false)
		{
			old_position[0] = 0;
			old_position[1] = 4;
			old_position[2] = 1;
			old_position[3] = 4;
			old_position[4] = 0;
			old_position[5] = 5;
			old_position[6] = 1;
			old_position[7] = 5;

			shape_exist = true;
			p_x = old_position[1];
			e_x = old_position[7];
			
			
		}
		else
		{
			if (lv == speed)
			{

				x_y_old_pos();

				if (x != 0)
				{
					x = 0;
				}
				t++;
				check_1();
				if (t == 18)
				{
					shape_exist = false;
					t = 0;
					check_all();

				}
			
				speed = 0;

			}
			else
			{
				
				x_old_pos();
				if (x != 0)
				{
					x = 0;
				}

				speed++;
			}
		}
	
	}

	void shape_2() 
	{

		if (shape_exist == false)
		{
			old_position[0] = 1;
			old_position[1] = 3;
			old_position[2] = 1;
			old_position[3] = 4;
			old_position[4] = 1;
			old_position[5] = 5;
			old_position[6] = 1;
			old_position[7] = 6;
			p_x = old_position[1];
			e_x = old_position[7];

			shape_exist = true;


		}
		else
		{
			if (lv == speed)
			{

				x_y_old_pos();

				if (x != 0)
				{
					x = 0;
				}
				t++;
				check_2();
				if (t == 18)
				{
					shape_exist = false;
					t = 0;
					check_all();

				}

				speed = 0;

			}
			else
			{

				x_old_pos();
				if (x != 0)
				{
					x = 0;
				}

				speed++;
			}
		}

	}

	void shape_3()
	{

		if (shape_exist == false)
		{
			old_position[0] = 1;
			old_position[1] = 4;
			old_position[2] = 2;
			old_position[3] = 4;
			old_position[4] = 3;
			old_position[5] = 4;
			old_position[6] = 4;
			old_position[7] = 4;

			shape_exist = true;

			p_x = old_position[1];
			e_x = old_position[7];

		}
		else
		{
			if (lv == speed)
			{

				x_y_old_pos();

				if (x != 0)
				{
					x = 0;
				}
				t++;
				check_3();
				if (t == 15)
				{
					shape_exist = false;
					t = 0;
					check_all();

				}

				speed = 0;

			}
			else
			{

				x_old_pos();
				if (x != 0)
				{
					x = 0;
				}

				speed++;
			}
		}

	}

	void shape_4()
	{

		if (shape_exist == false)
		{
			old_position[0] = 1;
			old_position[1] = 3;
			old_position[2] = 1;
			old_position[3] = 4;
			old_position[4] = 1;
			old_position[5] = 5;
			old_position[6] = 2;
			old_position[7] = 5;

			shape_exist = true;

			p_x = old_position[1];
			e_x = old_position[7];
		}
		else
		{
			if (lv == speed)
			{

				x_y_old_pos();

				if (x != 0)
				{
					x = 0;
				}
				t++;
				check_4();
				if (t == 17)
				{
					shape_exist = false;
					t = 0;
					check_all();

				}

				speed = 0;

			}
			else
			{

				x_old_pos();
				if (x != 0)
				{
					x = 0;
				}

				speed++;
			}
		}

	}

	void shape_5()
	{

		if (shape_exist == false)
		{
			old_position[0] = 1;
			old_position[1] = 4;
			old_position[2] = 2;
			old_position[3] = 4;
			old_position[4] = 3;
			old_position[5] = 4;
			old_position[6] = 3;
			old_position[7] = 5;

			shape_exist = true;

			p_x = old_position[1];
			e_x = old_position[7];

		}
		else
		{
			if (lv == speed)
			{

				x_y_old_pos();

				if (x != 0)
				{
					x = 0;
				}
				t++;
				check_5();
				if (t == 16)
				{
					shape_exist = false;
					t = 0;
					check_all();

				}

				speed = 0;

			}
			else
			{

				x_old_pos();
				if (x != 0)
				{
					x = 0;
				}

				speed++;
			}
		}

	}
};
int main()
{
	tetris game;
	game.bulid_map();
	while (game.end == false)
	{
		
		if (_kbhit())
		{
			game.arrow = _getch();
			game.draw_shape();
			game.show_map();
			game.arrows();
			
		}
		else
		{
			game.draw_shape();
			game.show_map();
	
		}
	}

}

