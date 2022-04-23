#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <sstream>
#include <chrono>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

struct user{
	char name[13];
	char username[13];
	char password[13];
	int login_times;
	int card_value;
	int win_times, lose_times;
};
struct userlist{
	int total_user_num;
	user member[100];
};
struct stocklist{
	int drink[19], bubble, ice, Mcup, Lcup, sugar;
	};

int Calorie[][7]{
	{180, 126, 90, 54, 36, 18, 0}, {200, 140, 100, 60, 40, 20, 0}, {180, 126, 90, 54, 36, 18, 0}, {200, 140, 100, 60, 40, 20, 0}
	, {160, 112, 80, 48, 32, 16, 0}, {180, 126, 90, 54, 36, 18, 0}, {180, 126, 90, 54, 36, 18, 0}, {200, 140, 100, 60, 40, 20, 0}
	, {160, 112, 80, 48, 32, 16, 0}, {180, 126, 90, 54, 36, 18, 0}, {120, 84, 60, 36, 24, 12, 0}, {140, 98, 70, 42, 28, 14, 0}
	, {225}, {315}, {100, 70, 50, 30, 20, 10, 0}, {140, 98, 70, 42, 28, 14, 0}
	, {160, 112, 80, 48, 32, 16, 0}, {180, 126, 90, 54, 36, 18, 0}, {324}, {454}
	, {250}, {351},  {160, 112, 80, 48, 32, 16, 0}, {180, 126, 90, 54, 36, 18, 0}
	, {140, 98, 70, 42, 28, 14, 0}, {160, 112, 80, 48, 32, 16, 0}, {140, 98, 70, 42, 28, 14, 0}, {140, 98, 70, 42, 28, 14, 0}
	, {180, 126, 90, 54, 36, 18, 0}, {500}, {500}, {100, 70, 50, 30, 20, 10, 0}
	, {100, 70, 50, 30, 20, 10, 0}
	};
string kebuke[]{
	"          _  __    ___     ___    _   _   _  __    ___   ",
	"         | |/ /   | __|   | _ )  | | | | | |/ /   | __|  ",
	"         | ' <    | _|    | _ \\  | |_| | | ' <    | _|   ",
	"         |_|\\_\\   |___|   |___/   \\___/  |_|\\_\\   |___|  ",
	"        _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| ",
	"        \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' "
	};
string kebuke2[]{
	"          :::    ::: :::::::::: :::::::::  :::    ::: :::    ::: :::::::::: ",
	"          :+:   :+:  :+:        :+:    :+: :+:    :+: :+:   :+:  :+:        ",
	"          +:+  +:+   +:+        +:+    +:+ +:+    +:+ +:+  +:+   +:+        ",
	"          +#++:++    +#++:++#   +#++:++#+  +#+    +:+ +#++:++    +#++:++#   ",
	"          +#+  +#+   +#+        +#+    +#+ +#+    +#+ +#+  +#+   +#+        ",
	"          #+#   #+#  #+#        #+#    #+# #+#    #+# #+#   #+#  #+#        ",
	"          ###    ### ########## #########   ########  ###    ### ########## ",
	};
string kebukech[]{
	"_________________________________________________________________________________________",
	"                                   可不可熟成紅茶                                   ",
	"------------------------------------------------------------------------------------------",
	"                               歡迎來到可不可熟成紅茶!                              "
	};
string teacompany[]{
	"\n                                    TEA COMPANY",
	"                                     __________",
	"                                     |   熟   |",
	"                         ------20    |        |    08----------",
	"                                     |   成   |                ",
	"                                     |________|"
	};
string s_sudoku[]{
	"\t .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ",
	"\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |",
	"\t| |    _______   | || | _____  _____ | || |  ________    | || |     ____     | || |  ___  ____   | || | _____  _____ | |",
	"\t| |   /  ___  |  | || ||_   _||_   _|| || | |_   ___ `.  | || |   .'    `.   | || | |_  ||_  _|  | || ||_   _||_   _|| |",
	"\t| |  |  (__ \\_|  | || |  | |    | |  | || |   | |   `. \\ | || |  /  .--.  \\  | || |   | |_/ /    | || |  | |    | |  | |",
	"\t| |   '.___`-.   | || |  | '    ' |  | || |   | |    | | | || |  | |    | |  | || |   |  __'.    | || |  | '    ' |  | |",
	"\t| |  |`\\____) |  | || |   \\ `--' /   | || |  _| |___.' / | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |   \\ `--' /   | |",
	"\t| |  |_______.'  | || |    `.__.'    | || | |________.'  | || |   `.____.'   | || | |____||____| | || |    `.__.'    | |",
	"\t| |              | || |              | || |              | || |              | || |              | || |              | |",
	"\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |",
	"\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' "
	};//11 lines
string s_1A2B[]{
	"   __o            o             __o       o__ __o   ",
	"   __|>          <|>          o/  v\\     <|     v\\  ",
	"     |           / \\         /|    <\\    / \\     <\\ ",
	"    <o>        o/   \\o       //    o/    \\o/     o/ ",
	"     |        <|__ __|>           /v      |__  _<|  ",
	"    < >       /       \\          />       |       \\ ",
	"     |      o/         \\o      o/        <o>      / ",
	"     o     /v           v\\    /v          |      o  ",
	"   __|>_  />             <\\  /> __o__/_  / \\  __/>  \n\n"
	};//9 lines
string KebukeMenu[]{
	"\t\t     _     ____  ___   _     _     ____ ",
	"\t\t    | |_/ | |_  | |_) | | | | |_/ | |_  ",
	"\t\t    |_| \\ |_|__ |_|_) \\_\\_/ |_| \\ |_|__ ",
	"\t\t\t\t   菜單",
	"\t\t\t\t   MENU\n",
	"  品 名             \t    價 錢      品 名                 價 錢\n"
	};//6 lines
string KebukeMenuSu[]{
	"\t\t     _     ____  ___   _     _     ____ ",
	"\t\t    | |_/ | |_  | |_) | | | | |_/ | |_  ",
	"\t\t    |_| \\ |_|__ |_|_) \\_\\_/ |_| \\ |_|__ ",
	"\t\t\t\t   菜單",
	"\t\t\t\t   MENU\n",
	"  品 名             \t    價 錢      品 名                 價 錢 \t     甜 度\n"
	};//6 lines
string KebukeMenuIce[]{
	"\t\t     _     ____  ___   _     _     ____ ",
	"\t\t    | |_/ | |_  | |_) | | | | |_/ | |_  ",
	"\t\t    |_| \\ |_|__ |_|_) \\_\\_/ |_| \\ |_|__ ",
	"\t\t\t\t   菜單",
	"\t\t\t\t   MENU\n",
	"  品 名             \t    價 錢      品 名                 價 錢 \t     甜 度\t\t冰度\n"
	};//6 lines
string s_drinks[]{
	"熟成紅茶", "麗春紅茶", "太妃紅茶", "胭脂紅茶", "雪藏紅茶", "熟成冷露", "雪花冷露", "春芽冷露","春芽綠茶",
	 "春梅冰茶", "冷露歐蕾", "熟成歐蕾", "白玉歐蕾", "熟成檸果", "胭脂多多", "雪藏末茶", "黃玉歐蕾", "墨玉歐特"
	};//18
string s_price[]{
	"M 25", "L 30", "M 25", "L 30", "M 30", "L 35", "M 35", "L 40", "M 45", "L 55",
	"M 25", "L 30", "M 25", "L 30", "M 25", "L 30", "M 25", "L 30", "M 35", "L 45",
	"M 40", "L 50", "M 40", "L 50", "M 50", "L 60", "M 50", "M 40", "L 50", "M 50",
	"L 60", "M 60", "L 70", "M 60"
	};
string s_sugar[]{
	" 100% 正常糖 ", "  70% 少　糖 ", "  50% 半　糖 ", "  30% 微　糖 ", "  20% 兩分糖 ", "  10% 一分糖 ", "   0% 無　糖 "
	};
string s_ice[]{
	"　正常冰 " , "　少　冰 ", "　微　冰 ", "　去　冰 ", "完全去冰 ", "　常　溫 ", "　　　溫 ", "　　　熱 "
	}; 
string s_bubble[3] = {"　　　  ", " 加白玉 ", " 加墨玉 "};
string kebukeshopgraph[]{
	"	`7MMF' `YMM' `7MM\"\"\"YMM  `7MM\"\"\"Yp, `7MMF'   `7MF'`7MMF' `YMM' `7MM\"\"\"YMM  ",
	"	  MM   .M'     MM    `7    MM    Yb   MM       M    MM   .M'     MM    `7  ",
	"	  MM .d\"       MM   d      MM    dP   MM       M    MM .d\"       MM   d    ",
	"	  MMMMM.       MMmmMM      MM\"\"\"bg.   MM       M    MMMMM.       MMmmMM    ",
	"	  MM  VMA      MM   Y  ,   MM    `Y   MM       M    MM  VMA      MM   Y  , ",
	"	  MM   `MM.    MM     ,M   MM    ,9   YM.     ,M    MM   `MM.    MM     ,M ",
	"	.JMML.   MMb..JMMmmmmMMM .JMMmmmd9     `bmmmmd\"'  .JMML.   MMb..JMMmmmmMMM "
	};                                                                 
string s_chat[]{
	" ______     __  __     ______     ______   ______     ______     ______     __    __    ",
	"/\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\__  _\\ /\\  == \\   /\\  __ \\   /\\  __ \\   /\\ \"-./  \\   ",
	"\\ \\ \\____  \\ \\  __ \\  \\ \\  __ \\  \\/_/\\ \\/ \\ \\  __<   \\ \\ \\/\\ \\  \\ \\ \\/\\ \\  \\ \\ \\-./\\ \\  ",
	" \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\ ",
	"  \\/_____/   \\/_/\\/_/   \\/_/\\/_/     \\/_/   \\/_/ /_/   \\/_____/   \\/_____/   \\/_/  \\/_/ "                                                                                
	};

int total = 0, newPrice, Price, mealNum, orderNum, amount, totalamount; //mealnum-->in process , ordernum-->how many orders are there right now

userlist LoadUsers();
void LoadOrderNum();
int WelcomeUI(int select);
int userUI(int select, int user_id, userlist users);
void userWelcomeScreen(int select, int user_id, userlist users);
int Login(userlist users);
void input_name(char name[]);
void input_username(char name[], char un[], int x);
void input_password(char name[], char un[], char pw[], char pw_tmp[], int x);
int sign_up(userlist users);

void modifyScreen(int select, int user_id, userlist users);
int modifyUI(int select, int user_id, userlist users);
void modifyName(int user_id, userlist users);
void modifyPassword_current(int user_id, userlist users, int correct);
void modifyPassword_new(int user_id, userlist users, int x);
void modifyPW(int user_id, userlist users);

void ChatRoom(char name[]);
void ChatRoomChooseScreen(int select);
int ChatRoomChooseUI(int select);
void ChooseFriendScreen(int select, userlist users, int user_id);
int ChooseFriendUI(int select, userlist users, int user_id);
void PrivateChatRoom(int friend_id, int user_id, userlist users);

void welcomeScreen(int select); // client or restaurant
void firstKEBUKE();
void welcomeKEBUKE();//print kebuke
void print_KEBUKE_User();
void print_KEBUKE_User_sleep();
void loggin_ING_Screen();

int Sudoku(int user_id);
void init_S(int p[][9][10]); //initailize the sudoku
void update_S(int p[][9][10], int R, int C, int N);
void Sudoku_Read(int no, int q[][9], int p[][9][10]); //讀進file裡的題目
void Sudoku_Print(int q[][9], int A[][9], int Row, int Clmn); //print the question
int Sudoku_Check(int User_A[][9], int p[][9][10], int R, int C);//是唯一解嗎
void Sudoku_UI(int Q[][9], int A[][9]);
void Sudoku_Print_Ans(int A[][9]);
bool S_isCorrect(int A[][9], int User_A[][9]);
void chooseSudokuGame(int select);
int chooseSudokuGame_UI(int select);
void print_s_sudoku();
int PlaySudokuAgainUI(int User_A[][9], int A[][9], int select, bool correct);
void PlaySudokuAgain(int User_A[][9], int A[9][9], int select, bool correct);

int XAXB_GAME(int user_id);
void XAXB_digit_cvrt(int n, int digit[]);
void XAXB(int a, int g, int AB[]);
bool XAXB_isLegal(int n);
void XAXB_init_pool(int pool[]);

void MenuScreen(int select, int cups, string s_ordered[100]);
int MenuUI(int select, int cups, string s_ordered[100]);
void BubbleScreen(int select, int drink, int cups, string s_ordered[100]);
int BubbleUI(int select, int drink, int cups, string s_ordered[100]);
void SugarScreen(int select, int drink, int bubble, int cups, string s_ordered[100]);
int SugarUI(int select, int drink, int bubble, int cups, string s_ordered[100]);
void IceScreen(int select, int drink, int bubble, int sugar, int cups, string s_ordered[100]);
int IceUI(int select, int drink, int bubble, int sugar, int cups, string s_ordered[100]);
void DoneScreen(int select, int drink, int bubble, int sugar, int ice, int cups, string s_ordered[100]);
int DoneUI(int select, int drink, int bubble, int sugar, int ice, int cups, string s_ordered[100]);
void OrderedDrink(int cups, string s_ordered[100]);
void PayScreen(int select, int done, int cups, string s_ordered[100]);
void PayUI(int select, int done, int cups, string s_ordered[100], int user_id, userlist users);
int DeletingDrink(int elem, int cups, string s_ordered[100]);
void OrderPrint(int cups, string s_ordered[100], int user_id, userlist users);
void CheckOrderStatus(int user_id, userlist users);
void PastOrder(int user_id, userlist users);
void addOrder(int user_id, userlist users, string TimeNow, int cups, string s_ordered[100], int total);
void addCardValue(int user_id, int value);

void LoadTotal();
void ShopWelcomeScreen(int select);
int ShopWelcomeUI(int select);
void OrdertoString(string s_shopOrders[100]);
int ShopNextOrderScreen(int select, string s_shopOrders[100]);
int ShopNextOrderUI(int select, string s_shopOrders[100]);
void ShopInProcessScreen(string s_shopOrders[100]);
int ShopInProcessUI(string s_shopOrders[100]);
void ShopCompleteOrder(int mealno);
void ShopCompletePrint();
void ShopAddValueScreen(int select, userlist users);
void ShopAddValueUI(int select, userlist users);
stocklist ShopLoadStock();
void ShopStockScreen(stocklist stock);

int main(){
	//chinese
	system("chcp 65001"); //設定字符集 （使用SetConsoleCP(65001)設定無效，原因未知）
    CONSOLE_FONT_INFOEX info = { 0 }; // 以下設定字型
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 18; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

    system("cls");
    welcomeKEBUKE();
	int n = 1;
	string s_ordered[100];
	string s_shopOrders[100];
	for(int i = 0; i < 100; i++){
		s_ordered[i] = "";
		s_shopOrders[i] = "";
	}
	stocklist stock;
	stock = ShopLoadStock();
	LoadOrderNum();
	do{
		n = WelcomeUI(n);
		if(n == 1){
			userlist users;
			users = LoadUsers();
			int user_id = Login(users), x = 0, doing = 0;
			if(user_id == 0){ // kebuke itself
				system("cls");
				do{
					if(x == 0)
						n = ShopWelcomeUI(n);
					switch(n){
						case 1:
							do{
								if(doing == 0){
									for(int i = 0; i < 100; i++)
										s_shopOrders[i] = "";
									OrdertoString(s_shopOrders);
									x = ShopNextOrderUI(x, s_shopOrders);
									if(x == 0)
										break;
								}	
								if(x == 1 || doing == 2){
									doing = ShopInProcessUI(s_shopOrders);
								}
								else
									doing = ShopInProcessUI(s_shopOrders);
								if(doing == 1){
									ShopCompleteOrder(mealNum);
									x = 1;
									doing = 0;
								}
								else{
									x = 0;
									break;			
								}
							}while(x != 0);
							continue;
						case 2:
							ShopAddValueUI(x, users);
							continue;
						case 3:
							ShopStockScreen(stock);
					}
				}while(n != 0);
				break;
			}
			else if(user_id == -1){ //signup
				user_id = sign_up(users);
				users = LoadUsers();
				system("cls");
				system("Color 9E");
				loggin_ING_Screen();
				print_KEBUKE_User_sleep();
				n = 1;
				int x;
				int sugar, drink, ice, bubble, cups;
				do{
					n = userUI(n, user_id, users);
					switch(n){
						case 1:
							x = 0;
							sugar = 0, drink = 0, ice = 0, bubble = 1, cups = 0, total = 0;
							do{
								x = 0;
								drink = MenuUI(x, cups, s_ordered);
								x = 1;
								bubble = BubbleUI(x, drink, cups, s_ordered);
								x = 0;
								sugar = SugarUI(x, drink, bubble, cups, s_ordered);
								ice = IceUI(x, drink, bubble, sugar, cups, s_ordered);
								cups++;
								x = 1;
								x = DoneUI(x, drink, bubble, sugar, ice, cups, s_ordered);
							}while(x != 0);
							PayUI(x, 0, cups, s_ordered, user_id, users);
							users = LoadUsers();
							continue;
						case 2:
							CheckOrderStatus(user_id, users);
							continue;
						case 3:
							x = 1;
							do{
								x = modifyUI(x, user_id, users);
								if(x == 1){ // change name
									modifyName(user_id, users);
									users = LoadUsers();
									x = 0;
								}
								else if(x == 2){ // change pw
									modifyPW(user_id, users);
									x = 0;
								}
							}while(x != 0);
							continue;
						case 4:

							ChatRoom(users.member[user_id].name);
							continue;
						case 5:
							x = 0;
							do{
								x = Sudoku(user_id);
							}while(x != 0);
							continue;
						case 6:
							x = 0;
							do{
								x = XAXB_GAME(user_id);
								//sleep(50000);
							}while(x != 0);
					}
				}while(n != 0);
				break;				
			}
			else{ // after user login
				system("cls");
				system("Color 9E");
				loggin_ING_Screen();
				print_KEBUKE_User_sleep();
				n = 1;
				int x;
				int sugar, drink, ice, bubble, cups;
				do{
					users = LoadUsers();
					n = userUI(n, user_id, users);
					switch(n){
						case 1:
							x = 0;
							sugar = 0, drink = 0, ice = 0, bubble = 1, cups = 0, total = 0;
							do{
								drink = MenuUI(x, cups, s_ordered);
								x = 1;
								bubble = BubbleUI(x, drink, cups, s_ordered);
								x = 0;
								sugar = SugarUI(x, drink, bubble, cups, s_ordered);
								ice = IceUI(x, drink, bubble, sugar, cups, s_ordered);
								cups++;
								x = 1;
								x = DoneUI(x, drink, bubble, sugar, ice, cups, s_ordered);
							}while(x != 0);
							PayUI(x, 0, cups, s_ordered, user_id, users);
							users = LoadUsers();
							continue;
						case 2:
							CheckOrderStatus(user_id, users);
							continue;
						case 3:
							x = 1;
							do{
								x = modifyUI(x, user_id, users);
								if(x == 1){ // change name
									modifyName(user_id, users);
									users = LoadUsers();
									x = 0;
								}
								else if(x == 2){ // change pw
									modifyPW(user_id, users);
									x = 0;
								}
							}while(x != 0);
							continue;
						case 4:
							x = 1;
							x = ChatRoomChooseUI(x);
							if(x == 1)
								ChatRoom(users.member[user_id].name);
							else if(x == 2){
								x = 1;
								if(user_id == 1)
									x = 2;
								x = ChooseFriendUI(x, users, user_id);
								if(x == 0)
									x = users.total_user_num;
								PrivateChatRoom(x, user_id, users);
							}
							continue;
						case 5:
							x = 0;
							do{
								x = Sudoku(user_id);
							}while(x != 0);
							continue;
						case 6:
							x = 0;
							do{
								x = XAXB_GAME(user_id);
							}while(x != 0);
					}
				}while(n != 0);
				break;
			}
		}
	}while(n != 0);
	
	return 0;
}


userlist LoadUsers(){
	userlist users;
	ifstream fin;
	fin.open("memberlist.txt");
	fin>>users.total_user_num;
	for(int i = 1; i < users.total_user_num + 1; i++){
		fin>>users.member[i].name;
		fin>>users.member[i].username;
		fin>>users.member[i].password;
		fin>>users.member[i].login_times;
		fin>>users.member[i].card_value;
		fin>>users.member[i].win_times;
		fin>>users.member[i].lose_times;
	}
	fin.close();
	return users;
}
void LoadOrderNum(){
	ifstream fin;
	fin.open("orderlist.txt");
	fin>>orderNum;
	fin.close();
}

//about input
void input_name(char name[]){
	do{
		system("cls");
		cout<<"[ Create Your Kebuke Account ]"<<endl<<endl;
		cout<<"Name: ";
		scanf("%s", name);
	}while(name[0] == '\0');
}
void input_username(char name[], char un[], int x){
	char c1,c2;
	int n = 0, i;
	do{
		system("cls");
		if(x == 1){
			cout<<"[ Create Your Kebuke Account ]"<<endl<<endl;
			cout<<"Name: "<<name<<endl<<endl;
			cout<<"**For username, you can use letters, numbers, or underline."<<endl;
			cout<<"** 4~12 characters. The first one must be a letter."<<endl;
		}
		cout<<"Username: ";
		for(i = 0; i < n; i++)
			cout<<un[i];
		c1 = getch();
		if(n == 0 && (c1 >= '0' && c1 <= '9'))
			continue;
		if(c1 == -32 || c1 == 0) // if it's a space or up, down, left, right
			c2 = getch();
		if((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z')||(c1 >= '0' && c1 <= '9')||c1 == '_')
		{
			if(n == 12)
				un[11] = c1;
			else{
				un[n] = c1;
				n++;
			}
		}
		if(c1 == 8 && n > 0) // 8: press backspace
			n--;
	}while(c1 != 13 || n == 0);
	un[n] = '\0'; //NULL terminator
}
void input_password(char name[], char un[], char pw[], char pw_tmp[], int x){
	char c1, c2;
	int n = 0, i;
	do{
		system("cls");
		if(x == 1){//for sign up
			cout<<"[ Create Your Kebuke Account ]"<<endl<<endl;
			cout<<"Name: "<<name<<endl<<endl;
			cout<<"**For username, you can use letters, numbers, or underline."<<endl;
			cout<<"** 4~12 characters. The first one must be a letter."<<endl;
			cout<<"Username: "<<un<<endl<<endl;
			cout<<"**Use 4~12 characters for your password."<<endl;
			cout<<"Password: ";

		}
		else if(x == 2){
			cout<<"[ Create Your Kebuke Account ]"<<endl<<endl;
			cout<<"Name: "<<name<<endl<<endl;
			cout<<"**For username, you can use letters, numbers, or underline."<<endl;
			cout<<"** 4~12 characters. The first one must be a letter."<<endl;
			cout<<"Username: "<<un<<endl<<endl;
			cout<<"**Use 4~12 characters for your password."<<endl;
			cout<<"Password: ";
			for(unsigned int i = 0; i < strlen(pw); i++){
			cout<<"*";
			}
			cout<<endl<<"Confirm your password: ";
		}
		else{
			cout<<"Username: "<<un<<endl;
			cout<<"Password: ";
		}

		for(i = 0; i < n; i++)
			cout<<"*";
		c1 = getch();
		if(c1 == -32 || c1 == 0)
			c2 = getch();
		if((c1 >= 'a' && c1 <= 'z')||(c1 >= 'A' && c1 <= 'Z')||(c1 >= '0' && c1 <= '9')||c1 == '_')
		{
			if(x == 0 || x == 1){
				if(n == 12)
					pw[11] = c1;
				else{
					pw[n] = c1;
					n++;
				}
			}
			if(x == 2){
				if(n == 12)
					pw_tmp[11] = c1;
				else{
					pw_tmp[n] = c1;
					n++;
				}
			}
			cout<<"*";
		}
		if(c1 == 8 && n > 0)
			n--;
	}while(c1 != 13 || n < 4);
	if(x == 2)
		pw_tmp[n] = '\0';
	else
		pw[n] = '\0';
}

//login signup & check password
void checkPassword(char name[], char un[], char pw[], char pw_tmp[]){
	char c1;
	do{
		input_password(name, un, pw ,pw_tmp, 2);
		if(strcmp(pw_tmp, pw) != 0){
			cout<<endl<<"These passwords didn't match. Press enter to try again.";
			c1 = getch();
		}
		else{
			cout<<endl<<"----Signed up successfully.----"<<endl;
			break;
		}
	}while(pw_tmp[0] == '\0' || c1 == 13);
}
int Login(userlist users){
	ifstream myfile;
	ofstream temp;
	string line;
	char name[3], username[13], password[13], c1, pw_tmp[3];
	int i, yes = 0;
	do{
		if(yes == 0){
			input_username(name, username, 0);
			char K[6] = {'K','E','B','U','K','E'};
			if(strcmp(username, K) == 0)
				return 0;
			input_password(name, username, password, pw_tmp, 0);
		}
		else
			input_password(name, username, password, pw_tmp, 0);
		for(i = 1; i < users.total_user_num + 1; i++){
			if(strcmp(username, users.member[i].username) == 0){//see if the username is in the list
				yes = 1;
				if(strcmp(password, users.member[i].password) == 0){
					myfile.open("memberlist.txt");
					temp.open("temp.txt");
					int flag = 0;
					while(getline(myfile, line)){
						int n = line.length();
						char char_line[n + 1];
						strcpy(char_line, line.c_str());
						if(strcmp(char_line, users.member[i].name) == 0){
							flag = 0;
							//temp<<"if name"<<endl;
						}
						if(flag == 0 && strcmp(char_line, username) == 0){
							flag++;
							//temp<<"if username"<<endl;
							if(strcmp(username, password) == 0){
								temp<<line<<endl;
								continue;
							}
						}

						if(flag == 1 && strcmp(char_line, password) == 0){
							temp<<line<<endl;
							flag++;
						}
						else if(flag == 2){
							temp<<users.member[i].login_times + 1<<endl;
							flag = 0;
						}
						else{
							temp<<line<<endl;
						}
					}
					myfile.close();
					temp.close();
					remove("memberlist.txt");
					rename("temp.txt", "memberlist.txt");
					return i; //return his or her id
				}
				else{
					cout<<"\nWrong password. Please input your password again."<<endl;
					sleep(1000);
					break;
					//input_password(name, username, password, pw_tmp, 0);
				}
			}
			
		}
		if(i == users.total_user_num + 1 && yes == 0){
			cout<<endl<<"You haven't registered yet."<<endl;
			cout<<"Press Enter to create a new account."<<endl;
			c1 = getch();
			//這裡要註冊新帳號 in the main function, if return -1 (below), go to create new account function
			return -1;
		}
	}while(true);
}
int sign_up(userlist users){
	ifstream myfile;
	ofstream temp;
	string line;
	//ofstream fout;
	char name[20], username[13], password[13], pw_tmp[13];

	input_name(name);
	input_username(name, username, 1);
	input_password(name, username, password, pw_tmp, 1);
	checkPassword(name, username, password, pw_tmp);
	//users.total_user_num
	myfile.open("memberlist.txt");
	temp.open("temp.txt");
	temp<<users.total_user_num + 1<<endl;

	int flag = 0;
	while(getline(myfile, line)){
		if(flag > 0)
			temp<<line<<endl;
		flag++;
	}

	temp<<name<<endl;
	temp<<username<<endl;
	temp<<password<<endl;
	temp<<1<<endl; // login times
	temp<<0<<endl; // card value
	temp<<0<<endl<<0<<endl; // win & lose times
	myfile.close();
	temp.close();
	remove("memberlist.txt");
	rename("temp.txt", "memberlist.txt");
	return users.total_user_num + 1;
}
void modifyScreen(int select, int user_id, userlist users){
	system("cls");
	system("Color CE");
	cout<<"\t  <修改會員資料>"<<endl;
	cout<<"   Hello, "<<users.member[user_id].name<<"! 您要修改的是..."<<endl;
	char L[3] = {' ', ' '}, R[3] = {' ', ' '};
	L[select] = '['; R[select] = ']';
	cout<<"  _____________________________"<<endl;
	cout<<"  |                           |"<<endl;
	cout<<"  |  "<<L[1]<<"Name"<<R[1]<<"                   |"<<endl;
	cout<<"  |  "<<L[2]<<"Password"<<R[2]<<"               |"<<endl;
	cout<<"  |  "<<L[0]<<"Go back to main page"<<R[0]<<"   |"<<endl;
	cout<<"  |___________________________|"<<endl;
}
int modifyUI(int select, int user_id, userlist users){
	char x, x1;
	do{
		modifyScreen(select, user_id, users);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 2) % 3;
			if(x1 == 80)
				select = (select + 1) % 3;
			if(x1 == 77)
				return select;
		}
	}while(x != 13);
	return select;
}

void modifyName(int user_id, userlist users){
	system("cls");
	string name, line;
	cout<<"\t<Changing Name>"<<endl;
	cout<<"  Your current name is: "<<users.member[user_id].name<<name<<endl;
	cout<<"  Please input your new name: ";
	cin>>name;

	ifstream myfile;
	ofstream temp;
	myfile.open("memberlist.txt");
	temp.open("temp.txt");
	int i = 1;
	while(getline(myfile, line)){
		if(i == 2 + (user_id - 1) * 7)
			temp<<name<<endl;
		else
			temp<<line<<endl;
		i++;
	}
	myfile.close();
	temp.close();
	remove("memberlist.txt");
	rename("temp.txt", "memberlist.txt");
	cout<<endl<<"---> You've changed your name into ["<<name<<"] successfully."<<endl;
	sleep(2500);
}
void modifyPassword_current(int user_id, userlist users, int correct){
	if(correct != 0){
		cout<<"\nIncorrect password. Type in again."<<endl;
		sleep(700);
	}
	char c1, c2, pw[13];
	int n = 0, i;
	do{
		system("cls");
		cout<<"\t<Changing Password>"<<endl;
		cout<<"Please input your current password: ";
		for(i = 0; i < n; i++)
			cout<<"*";
		//<<"<i: "<<i<<"> <n: "<<n<<">"<<endl
		c1 = getch();
		if(c1 == -32 || c1 == 0)
			c2 = getch();
		if((c1 >= 'a' && c1 <= 'z')||(c1 >= 'A' && c1 <= 'Z')||(c1 >= '0' && c1 <= '9')||c1 == '_')
		{
			if(n == 12)
				pw[11] = c1;
			else{
				pw[n] = c1;
				n++;
			}
			cout<<"*";
		}
		if(c1 == 8 && n > 0)
			n--;
	}while(c1 != 13 || n < 4);
	pw[n] = '\0';
	correct = strcmp(users.member[user_id].password, pw);
	if(correct != 0)
		modifyPassword_current(user_id, users, correct);
}
void modifyPassword_new(int user_id, userlist users, char pw[], char pw_tmp[], int x){
	char c1, c2;
	int n = 0, i;
	do{
		system("cls");
		if(x == 1){ //entering new password
			cout<<"\t<Changing Password>"<<endl;
			cout<<"Please input your current password: ";
			for(i = 0; i < 13; i++){
				if(users.member[user_id].password[i] != '\0')
					cout<<"*";
			}
			cout<<endl;
			cout<<"**Use 4~12 characters for your password."<<endl;
			cout<<"Password: ";
		}
		else if(x == 2){ // confirming
			cout<<"\t<Changing Password>"<<endl;
			cout<<"Please input your current password: ";
						for(i = 0; i < 13; i++){
				if(users.member[user_id].password[i] != '\0')
					cout<<"*";
			}
			cout<<"\n**Use 4~12 characters for your password."<<endl;
			cout<<"Password: ";
			for(int i = 0; i < strlen(pw); i++){
				cout<<"*";
			}
			cout<<endl<<"Confirm your password: ";
		}

		for(i = 0; i < n; i++)
			cout<<"*";
		c1 = getch();
		if(c1 == -32 || c1 == 0)
			c2 = getch();
		if((c1 >= 'a' && c1 <= 'z')||(c1 >= 'A' && c1 <= 'Z')||(c1 >= '0' && c1 <= '9')||c1 == '_')
		{
			if(x == 0 || x == 1){
				if(n == 12)
					pw[11] = c1;
				else{
					pw[n] = c1;
					n++;
				}
			}
			if(x == 2){
				if(n == 12)
					pw_tmp[11] = c1;
				else{
					pw_tmp[n] = c1;
					n++;
				}
			}
			cout<<"*";
		}
		if(c1 == 8 && n > 0)
			n--;
	}while(c1 != 13 || n < 4);
	if(x == 2)
		pw_tmp[n] = '\0';
	else
		pw[n] = '\0';
}
void modifyPassword_check(int user_id, userlist users, char pw[], char pw_tmp[]){
	char c1;
	do{
		modifyPassword_new(user_id, users, pw, pw_tmp, 2);
		if(strcmp(pw_tmp, pw) != 0){
			cout<<endl<<"These passwords didn't match. Press enter to try again.";
			c1 = getch();
		}
		else{
			cout<<endl<<"----Changed password successfully.----"<<endl;
			break;
		}
	}while(pw_tmp[0] == '\0' || c1 == 13);
}
void modifyPW(int user_id, userlist users){
	char  pw[13], pw_tmp[13];
	string line, username = "";
	modifyPassword_current(user_id, users, 0);
	modifyPassword_new(user_id, users, pw, pw_tmp, 1);
	modifyPassword_check(user_id, users, pw, pw_tmp);

	ifstream myfile;
	ofstream temp;
	myfile.open("memberlist.txt");
	temp.open("temp.txt");
	int flag = 0;
	while(getline(myfile, line)){
		char char_line[line.length()];
		strcpy(char_line, line.c_str());
		if(flag == 1){
			string str(pw);
			temp<<pw<<endl;
			flag = 0;
		}
		else
			temp<<line<<endl;
		if(strcmp(char_line, users.member[user_id].username) == 0)
			flag = 1;
	}
	myfile.close();
	temp.close();
	remove("memberlist.txt");
	rename("temp.txt", "memberlist.txt");
	sleep(2500);
}

void welcomeScreen(int select){
	system("cls");
	firstKEBUKE();
	char L[2] = {' ', ' '}, R[2] = {' ', ' '};
	L[select] = '['; R[select] = ']';
	cout<<"\t\t\t\t       "<<L[1]<<"LOGIN"<<R[1]<<endl;
	cout<<"\t\t\t\t        "<<L[0]<<"EXIT"<<R[0]<<endl;
}
int WelcomeUI(int select){
	char x, x1;
	do{
		welcomeScreen(select);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72 || x1 == 80)
				select = (select + 1) % 2;
			if(x1 == 77)
				return select;
		}
	}while( x != 13);
	return select;
}
void welcomeKEBUKE(){
	system("Color 5E");
	int i;
	for(i = 0; i < 6; i++){
		cout<<teacompany[i]<<endl;
		sleep(50);
	}
	for(i = 0; i < 7; i++){
		cout<<kebuke2[i]<<endl;
		sleep(50);
	}
	for(i = 0; i < 4; i++){
		cout<<kebukech[i]<<endl;
		if(i == 3)
			sleep(800);
		else
			sleep(100);
	}
	sleep(200);
}
void firstKEBUKE(){
	int i;
	//system("cls");
	for(i = 0; i < 6; i++)
		cout<<teacompany[i]<<endl;
	for(i = 0; i < 7; i++)
		cout<<kebuke2[i]<<endl;
	for(i = 0; i < 4; i++)
		cout<<kebukech[i]<<endl;
}

int userUI(int select, int user_id, userlist users){
	char x, x1;
	do{
		userWelcomeScreen(select, user_id, users);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 6) % 7;
			if(x1 == 80)
				select = (select + 1) % 7;
			if(x1 == 77)
				return select;
		}
		if(x >= '0' && x <= '6'){
			select = x -'0';
			return select;
		}
	}while(x != 13);
	return select;
}
void userWelcomeScreen(int select, int user_id, userlist users){
	system("cls");
	system("Color 9E");
	print_KEBUKE_User();
	cout<<"\t\t\t~Welcome to KEBUKE~\n  "<<endl;
	cout<<users.member[user_id].name<<", you've logged in for "<<
	users.member[user_id].login_times<<" times. The balance of your member card is "<<users.member[user_id].card_value<<"."<<endl;
	cout<<"_______________________________________________________________________________________"<<endl;
	char L[7], R[7];
	for(int i = 0; i < 7; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	L[select] = '['; R[select] = ']';
	cout<<"\t\t\t"<<L[1]<<'1'<<R[1]<<"Order"<<endl;
	cout<<"\t\t\t"<<L[2]<<'2'<<R[2]<<"查訂單"<<endl;
	cout<<"\t\t\t"<<L[3]<<'3'<<R[3]<<"修改會員資料"<<endl;
	cout<<"\t\t\t"<<L[4]<<'4'<<R[4]<<"Chat Room"<<endl;
	cout<<"\t\t\t"<<L[5]<<'5'<<R[5]<<"Sudoku"<<endl;
	cout<<"\t\t\t"<<L[6]<<'6'<<R[6]<<"1A2B"<<endl; 
	cout<<"\t\t\t"<<L[0]<<'0'<<R[0]<<"EXIT"<<endl; 	
}
void print_KEBUKE_User(){
	for(int i = 0; i < 6; i++)
		cout<<kebuke[i]<<endl;
}
void print_KEBUKE_User_sleep(){
	int i;
	for(i = 0; i < 6; i++){
		cout<<kebuke[i]<<endl;
		sleep(50);
	}
}
void loggin_ING_Screen(){
	cout<<"\n\n\n          LOGGING IN."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN ."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN  ."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN   ."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN    ."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN     ."<<endl;
	sleep(100);
	system("cls");
	cout<<"\n\n\n          LOGGING IN      ."<<endl;
	sleep(100);
	system("cls");
}


//SUDOKU!!!!!!!!!!
void init_S(int p[][9][10]){ // initialize the pool. if the num in the block is 1, it's available for entering an answer
	int r, c, n;
	for(r = 0; r < 9; r++){
		for(c = 0; c < 9; c++){
			for(n = 1; n < 10; n++){
				p[r][c][n] = 1;
			}
		}
	}
	}
void update_S(int p[][9][10], int R, int C, int N){
	int r, c;
	for(c = 0; c < 9; c++)
		p[R][c][N] = 0;
	for(r = 0; r < 9; r++)
		p[r][C][N] = 0;
	for(r = (R/3)*3; r <= (R/3) * 3 + 2; r++){
		for(c = (C/3)*3; c<= (C/3) * 3 + 2; c++)
			p[r][c][N] = 0;		
	}
	p[R][C][N] = 1;
	}
void Sudoku_Read(int no, int q[][9], int p[][9][10]){
	ifstream fin; //fin is a variable
	string filename = "Q" + to_string(no) + ".txt";
	fin.open(filename);
	int n;
	for(int r = 0; r < 9; r++){
		for(int c = 0; c < 9; c++){
			fin>>n;
			q[r][c] = n;
			if(n > 0)
				update_S(p, r, c, n);
		}
	}
	fin.close();
	}
void Sudoku_Print(int Q[][9],int A[][9],int R,int C){
	//HW:finish
	int r,c;
	system("cls");
	char left[9][9],right[9][9];
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
		{
			left[r][c] = ' ';
			right[r][c] = ' ';
		}
	if(Q[R][C] == 0)
	{
		left[R][C] = '<';
		right[R][C] = '>';
		//SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_RED);
	}
	else
	{

		left[R][C] = '[';
		right[R][C] = ']';
	}
	for(r=0;r<9;r++){
		for(c=0;c<9;c++)
		{
			cout<<left[r][c];
			if(A[r][c]==0)
				cout<<" ";
			else
				cout << A[r][c];
			cout<<right[r][c];
			if(c==2||c==5)
				cout <<"|";
		}
		cout << endl;
		if(r==2||r==5)
			cout << "----------------------------"<<endl;
		}
	}
void Sudoku_UI(int Q[][9], int A[][9]){
	int r = 0, c = 0;
	char c1, c2;
	do{
		Sudoku_Print(Q, A, r, c);
		c1 = getch();
		if(c1 == -32){
			c2 = getch();
			switch(c2){
				case 72:
					r = (r + 8) % 9;
					break;
				case 75:
					c = (c + 8) % 9;
					break;
				case 77:
					c = (c + 1) % 9;
					break;
				case 80:
					r = (r + 1) % 9; 
					break;
			}
		}
		if(c1 >= '0' && c1 <= '9')
			if(Q[r][c] == 0)
				A[r][c] = c1 - '0';
		if(c1 == 8)
			A[r][c] = 0;
	}while(c1 != 13);
	}
int Sudoku_Check(int User_A[][9], int p[][9][10],int R,int C){
	//HW:another rule
	int sum = 0, n, r, c, a, cnt = 0, ans_temp;
	for(n = 1; n <= 9; n++)
	{
		sum += p[R][C][n];
		if(p[R][C][n] == 1)
			a = n;
		for(r = 0; r < 9; r++){
			if(User_A[r][C] == n)
				p[R][C][n] = 0;
		}
		for(c = 0; c < 9; c++){
			if(User_A[R][c] == n)
				p[R][C][n] = 0;
		}

		for(r = (R/3)*3; r <= (R/3)*3 + 2; r++){
			for(c = (C/3)*3; c <= (C/3)*3 + 2; c++)
				if(User_A[r][c] == n)
					p[R][C][n] = 0;
		}
	}

	for(int i = 1; i < 10; i++){
		if(p[R][C][i] == 1){
			cnt++;
			ans_temp = i;
		}
	}
	if(cnt == 1) return ans_temp;

	if(sum == 1)
		return a;
	else
		return 0;
	}
void Sudoku_Print_Ans(int A[][9]){
	int r, c;
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			//cout<<left[r][c];
			if(A[r][c]==0)
				cout << "  ";
			else
				cout <<" "<< A[r][c];
			//cout <<right[r][c];
			if(c==2||c==5)
				cout <<" |";
		}
		cout << endl;
		if(r==2||r==5)
			cout << "----------------------"<<endl;
	}
	}
bool S_isCorrect(int A[][9], int User_A[][9]){
	int yes = 1;
	for(int r = 0; r < 9; r++){
		for(int c = 0; c < 9; c++){
			if(A[r][c] != User_A[r][c])
				yes = 0;
		}
	}
	if(yes == 0)
		return false;
	else
		return true;
	}
int Sudoku(int user_id){
	int r,c,n,modified = 1;
	int Q[9][9];
	int A[9][9], User_A[9][9];
	int pool[9][9][10];
	system("COLOR F0");
	init_S(pool);
	int choice = 1;

	choice = chooseSudokuGame_UI(choice);
	//本來有寫do while
	if(choice == 0)
		return 0;
	if(choice == 3){
		srand(time(NULL));
		choice = rand() % 2 + 1;
	}
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<"."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<" ."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<"  ."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<"   ."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<"    ."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tLoading Question "<<choice<<"     ."<<endl;
	sleep(50);
	system("cls");
	cout<<"\n\n\t\tQuestion "<<choice<<endl;
	cout<<"\t\tGood luck!"<<endl;
	sleep(2000);
	Sudoku_Read(choice,Q,pool);
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
		{
			A[r][c] = Q[r][c];
			User_A[r][c] = Q[r][c];
		}
	cout << endl;
	Sudoku_UI(Q,User_A);
	while(modified == 1)
	{
		modified = 0;
		for(r = 0; r < 9; r++)
		{
			for(c = 0; c < 9; c++)
			{
				if(A[r][c] == 0)
				{
					n = Sudoku_Check(A, pool, r, c); //0-9
					if(n > 0)
					{
						A[r][c] = n;
						update_S(pool, r, c, n);
						modified = 1;
					}
				}
			}
		}
	}
	Sudoku_Print_Ans(A);

	if(S_isCorrect(A,User_A))
		addCardValue(user_id, 20);

	int play = 1;
	play = PlaySudokuAgainUI(User_A, A, play, S_isCorrect(A,User_A));
	return play;
}
void print_s_sudoku(){
	for(int i = 0; i < 11; i++)
		cout<<s_sudoku[i]<<endl;
}
void chooseSudokuGame(int select){ //SCREEN
	system("cls");
	system("COLOR F0");
	print_s_sudoku();
	char L[4] = {' ', ' ', ' ', ' '}, R[4] = {' ', ' ', ' ', ' '};
	L[select] = '['; R[select] = ']';
	cout<<"\t\t\t\t "<<L[1]<<"1"<<R[1]<<"Question One"<<endl;
	cout<<"\t\t\t\t "<<L[2]<<"2"<<R[2]<<"Question Two"<<endl;
	cout<<"\t\t\t\t "<<L[3]<<"3"<<R[3]<<"Random"<<endl;
	cout<<"\t\t\t\t "<<L[0]<<"0"<<R[0]<<"BACK"<<endl;
	cout<<"\t\t\tYou can also type in your choice."<<endl;
}
int chooseSudokuGame_UI(int select){
	char x, x1;
	do{
		chooseSudokuGame(select);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 3) % 4;
			if(x1 == 80)
				select = (select + 1) % 4;
			if(x1 == 77)
				return select;
		}
		if(x >= '0' && x <= '3')
			return x - '0';
	}while(x != 13);
	return select;
}
void PlaySudokuAgain(int User_A[][9], int A[9][9], int select, bool correct){
	system("cls");
	Sudoku_Print_Ans(User_A);
	cout<<endl<<"Answer:"<<endl;
	Sudoku_Print_Ans(A);
	cout<<endl;
	if(correct){
		cout<<"You solved it!"<<endl;
		cout<<"$20 is added to your member card."<<endl;
	}
	else
		cout<<"Your answer is not correct."<<endl;

	char L[2] = {' ', ' '}, R[2] = {' ', ' '};
	L[select] = '['; R[select] = ']';
	cout<<"\t\t\t\t       "<<L[1]<<"Play Sudoku again?"<<R[1]<<endl;
	cout<<"\t\t\t\t        "<<L[0]<<"Go Back to Main Page."<<R[0]<<endl;
}
int PlaySudokuAgainUI(int User_A[][9], int A[9][9], int select, bool correct){
	char x, x1;
	do{
		PlaySudokuAgain(User_A, A, select, correct);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72 || x1 == 80)
				select = (select + 1) % 2;
			if(x1 == 77)
				return select;
		}
	}while( x != 13);
	cout<<select<<endl;
	sleep(2000);
	return select;	
}

//XAXB
void addCardValue(int user_id, int value){
	ifstream myfile;
	ofstream temp;
	string line;
	myfile.open("memberlist.txt");
	temp.open("temp.txt");
	int no_line = 1 + (user_id - 1) * 7 + 5;
	int cnt = 1;
	while(getline(myfile, line)){
		if(no_line == cnt){
			stringstream geek(line);
			int x = 0;
			geek >> x;
			x += value;
			temp<<x<<endl;
		}
		else
			temp<<line<<endl;
		cnt++;
	}
	myfile.close();
	temp.close();
	remove("memberlist.txt");
	rename("temp.txt", "memberlist.txt");
}
int XAXB_GAME(int user_id){
	system("cls");
	system("COLOR F0");
	for(int i = 0; i < 9; i++)
		cout<<s_1A2B[i]<<endl;
	srand(time(NULL));
	chrono::steady_clock timecounter;
	int comG, comA, userA, userG, comAB[2], AB_tmp[2], userAB[2];
	int pool[10000];
	int i, com_count = 1, user_count = 1;

	do{
		cout<<"Please enter your answer: ";
		cin>>userA;
	}while(XAXB_isLegal(userA) == false || userA >= 10000);

	auto start = timecounter.now();
	XAXB_init_pool(pool);
	do{
		comA = rand() % 10000;
	}while(XAXB_isLegal(comA) == false);
	//computer guess user's answer
	do{
		for(i = 0; i < 10000; i++){
			if(pool[i] == 1)
				break;
		}
		comG = i;
		XAXB(userA, comG, comAB);
		if(com_count == 1)
			cout<<endl<<"Time for computer to guess!"<<endl;
		else
			cout<<endl<<"--Computer's Turn--"<<endl;
		cout<<"("<<com_count<<")"<<comG<<"  "<<comAB[0]<<"A"<<comAB[1]<<"B"<<endl;
		com_count++;
		
		for(i = 0; i<10000; i++){
			if(pool[i] == 1){
				XAXB(comG, i, AB_tmp);
				if(comAB[0] != AB_tmp[0] || comAB[1] != AB_tmp[1]){
					pool[i] = 0;
				}
			}
		}

	//---user guesses computer

	//init_pool(pool);
		if(user_count == 1){
			cout<<endl<<"Let's guess the number that your computer has in mind!"<<endl;
			cout<<"Enter your guess below."<<endl;
		}
		else 
			cout<<"--Your Turn--"<<endl;
		cout<<"("<<user_count<<")";
		cin>>userG;
		user_count++;
		while(XAXB_isLegal(userG) == false || userG >= 10000){
			cout<<"!Your guess is not legal. Please enter another answer: ";
			cin>>userG;
		}
		XAXB(userG, comA, userAB);
		cout<<"-->"<<userAB[0]<<"A"<<userAB[1]<<"B"<<endl;
		if(userAB[0] == 4 && comAB[0] != 4){
			cout<<"Seems that you're smarter than your computer! You won!!!"<<endl;
			cout<<"$20 is added to your member card."<<endl;
			addCardValue(user_id, 20);
			break;
		}
		if(comAB[0] == 4 && userAB[0] != 4){
			cout<<"Work harder, man. You lost.";
			break;
		}
		if(comAB[0] == 4 && userAB[0] == 4){
			cout<<"You're as smart as the computer. WOW!"<<endl;
			cout<<"$10 is added to your member card."<<endl;
			addCardValue(user_id, 10);
			break;
		}
	}while(userAB[0] != 4 || comAB[0] != 4);
	auto end = timecounter.now();
	auto time_span = static_cast<chrono::duration<double>>(end - start);
	cout<<endl<<"You've spent "<<time_span.count()<<" seconds."<<endl;
	cout<<"Press <Enter> to play again or press <Backspace> to go back to main page."<<endl;
	char c = getch();
	if(c == 13)
		return 1;
	else if(c == 8)
		return 0;
	else
		return 0;
}
void XAXB_digit_cvrt(int n, int digit[]){
	digit[0] = n/1000;
	digit[1] = n/100 %10;
	digit[2] = n/10 % 10;
	digit[3] = n%10;
}
void XAXB(int a, int g, int AB[]){
	int d_a[4], d_g[4];
	XAXB_digit_cvrt(a,d_a); XAXB_digit_cvrt(g,d_g);
	int A = 0,B = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(i==j && d_a[i] == d_g[i])
				A++;
			else if(d_a[i] == d_g[j])
				B++;
		}
	}
	AB[0] = A; AB[1] = B;
}
bool XAXB_isLegal(int n){
	int d[4];
	XAXB_digit_cvrt(n,d);
	for(int i=0; i<4; i++){
		for(int j=i+1; j<4; j++){
			if(d[i] == d[j])
				return false;
		}
	}
	return true;
}
void XAXB_init_pool(int pool[]){
	for(int i=0; i<10000; i++){
		if(XAXB_isLegal(i)==true)
			pool[i] = 1;
		else
			pool[i] = 0;
	}
}

void MenuScreen(int select, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenu[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	L[select] = '['; R[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"  加白玉 10元 / 加墨玉 15元 / 不加"<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<"[YES]"<<" |  NO "<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點："<<endl;
	OrderedDrink(cups, s_ordered);
}
int MenuUI(int select, int cups, string s_ordered[100]){
	char x, x1;
	do{
		MenuScreen(select, cups, s_ordered);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72){
				if(select >= 2 && select <= 16 && select % 2 == 0){
					select = (select - 2) % 17;
					continue;
				}
				if(select == 0 || select == 19){
					select = 33;
					continue;
				}
				if(select == 1)
					select = 16;
				if(select >= 3 && select <= 17 && select % 2 == 1)
					select = (select - 2) % 18;
				if(select == 18)
					select = 17;
				if(select == 27 || select == 28){
					select = 26;
					continue;
				}
				if((select >= 20 && select <= 26 && select % 2 == 0) || (select >= 29 && select <= 33 && select % 2 == 1)
					||(select == 30 || select == 32 || select == 21 || select == 23 || select == 25))
					select = (select - 2) % 34;
			}
			if(x1 == 80){
				if((select >= 0 && select <= 14 && select % 2 == 0) || (select >= 1 && select <= 15 && select % 2 == 1)
				 || (select >= 18 && select <= 24 && select % 2 == 0) || (select >= 19 && select <= 23 && select % 2 == 1)
				  || (select >= 27 && select <= 31)){
					select += 2;
					continue;
				}
				if(select == 16){
					select = 1;
					continue;
				}
				if(select == 17){
					select = 18;
					continue;
				}
				if(select == 26){
					select = 27;
					continue;
				}
				if(select == 33)
					select = 0;
				if(select == 25)
					select = 26;
				if(select == 32)
					select = 33;
				
			}
			if(x1 == 77){
				if((select >= 0 && select <= 16 && select % 2 == 0) || (select >= 18 && select <= 24 && select % 2 == 0) ||(select >= 27 && select <= 31 && select % 2 == 1)){ //熟成紅茶到春芽　中杯　按右鍵往大杯
					select += 1;
					continue;
				}
				if(select >= 0 && select <= 9 && select % 2 == 1){ //熟成紅茶到雪藏　大杯　往右邊那排
					select += 17;
					continue;
				}
				if(select >= 11 && select <= 17 && select % 2 == 1){ //熟成冷露到春芽　大杯　往右邊那排
					select += 16;
					continue;
				}
				if(select == 26)
					select = 8;
				if(select == 33)
					select = 16;
				if(select >= 19 && select <= 25 && select % 2 == 1)
					select -= 19;
				if(select >= 28 && select <= 32 && select % 2 == 0)
					select -= 18;
			}
			if(x1 == 75){
				if((select >= 1 && select <= 17 && select % 2 == 1) || (select >= 19 && select <= 25 && select % 2 == 1) || (select >= 28 && select <= 32 && select % 2 == 0)){
					select -= 1;
					continue;
				}
				if(select >= 0 && select <= 6 && select % 2 == 0){
					select += 19;
					continue;
				}
				if(select == 8){
					select = 26;
					continue;
				}
				if(select == 16){
					select = 33;
					continue;
				}
				if(select >= 10 && select <= 14 && select % 2 == 0){
					select += 18;
					continue;
				}
				if(select == 26)
					select = 9;
				if(select == 33)
					select = 17;
				if(select >= 18 && select <= 24 && select % 2 == 0)
					select -= 17;
				if(select >= 27 && select <= 31 && select % 2 == 1)
					select -= 16;
			}
		}
	}while(x != 13);
	return select;
}
void BubbleScreen(int select, int drink, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenu[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	char BL[3] = {' ', ' ', ' '}, BR[3] = {' ', ' ', ' '};
	L[drink] = '['; R[drink] = ']';
	BL[select] = '['; BR[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<" "<<BL[1]<<"加白玉 10元"<<BR[1]<<"/"<<BL[2]<<"加墨玉 15元"<<BR[2]<<"/"<<BL[0]<<"不加"<<BR[0]<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<"[YES]"<<" |  NO "<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點："<<endl;
	OrderedDrink(cups, s_ordered);
}
int BubbleUI(int select, int drink, int cups, string s_ordered[100]){
	char x, x1;
	do{
		BubbleScreen(select, drink, cups, s_ordered);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 77)
				select = (select + 1) % 3;
			if(x1 == 75)
				select = (select + 2) % 3;
		}
	}while(x != 13);
	return select;
}
void SugarScreen(int select, int drink, int bubble, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenuSu[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	char BL[3] = {' ', ' ', ' '}, BR[3] = {' ', ' ', ' '};
	char SL[7], SR[7];
	for(int i = 0; i < 7; i++){
		SL[i] = ' ';
		SR[i] = ' ';
	}
	L[drink] = '['; R[drink] = ']';
	BL[bubble] = '['; BR[bubble] = ']';
	SL[select] = '['; SR[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<"\t  "<<SL[0]<<"100% 正常糖"<<SR[0]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<"\t  "<<SL[1]<<" 70% 少　糖"<<SR[1]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<"\t  "<<SL[2]<<" 50% 半　糖"<<SR[2]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<"\t  "<<SL[3]<<" 30% 微　糖"<<SR[3]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<"\t\t  "<<SL[4]<<" 20% 二分糖"<<SR[4]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<"\t  "<<SL[5]<<" 10% 一分糖"<<SR[5]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<"\t  "<<SL[6]<<"  0% 無　糖"<<SR[6]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<" "<<BL[1]<<"加白玉 10元"<<BR[1]<<"/"<<BL[2]<<"加墨玉 15元"<<BR[2]<<"/"<<BL[0]<<"不加"<<BR[0]<<endl;
	if(drink == 12 || drink == 13 || drink == 18 || drink == 19 || drink ==  20
		|| drink == 21 || drink == 29 || drink ==  30)
	cout<<"此款甜度固定，無法調整. Press any button to continue"<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<"[YES]"<<" |  NO "<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點："<<endl;
	OrderedDrink(cups, s_ordered);
}
//if drink == 12, 13, 18, 19, 20, 21, 29, 30 甜度固定
//drink 29, 30 熱量未知
int SugarUI(int select, int drink, int bubble, int cups, string s_ordered[100]){
	char x, x1;
	if(drink == 12 || drink == 13 || drink == 18 || drink == 19 || drink ==  20
		|| drink == 21 || drink == 29 || drink ==  30){
		SugarScreen(0, drink, bubble, cups, s_ordered);
		x = getch();
		select = 0;
	}
	else{
		do{
			SugarScreen(select, drink, bubble, cups, s_ordered);
			x = getch();
			if(x == -32){
				x1 = getch();
				if(x1 == 72)
					select = (select + 6) % 7;
				if(x1 == 80)
					select = (select + 1) % 7;
				if(x1 == 77)
					return select;
			}
		}while(x != 13);
	}
	return select;
}
void IceScreen(int select, int drink, int bubble, int sugar, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenuIce[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	char BL[3] = {' ', ' ', ' '}, BR[3] = {' ', ' ', ' '};
	char SL[7], SR[7];
	for(int i = 0; i < 7; i++){
		SL[i] = ' ';
		SR[i] = ' ';
	}
	char IL[8], IR[8];
	for(int i = 0; i < 8; i++){
		IL[i] = ' ';
		IR[i] = ' ';
	}
	L[drink] = '['; R[drink] = ']';
	BL[bubble] = '['; BR[bubble] = ']';
	SL[sugar] = '['; SR[sugar] = ']';
	IL[select] = '['; IR[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<"\t  "<<SL[0]<<"100% 正常糖"<<SR[0]<<"\t 　　 "<<IL[0]<<"正常冰"<<IR[0]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<"\t  "<<SL[1]<<" 70% 少　糖"<<SR[1]<<"\t 　　 "<<IL[1]<<"少　冰"<<IR[1]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<"\t  "<<SL[2]<<" 50% 半　糖"<<SR[2]<<"\t 　　 "<<IL[2]<<"微　冰"<<IR[2]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<"\t  "<<SL[3]<<" 30% 微　糖"<<SR[3]<<"\t 　　 "<<IL[3]<<"去　冰"<<IR[3]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<"\t\t  "<<SL[4]<<" 20% 二分糖"<<SR[4]<<"\t 　  "<<IL[4]<<"完全去冰"<<IR[4]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<"\t  "<<SL[5]<<" 10% 一分糖"<<SR[5]<<"\t 　　 "<<IL[5]<<"常　溫"<<IR[5]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<"\t  "<<SL[6]<<"  0% 無　糖"<<SR[6]<<"\t 　　　 "<<IL[6]<<"溫"<<IR[6]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<"\t\t\t 　　　 "<<IL[7]<<"熱"<<IR[7]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<" "<<BL[1]<<"加白玉 10元"<<BR[1]<<"/"<<BL[2]<<"加墨玉 15元"<<BR[2]<<"/"<<BL[0]<<"不加"<<BR[0]<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<"[YES]"<<" |  NO "<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點："<<endl;
	OrderedDrink(cups, s_ordered);
}
int IceUI(int select, int drink, int bubble, int sugar, int cups, string s_ordered[100]){
	char x, x1;
	do{
		IceScreen(select, drink, bubble, sugar, cups, s_ordered);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 7) % 8;
			if(x1 == 80)
				select = (select + 1) % 8;
			if(x1 == 77){
				int drinkType;
				if(drink >= 0 && drink <= 26)
					drinkType = drink / 2;
				if(drink >= 27 && drink <= 33)
					drinkType = (drink + 1) / 2;
				string stmp = "";
				stmp += s_drinks[drinkType];
				stmp += s_price[drink][0];
				stmp += s_sugar[sugar];
				stmp += s_ice[select];
				stmp += s_bubble[bubble];
				stmp += " $";
				if(bubble != 0){
					string s_p = "";
					s_p += s_price[drink][2]; s_p += s_price[drink][3];
					stringstream geek(s_p);
					geek>>newPrice;
					if(bubble == 1)
						newPrice += 10;
					else
						newPrice += 15;
					total += newPrice;
					stmp += to_string(newPrice);
				}
				else{
					string s_p = "";
					s_p += s_price[drink][2]; s_p += s_price[drink][3];
					stringstream geek(s_p);
					geek>>Price;
					total += Price;
					stmp += s_price[drink][2]; stmp += s_price[drink][3];
				}
				stmp += " ";
				if(Calorie[drink][sugar] < 10)
					stmp += "  ";
				if(Calorie[drink][sugar] >= 10 && Calorie[drink][sugar] < 100)
					stmp += " ";
				stmp += to_string(Calorie[drink][sugar]);
				stmp += " KCal";
				s_ordered[cups] = stmp;
				return select;
			}
		}
	}while(x != 13);
	int drinkType;
	if(drink >= 0 && drink <= 26)
		drinkType = drink / 2;
	if(drink >= 27 && drink <= 33)
		drinkType = (drink + 1) / 2;
	string stmp = "";
	stmp += s_drinks[drinkType];
	stmp += s_price[drink][0];
	stmp += s_sugar[sugar];
	stmp += s_ice[select];
	stmp += s_bubble[bubble];
	stmp += " $";
	if(bubble != 0){
		string s_p = "";
		s_p += s_price[drink][2]; s_p += s_price[drink][3];
		stringstream geek(s_p);
		geek>>newPrice;
		if(bubble == 1)
			newPrice += 10;
		else
			newPrice += 15;
		total += newPrice;
		stmp += to_string(newPrice);
	}
	else{
		string s_p = "";
		s_p += s_price[drink][2]; s_p += s_price[drink][3];
		stringstream geek(s_p);
		geek>>Price;
		total += Price;
		stmp += s_price[drink][2]; stmp += s_price[drink][3];
	}
	stmp += " ";
	if(Calorie[drink][sugar] < 10)
		stmp += "  ";
	if(Calorie[drink][sugar] >= 10 && Calorie[drink][sugar] < 100)
		stmp += " ";
	stmp += to_string(Calorie[drink][sugar]);
	stmp += " KCal";
	s_ordered[cups] = stmp;
	return select;
}
void DoneScreen(int select, int drink, int bubble, int sugar, int ice, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenuIce[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	char BL[3] = {' ', ' ', ' '}, BR[3] = {' ', ' ', ' '};
	char SL[7], SR[7];
	for(int i = 0; i < 7; i++){
		SL[i] = ' ';
		SR[i] = ' ';
	}
	char IL[8], IR[8];
	for(int i = 0; i < 8; i++){
		IL[i] = ' ';
		IR[i] = ' ';
	}
	char DL[2] = {' ', ' '}, DR[2] = {' ', ' '};
	L[drink] = '['; R[drink] = ']';
	BL[bubble] = '['; BR[bubble] = ']';
	SL[sugar] = '['; SR[sugar] = ']';
	IL[ice] = '['; IR[ice] = ']';
	DL[select] = '['; DR[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<"\t  "<<SL[0]<<"100% 正常糖"<<SR[0]<<"\t 　　 "<<IL[0]<<"正常冰"<<IR[0]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<"\t  "<<SL[1]<<" 70% 少　糖"<<SR[1]<<"\t 　　 "<<IL[1]<<"少　冰"<<IR[1]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<"\t  "<<SL[2]<<" 50% 半　糖"<<SR[2]<<"\t 　　 "<<IL[2]<<"微　冰"<<IR[2]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<"\t  "<<SL[3]<<" 30% 微　糖"<<SR[3]<<"\t 　　 "<<IL[3]<<"去　冰"<<IR[3]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<"\t\t  "<<SL[4]<<" 20% 二分糖"<<SR[4]<<"\t 　  "<<IL[4]<<"完全去冰"<<IR[4]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<"\t  "<<SL[5]<<" 10% 一分糖"<<SR[5]<<"\t 　　 "<<IL[5]<<"常　溫"<<IR[5]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<"\t  "<<SL[6]<<"  0% 無　糖"<<SR[6]<<"\t 　　　 "<<IL[6]<<"溫"<<IR[6]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<"\t\t\t 　　　 "<<IL[7]<<"熱"<<IR[7]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<" "<<BL[1]<<"加白玉 10元"<<BR[1]<<"/"<<BL[2]<<"加墨玉 15元"<<BR[2]<<"/"<<BL[0]<<"不加"<<BR[0]<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<DL[0]<<"YES"<<DR[0]<<" | "<<DL[1]<<"NO"<<DR[1]<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點："<<endl;
	OrderedDrink(cups, s_ordered);
}
int DoneUI(int select, int drink, int bubble, int sugar, int ice, int cups, string s_ordered[100]){
	char x, x1;
	do{
		DoneScreen(select, drink, bubble, sugar, ice, cups, s_ordered);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 77 || x1 == 75)
				select = (select + 1) % 2;
		}
	}while(x != 13);
	return select;
}
void OrderedDrink(int cups, string s_ordered[100]){
	for(int i = 0; i < cups; i++){
		//白玉歐雷 M 無糖 正常冰 大卡 $25
		cout<<"   "<<s_ordered[i]<<endl;
	}
	cout<<"-->共: "<<total<<"元"<<" ("<<cups<<" 杯)"<<endl;
}

void PayScreen(int select, int done, int cups, string s_ordered[100]){
	system("cls");
	system("Color 1F");
	for(int i = 0; i < 6; i++){
		cout<<KebukeMenuIce[i]<<endl;
	}
	char L[34], R[34];
	for(int i = 0; i < 34; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	char BL[3] = {' ', ' ', ' '}, BR[3] = {' ', ' ', ' '};
	char SL[7], SR[7];
	for(int i = 0; i < 7; i++){
		SL[i] = ' ';
		SR[i] = ' ';
	}
	char IL[8], IR[8];
	for(int i = 0; i < 8; i++){
		IL[i] = ' ';
		IR[i] = ' ';
	}
	char DL[2] = {' ', ' '}, DR[2] = {' ', ' '};
	char CL[cups + 1], CR[cups + 1];
	for(int i = 0; i <= cups; i++){
		CL[i] = ' '; CR[i] = ' ';
	}
	DL[done] = '['; DR[done] = ']';
	CL[select] = '['; CR[select] = ']';
	cout<<" 熟成紅茶\t\t"<<L[0]<<"M 25"<<R[0]<<"/"<<L[1]<<"L 30"<<R[1]<<" 春梅冰茶\t\t"<<L[18]<<"M 35"<<R[18]<<"/"<<L[19]<<"L 45"<<R[19]<<"\t  "<<SL[0]<<"100% 正常糖"<<SR[0]<<"\t 　　 "<<IL[0]<<"正常冰"<<IR[0]<<endl;
	cout<<" 麗春紅茶\t\t"<<L[2]<<"M 25"<<R[2]<<"/"<<L[3]<<"L 30"<<R[3]<<" 冷露歐蕾\t\t"<<L[20]<<"M 40"<<R[20]<<"/"<<L[21]<<"L 50"<<R[21]<<"\t  "<<SL[1]<<" 70% 少　糖"<<SR[1]<<"\t 　　 "<<IL[1]<<"少　冰"<<IR[1]<<endl;
	cout<<" 太妃紅茶\t\t"<<L[4]<<"M 30"<<R[4]<<"/"<<L[5]<<"L 35"<<R[5]<<" 熟成歐蕾\t\t"<<L[22]<<"M 40"<<R[22]<<"/"<<L[23]<<"L 50"<<R[23]<<"\t  "<<SL[2]<<" 50% 半　糖"<<SR[2]<<"\t 　　 "<<IL[2]<<"微　冰"<<IR[2]<<endl;
	cout<<" 胭脂紅茶\t\t"<<L[6]<<"M 35"<<R[6]<<"/"<<L[7]<<"L 40"<<R[7]<<" 白玉歐蕾\t\t"<<L[24]<<"M 50"<<R[24]<<"/"<<L[25]<<"L 60"<<R[25]<<"\t  "<<SL[3]<<" 30% 微　糖"<<SR[3]<<"\t 　　 "<<IL[3]<<"去　冰"<<IR[3]<<endl;
	cout<<" 雪藏紅茶\t\t"<<L[8]<<"M 45"<<R[8]<<"/"<<L[9]<<"L 55"<<R[9]<<" 熟成檸果\t\t"<<L[26]<<"M 50"<<R[26]<<"\t\t  "<<SL[4]<<" 20% 二分糖"<<SR[4]<<"\t 　  "<<IL[4]<<"完全去冰"<<IR[4]<<endl;
	cout<<" 熟成冷露\t\t"<<L[10]<<"M 25"<<R[10]<<"/"<<L[11]<<"L 30"<<R[11]<<" 胭脂多多\t\t"<<L[27]<<"M 40"<<R[27]<<"/"<<L[28]<<"L 50"<<R[28]<<"\t  "<<SL[5]<<" 10% 一分糖"<<SR[5]<<"\t 　　 "<<IL[5]<<"常　溫"<<IR[5]<<endl;
	cout<<" 雪花冷露\t\t"<<L[12]<<"M 25"<<R[12]<<"/"<<L[13]<<"L 30"<<R[13]<<" 雪藏末茶\t\t"<<L[29]<<"M 50"<<R[29]<<"/"<<L[30]<<"L 60"<<R[30]<<"\t  "<<SL[6]<<"  0% 無　糖"<<SR[6]<<"\t 　　　 "<<IL[6]<<"溫"<<IR[6]<<endl;
	cout<<" 春芽冷露\t\t"<<L[14]<<"M 25"<<R[14]<<"/"<<L[15]<<"L 30"<<R[15]<<" 黃玉歐蕾\t\t"<<L[31]<<"M 60"<<R[31]<<"/"<<L[32]<<"L 70"<<R[32]<<"\t\t\t 　　　 "<<IL[7]<<"熱"<<IR[7]<<endl;
	cout<<" 春芽綠茶\t\t"<<L[16]<<"M 25"<<R[16]<<"/"<<L[17]<<"L 30"<<R[17]<<" 墨玉歐特\t\t"<<L[33]<<"M 60"<<R[33]<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<" "<<BL[1]<<"加白玉 10元"<<BR[1]<<"/"<<BL[2]<<"加墨玉 15元"<<BR[2]<<"/"<<BL[0]<<"不加"<<BR[0]<<endl;
	cout<<"\n　_________"<<endl;
	cout<<" |         |"<<endl;
	cout<<" | 點好了? |  "<<DL[0]<<"YES"<<DR[0]<<" | "<<DL[1]<<"NO"<<DR[1]<<endl;
	cout<<" |_________|"<<endl;
	//cout<<"______________________________________________________________"<<endl;
	cout<<"已點： (如需取消，請在下方選擇品項後按下enter鍵，或按確認確認付款)"<<endl;
	for(int i = 0; i < cups; i++){
		cout<<CL[i]<<"x"<<CR[i]<<s_ordered[i]<<endl;
	}
	cout<<"-->共: "<<total<<"元"<<" ("<<cups<<" 杯)"<<endl;
	cout<<CL[cups]<<"確認付款"<<CR[cups]<<endl;
}
void PayUI(int select, int done, int cups, string s_ordered[100], int user_id, userlist users){
	char x, x1;
	do{
		PayScreen(select, done, cups, s_ordered);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + cups) % (cups + 1);
			if(x1 == 80)
				select = (select + 1) % (cups + 1);
		}
	}while(x != 13);
	if(select != cups){
		cups = DeletingDrink(select, cups, s_ordered);
		PayUI(select, 0, cups, s_ordered, user_id, users);
	}
	else{
		if(users.member[user_id].card_value >= total){//see if he still have enough money
			if(cups == 0){
				system("cls");
				cout<<"         [未點餐]"<<endl;
				cout<<"     將跳轉到Main Page..."<<endl;
				users.member[user_id].card_value -= total;
				sleep(3000);
			}
			else{
				cout<<"扣款中，請稍後。"<<endl;
				addCardValue(user_id, -total);
				users = LoadUsers();
				sleep(2000);
				system("cls");
				orderNum++;
				cout<<"　    　        　　　[扣款完成]"<<endl;
				cout<<"             以下是您的訂單，即將為您製作"<<endl;
				OrderPrint(cups, s_ordered, user_id, users);
				sleep(2000);
			}
		}
		else{
			cout<<"＜您的餘額不足，請多玩小遊戲贏取硬幣＞"<<endl;
			sleep(2000);
		}
	}

}
int DeletingDrink(int elem, int cups, string s_ordered[100]){
	int i, j, cups_tmp = cups, money;
	string goalS = s_ordered[elem], s_money = "";
	for(i = 0; i < cups_tmp; i++){
		if(s_ordered[i] == goalS){
			for(j = 0; j < s_ordered[i].length(); j++){
				if(s_ordered[i][j] == '$'){
					s_money += s_ordered[i][j+1];
					s_money += s_ordered[i][j+2];
					stringstream geek(s_money);
					geek>>money;
					total -= money;
				}
			}
			for(j = i; j < (cups - 1); j++)
				s_ordered[j] = s_ordered[j + 1];
			i--;
			cups_tmp--;
		}
	}
	cups--;
	return cups;
}
void addOrder(int user_id, userlist users, string TimeNow, int cups, string s_ordered[100], int total){
	ifstream myfile;
	ofstream temp;
	string line;
	myfile.open("orderlist.txt");
	temp.open("temp.txt");
	int cnt = 0;
	while(getline(myfile, line)){
		if(cnt == 0){ // 第一 line
			stringstream geek(line);
			int x;
			geek>>x;
			if(x == 0)//如果是第一筆訂單
				temp<<1<<endl;
			else
				temp<<orderNum<<endl;
		}
		else{
			temp<<line<<endl;
		}
		cnt++;
	}
	temp<<"#";
	temp<<orderNum<<endl;
	temp<<0<<endl; //0是pending 1 in process　2 done
	temp<<users.member[user_id].name<<endl;
	temp<<TimeNow;
	for(int i = 0; i < cups; i++){
		temp<<"-"<<s_ordered[i]<<endl;
	}
	temp<<"     共： "<<total<<"元"<<endl;
	temp<<"@"<<endl;
	myfile.close();
	temp.close();
	remove("orderlist.txt");
	rename("temp.txt", "orderlist.txt");
}

void CheckOrderStatus(int user_id, userlist users){
	system("cls");
	ifstream myfile;
	string line, st, sname, things[100], linetmp = "";
	char ch;
	for(int i = 0; i < 100; i++)
		things[i] = "";
	char c_name[13];

	myfile.open("orderlist.txt");
	int flag = 0, num, state, k, yes, cnt2, inorder = 0; // flag 1->訂單編號　2->狀態 3->name 4-> time
	while(getline(myfile, line)){
		ch = myfile.peek();
		if(line[0] == '#'){
			linetmp = "";
			for(unsigned int i = 1; i < line.length(); i++){
				linetmp += line[i];
			}
			stringstream geek(linetmp);
			geek>>num;
			flag = 2;
			yes = 1;
			k = 4;
			for(int i = 0; i < 100; i++)
				things[i] = "";
		}
		else if(flag == 2){
			stringstream geek(line);
			geek>>state;
			flag++;
		}
		else if(flag == 3){
			sname = line;
			strcpy(c_name, sname.c_str());
			flag++;
		}
		else if(flag == 4){
			st = line;
			//cout<<"time: "<<st<<endl;
			if(strcmp(c_name, users.member[user_id].name) == 0 && state != 2){
				yes = 1;
				//cout<<"strcmp == 0"<<endl;
				things[0] = to_string(num);
				if(state == 0)
					things[1] = "待製作";
				else if(state == 1)
					things[1] = "製作中";
				things[2] = sname;
				things[3] = st;
			}
			else if(strcmp(c_name, users.member[user_id].name) == 0 && state == 2){
				things[0] = to_string(num);
				things[1] = "已完成";
				things[2] = sname;
				things[3] = st;

			}
			else{
				yes = 0;
			}
			flag = 0;
		}
		if(yes == 1 && (line[0] == '-' || line[0] == ' ')){
			things[k] = line;
			k++;
		}
		if(yes == 1 && ch == '@'){
			//cout<<"YEs == 1 && @"<<endl;
			cnt2 = 0;
			inorder++;
			string space = "", space_tmp;
			for(int i = 0; i < 13; i++){
				if(users.member[user_id].name[i] != '\0'){
					cnt2++;
				}
			}
			for(int i = 0; i < (47-cnt2); i++)
				space += " ";
			if(num >= 10 && num < 100)
				space_tmp = " ";
			else if(num < 10)
				space_tmp = "  ";
			cout<<"\n\n 　　訂購時間：　"<<st<<endl;
			cout<<" 　　狀態：　"<<things[1]<<endl;
			cout<<"  _____________________________________________________________"<<endl; //60 chars
			cout<<" |                    可不可熟成紅茶　林口店　　　　　　       |"<<endl;
			cout<<" |   訂購人：　"<<users.member[user_id].name<<space<<" |"<<endl;
			cout<<" |   訂單編號："<<space_tmp<<num<<"                                             |"<<endl;
			cout<<" |_____________________________________________________________|"<<endl;
			for(int i = 4; i < k; i++){
				if(i == k - 1)
					cout<<things[i]<<endl;
				else
					cout<<"   -"<<things[i]<<endl;
			}			
		}
	}
	myfile.close();
	if(inorder == 0){
		cout<<"\n\n\t 您沒有正在製作或待處理的訂單"<<endl;
		cout<<"\t 按任意鍵回到主頁"<<endl;
	}
	else
		cout<<"      \t\t 按任意鍵回到主頁"<<endl;
	char x = getch();

}

void OrderPrint(int cups, string s_ordered[100], int user_id, userlist users){
	int cnt = 0;
	string space = "", space_tmp;
	for(int i = 0; i < 13; i++){
		if(users.member[user_id].name[i] != '\0'){
			cnt++;
		}
	}
	for(int i = 0; i < (47-cnt); i++)
		space += " ";
	time_t curtime;
	time(&curtime);
	string TimeNow = ctime(&curtime);
	if(orderNum >= 10 && orderNum < 100)
		space_tmp = " ";
	else if(orderNum < 10)
		space_tmp = "  ";
	cout<<"\n\n 　　訂購時間：　"<<ctime(&curtime);
	cout<<"  _____________________________________________________________"<<endl; //60 chars
	cout<<" |                    可不可熟成紅茶　林口店　　　　　　       |"<<endl;
	cout<<" |   訂購人：　"<<users.member[user_id].name<<space<<" |"<<endl;
	cout<<" |   訂單編號："<<space_tmp<<orderNum<<"                                             |"<<endl;
	cout<<" |_____________________________________________________________|"<<endl;
	for(int i = 0; i < cups; i++){
		cout<<"   --"<<s_ordered[i]<<endl;
	}
	cout<<"　　　共：　"<<total<<"元"<<endl;
	cout<<"     (卡片餘額： $"<<users.member[user_id].card_value<<")"<<endl;
	char x = getch();
	addOrder(user_id, users, TimeNow, cups, s_ordered, total);
}

void ChatRoom(char name[]){
	ifstream fin;
	ofstream fout;
	string line;
	do{
		system("cls");
		system("Color AF");
	    fin.open("messages.txt");
	    cout<<"    ^    ^    ^    ^    ^    ^    ^    ^  "<<endl;
	    cout<<"   /C\\  /h\\  /a\\  /t\\  /r\\  /o\\  /o\\  /m\\ "<<endl;
	    cout<<"  <___><___><___><___><___><___><___><___>"<<endl;
	    cout<<" (Hint: Type in \"EXIT\" to exit the chat room)\n"<<endl;
	    while(!fin.eof()){
	    	getline(fin, line);
	    	int n = line.length();
	    	if(n >= 50){
	    		cout<<"  ";
	    		for(int i = 0; i < 50; i++)
	    			cout<<line[i];
	    		cout<<endl<<"  ";
	    		for(int i = 50; i < n; i++)
	    			cout<<line[i];
	    		cout<<endl;
	    	}
	    	else
	    		cout<<"  "<<line<<endl;
	    		
	    }
	    fin.close();
		cout<<"-------------------------------"<<endl;
		cout<<"  "<<name<<": ";
		getline(cin, line);
		if(line.compare("EXIT") == 0)
			break;
		if(line.length() > 0){
			//save what you said into my file msg (append)
			fout.open("messages.txt", std::ofstream::app);
			fout<<name<<": "<<line<<endl;
			fout.close();
		}
	}while(true);
}
void ChatRoomChooseScreen(int select){
	int i;
	for(i = 0; i < 5; i++)
		cout<<"  "<<s_chat[i]<<endl;
	char L[3] = {' ', ' ', ' '}, R[3] = {' ', ' ', ' '};
	L[select] = '['; R[select] = ']';
	cout<<"\t\t\t\t      "<<L[1]<<"Group Chat"<<R[1]<<endl;
	cout<<"\t\t\t\t     "<<L[2]<<"Private Chat"<<R[2]<<endl;
	cout<<"\t\t\t\t         "<<L[0]<<"BACK"<<R[0]<<endl;
}
int ChatRoomChooseUI(int select){
	char x, x1;
	do{
		system("cls");
		system("Color F3");
		ChatRoomChooseScreen(select);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 2) % 3;
			if(x1 == 80)
				select = (select + 1) % 3;
			if(x1 == 77)
				return select;
		}
	}while(x != 13);
	return select;
}
void ChooseFriendScreen(int select, userlist users, int user_id){
	int i, n = users.total_user_num;
	char L[n + 1], R[n + 1];
	for(i = 0; i <= n; i++){
		L[i] = ' ';
		R[i] = ' ';
	}
	L[select] = '['; R[select] = ']';
	for(i = 1; i <= n; i++){
		if(i != user_id)
			cout<<"  "<<L[i]<<users.member[i].name<<R[i]<<endl;
	}
}
int ChooseFriendUI(int select, userlist users, int user_id){
	char x, x1;
	int n, check;
	do{
		system("cls");
		ChooseFriendScreen(select, users, user_id);
		n = users.total_user_num;
		x = getch();
		if(user_id == n)
			check = 0;
		if(x == -32){
			x1 = getch();
			if(x1 == 72){
				select = (select + (n - 1)) % n;
				//cout<<"select = "<<select<<endl;
				//sleep(500);
				if(select == user_id && select == 1)
					select = n;
				if(select == check && select == 0)
					select = n - 1;
			}
			if(x1 == 80){
				select = (select + 1) % n;
				//cout<<"select = "<<select<<endl;
				//sleep(500);
				if(select == user_id && select == 1)
					select = 2;
				if(select == check && select == 0)
					select = 1;
			}
			if(x1 == 77)
				return select;
		}
	}while(x != 13);
	return select;
}
void PrivateChatRoom(int friend_id, int user_id, userlist users){
	ifstream fin;
	ofstream fout;
	string line;
	string fname = "";
	if(friend_id > user_id){
		fname += to_string(user_id);
		fname += "&";
		fname += to_string(friend_id);
		fname += ".txt";
	}
	else{
		fname += to_string(friend_id);
		fname += "&";
		fname += to_string(user_id);
		fname += ".txt";
	}
	//cout<<fname<<endl;
	do{
		system("cls");
		system("Color AF");
		//cout<<fname<<"@"<<endl;
		fin.open(fname);
		//sleep(2000);
		cout<<" ____ _  _ ____ ___ ____ ____ ____ _  _   _  _ _ ___ _  _  "<<endl;
		cout<<" |___ |--| |--|  |  |--< [__] [__] |\\/|   |/\\| |  |  |--|"<<endl;
		cout<<" ---> "<<users.member[friend_id].name<<endl;
		cout<<"   (Hint: Type in \"EXIT\" to exit the chat room)\n"<<endl;
		while(!fin.eof()){
			getline(fin, line);
			int n = line.length();
			if(line == "")
				break;
			if(n >= 50){
				cout<<"  ";
				for(int i = 0; i < 50; i++)
					cout<<line[i];
				cout<<endl<<"  ";
				for(int i = 50; i < n; i++)
					cout<<line[i];
				cout<<endl;
			}
			else
				cout<<"  "<<line<<endl;
		}
		fin.close();
		cout<<"----------------------------------------------------"<<endl;
		cout<<"  "<<users.member[user_id].name<<": ";
		getline(cin, line);
		if(line.compare("EXIT") == 0)
			break;
		if(line.length() > 0){
			//save what you said into my file msg (append)
			fout.open(fname, std::ofstream::app);
			fout<<users.member[user_id].name<<": "<<line<<endl;
			fout.close();
		}
	}while(true);
}

void LoadTotal(){
	ifstream myfile;
	string line;
	int cnt = 1;
	myfile.open("orderlist.txt");
	while(getline(myfile, line)){
		if(cnt == 2){
			stringstream geek(line);
			geek>>totalamount;
			break;
		}
		cnt++;
	}
	myfile.close();
}
void ShopWelcomeScreen(int select){
	LoadTotal();
	//print shop welcome graph
	char L[4] = {' ', ' ', ' ', ' '}, R[4] = {' ', ' ', ' ', ' '};
	cout<<"\n\n\n"<<endl;
	for(int i = 0; i < 7; i++)
		cout<<kebukeshopgraph[i]<<endl;
	cout<<"                                  現在累積營收: "<<totalamount<<endl;
	L[select] = '['; R[select] = ']';
	cout<<" |_______________________________________________________________________________________|\n"<<endl;
	cout<<"\t\t\t\t        "<<L[1]<<"查詢訂單"<<R[1]<<endl;
	cout<<"\t\t\t\t        "<<L[2]<<"顧客加值"<<R[2]<<endl;
	cout<<"\t\t\t\t        "<<L[3]<<"庫存查詢"<<R[3]<<endl;
	cout<<"\t\t\t\t          "<<L[0]<<"EXIT"<<R[0]<<endl;
}
int ShopWelcomeUI(int select){
	char x, x1;
	do{
		system("cls");
		system("Color F3");
		ShopWelcomeScreen(select);
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 72)
				select = (select + 3) % 4;
			if(x1 == 80)
				select = (select + 1) % 4;
			if(x1 == 77)
				return select;
		}
	}while(x != 13);
	return select;
}
void OrdertoString(string s_shopOrders[100]){
	ifstream myfile;
	myfile.open("orderlist.txt");
	string sstate, sname, st, things[100], line, linetmp, s_amount = "";
	string space = "", space_tmp;
	char c;
	int flag = 0, cnt, num, yes = 0, k, aflag = 0;
	while(getline(myfile, line)){
		system("cls");
		system("Color E5");
		c = myfile.peek();
		if(line[0] == '#' && c == '0'){
			linetmp = "";
			for(unsigned int i = 1; i < line.length(); i++){
				linetmp += line[i];
			}
			stringstream geek(linetmp);
			geek>>num;
			flag = 2;
			yes = 1;
			k = 0;
			mealNum = num;
		}
		else if(flag == 2){
			sstate = "待製作";
			flag++;
		}
		else if(flag == 3){
			sname = line;
			flag++;
		}
		else if(flag == 4){
			st = line;
			flag = 0;
		}
		if(yes == 1 && (line[0] == '-' || line[0] == ' ')){
			things[k] = line;
			if(line[0] == ' '){
				for(int i = 0; i < line.length(); i++){
					if(aflag = 2 && line[i] >= '0' && line[i] <= '9')
						s_amount += line[i];
					if(line[i] == ':')
						aflag = 1;
					if(aflag == 1 && line[i] == ' ')
						aflag = 2;
				}
				aflag = 0;
			}
			k++;
		}

		if(c == '@' && yes == 1){
			stringstream geek(s_amount);
			geek>>amount;
			cnt = 0;
			space = "";
			for(int i = 0; i < (47 - sname.length()); i++){
				space += " ";
			}
			if(num >= 10 && num < 100)
				space_tmp = " ";
			else if(num < 10)
				space_tmp = "  ";
			cout<<"\n\n 　　訂購時間：　"<<st<<endl;
			cout<<" 　　狀態：　待製作"<<endl;
			cout<<"  _____________________________________________________________"<<endl; //60 chars
			cout<<" |                    可不可熟成紅茶　林口店　　　　　　       |"<<endl;
			cout<<" |   訂購人：　"<<sname<<space<<" |"<<endl;
			cout<<" |   訂單編號："<<space_tmp<<num<<"                                             |"<<endl;
			cout<<" |_____________________________________________________________|"<<endl;
			s_shopOrders[4] = " |   訂購人：　"; s_shopOrders[4] += sname; s_shopOrders[4] += space; s_shopOrders[4] += " |";
			s_shopOrders[5] = " |   訂單編號："; s_shopOrders[5] += space_tmp; s_shopOrders[5] += to_string(num); s_shopOrders[5] += "                                             |";
			for(int i = 0; i < k; i++){
				if(i == k-1){
					cout<<things[i]<<endl;
					s_shopOrders[i + 7] = things[i];
					s_shopOrders[i + 8] = '\0';
				}
				else{
					cout<<"   -"<<things[i]<<endl;
					s_shopOrders[i+7] = "   -";
					s_shopOrders[i+7] += things[i];
				}
			}
			break;
		}
		s_shopOrders[0] = "\n\n 　　訂購時間：　"; s_shopOrders[0] += st;
		s_shopOrders[1] = " 　　狀態：　待製作";
		s_shopOrders[2] = "  _____________________________________________________________";
		s_shopOrders[3] = " |                    可不可熟成紅茶　林口店　　　　　　       |";
		s_shopOrders[4] = " |   訂購人：　"; s_shopOrders[4] += sname; s_shopOrders[4] += space; s_shopOrders[4] += " |";
		s_shopOrders[5] = " |   訂單編號："; s_shopOrders[5] += space_tmp; s_shopOrders[5] += to_string(num); s_shopOrders[5] += "                                             |";
		s_shopOrders[6] = " |_____________________________________________________________|";
	}
	myfile.close();
}
int ShopNextOrderScreen(int select, string s_shopOrders[100]){
	system("cls");
	system("color E5");
	int cnt = 0;
	for(int i = 0; i < 100; i++){
		if(s_shopOrders[i] != "\0"){
			cout<<s_shopOrders[i]<<endl;
			cnt++;
		}
	}
	if(cnt != 0){
		char L[2] = {' ', ' '}, R[2] = {' ', ' '};
		L[select] = '['; R[select] = ']';
		cout<<"\n  --> 開始製作? "<<L[1]<<"YES"<<R[1]<<"|"<<L[0]<<"NO"<<R[0]<<endl;
		return 1;
	}
	else{
		return 0;
	}
	
}
int ShopNextOrderUI(int select, string s_shopOrders[100]){
	char x, x1;
	int empty = 0;
	do{
		empty = ShopNextOrderScreen(select, s_shopOrders);
		if(empty == 0){
			select = 0;
			break;
		}
		x = getch();
		if(x == -32){
			x1 = getch();
			if(x1 == 75 || x1 == 77)
				select = (select + 1) % 2;
		}
	}while(x != 13);
	return select;
}
void ShopInProcessScreen(string s_shopOrders[100]){
	system("cls");
	system("Color E5");
	s_shopOrders[1] = " 　　狀態：　製作中";
	for(int i = 0; i < 100; i++){
		if(s_shopOrders[i] != "\0")
			cout<<s_shopOrders[i]<<endl;
	}
	cout<<"\n\t\t       ---製作中----\n"<<endl;
	cout<<"\t ->按Pg Dn完成餐點或按Backspace回到Main Page"<<endl;
}
int ShopInProcessUI(string s_shopOrders[100]){
	char x, x1;
	do{
		ShopInProcessScreen(s_shopOrders);
		x = getch();
		if(x == 0){
			x1 = getch();
			if(x1 == 81)//pagedown
				return 1;
		}
		if(x == 8) //back
			return 2;
	}while(true);
}
void ShopCompleteOrder(int mealno){
	ifstream myfile;
	ofstream temp;
	char c;
	int flag = 0, cnt = 1, tot;
	string line, linetmp;
	linetmp = "#"; linetmp += to_string(mealno);
	myfile.open("orderlist.txt");
	temp.open("temp.txt");
	while(getline(myfile, line)){
		if(flag == 1){
			temp<<2<<endl;
			flag = 0;
		}
		else if(cnt == 2){
			stringstream geek(line);
			geek>>tot;
			tot += amount;
			temp<<tot<<endl;
		}
		else
			temp<<line<<endl;
		if(line == linetmp)
			flag = 1;
		cnt++;
	}
	myfile.close();
	temp.close();
	remove("orderlist.txt");
	rename("temp.txt", "orderlist.txt");
	ShopCompletePrint();
}
void ShopCompletePrint(){
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	sleep(500);
	cout<<"　　　　　　　　　 送出中."<<endl;
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中 ."<<endl;
	sleep(200);
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中  ."<<endl;
	sleep(200);
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中   ."<<endl;
	sleep(200);
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中    ."<<endl;
	sleep(200);
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中     ."<<endl;
	sleep(200);
	system("cls");
	cout<<"　　　　　　　　　餐點完成"<<endl;
	cout<<"　　　　　　　　 　送出中      ."<<endl;
	sleep(200);
	system("cls");
	cout<<"              將顯示下份餐點"<<endl;
	sleep(1000);
}
void ShopAddValueScreen(int select, userlist users){
	system("cls");
	system("Color F0");
	int tot = users.total_user_num, i;
	for(i = 1; i <= tot; i++){
		cout<<"\n UserId: "<<i<<endl;
		cout<<"  Name: "<<users.member[i].name<<endl;
		cout<<"  Username: "<<users.member[i].username<<endl;
		cout<<"  Card Value: $"<<users.member[i].card_value<<endl;
	}
	cout<<"\n欲跳轉回Main Page，請在下方輸入BACK。 加值金額一次不得超過3000"<<endl;
	cout<<"--請輸入欲加值的user's UserID: ";
}
void ShopAddValueUI(int select, userlist users){
	int tot = users.total_user_num;
	string line;
	int id, flag = 0, money;
	do{
		ShopAddValueScreen(select, users);
		if(flag == 0){
			cin>>line;
			if(line == "BACK")
				break;
			else{
				stringstream geek(line);
				geek>>id;
				if(id >= 1 && id <= tot)
					flag = 1;
				else{
					cout<<"<此用戶不存在，請重新輸入>"<<endl;
					sleep(2000);
				}
			}
		}
		else{
			cout<<id<<endl;
			cout<<"--請輸入欲加值的金額: ";
			cin>>line;
			stringstream geek(line);
			geek>>money;
			if(money > 0 && money <= 3000){
				addCardValue(id, money);
				system("cls");
				cout<<"\n\n\t\t\t加值中. "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值中 . "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值中  . "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值中   . "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值中    . "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值中     . "<<endl;
				sleep(100);
				system("cls");
				cout<<"\n\n\t\t\t加值成功!      "<<endl;
				sleep(1500);
				users = LoadUsers();
				flag = 0;
			}
		}
	}while(line != "BACK");
}
stocklist ShopLoadStock(){
	stocklist stock;
	string line, snum;
	int i, num, tmp, flag, flag1;
	ifstream myfile;
	myfile.open("stock.txt");
	while(getline(myfile, line)){
		snum = "";
		if(flag == 1){
			stringstream geek(line);
			geek>>tmp;
			stock.drink[num] = tmp;
			flag = 0;
		}

		if(flag1 == 1){
			stringstream geek(line);
			geek>>tmp;
			stock.ice = tmp;
			flag1 = 0;
		}
		else if(flag1 == 2){
			stringstream geek(line);
			geek>>tmp;
			stock.sugar = tmp;
			flag1 = 0;
		}
		else if(flag1 == 3){
			stringstream geek(line);
			geek>>tmp;
			stock.Mcup = tmp;
			flag1 = 0;
		}
		else if(flag1 == 4){
			stringstream geek(line);
			geek>>tmp;
			stock.Lcup = tmp;
			flag1 = 0;
		}

		if(line[0] == 'd'){
			for(i = 1; i <line.length(); i++)
				snum += line[i];
			stringstream geek(snum);
			geek>>num;
			flag = 1;
		}

		if(line == "Ice")
			flag1 = 1;
		if(line == "Sugar")
			flag1 = 2;
		if(line == "MCup")
			flag1 = 3;
		if(line == "LCup")
			flag1 = 4;
	}
	myfile.close();
	return stock;
}

void ShopStockScreen(stocklist stock){
	int flag = 0;
	do{
		system("cls");
		cout<<"   <可不可熟成紅茶林口店 庫存>";
		cout<<"\n\t 1 熟成紅茶: "<<stock.drink[1]<<"ml"<<endl;
		cout<<"\t 2 麗春紅茶: "<<stock.drink[2]<<"ml"<<endl;
		cout<<"\t 3 太妃紅茶: "<<stock.drink[3]<<"ml"<<endl;
		cout<<"\t 4 胭脂紅茶: "<<stock.drink[4]<<"ml"<<endl;
		cout<<"\t 5 雪藏紅茶: "<<stock.drink[5]<<"ml"<<endl;
		cout<<"\t 6 熟成冷露: "<<stock.drink[6]<<"ml"<<endl;
		cout<<"\t 7 雪花冷露: "<<stock.drink[7]<<"ml"<<endl;
		cout<<"\t 8 春芽冷露: "<<stock.drink[8]<<"ml"<<endl;
		cout<<"\t 9 春芽綠茶: "<<stock.drink[9]<<"ml"<<endl;
		cout<<"\t10 春梅冰茶: "<<stock.drink[10]<<"ml"<<endl;
		cout<<"\t11 冷露歐蕾: "<<stock.drink[11]<<"ml"<<endl;
		cout<<"\t12 熟成歐蕾: "<<stock.drink[12]<<"ml"<<endl;
		cout<<"\t13 白玉歐蕾: "<<stock.drink[13]<<"ml"<<endl;
		cout<<"\t14 熟成檸果: "<<stock.drink[14]<<"ml"<<endl;
		cout<<"\t15 胭脂多多: "<<stock.drink[15]<<"ml"<<endl;
		cout<<"\t16 雪藏末茶: "<<stock.drink[16]<<"ml"<<endl;
		cout<<"\t17 黃玉歐蕾: "<<stock.drink[17]<<"ml"<<endl;
		cout<<"\t18 墨玉歐特: "<<stock.drink[18]<<"ml"<<endl;
		cout<<"  --------------------------------------------"<<endl;
		float icekg = stock.ice / 1000;
		float sugarkg = stock.sugar / 1000;
		cout<<"\t19 冰塊: "; cout<<setprecision(2)<<icekg; cout<<"kg"<<endl;
		cout<<"\t20 砂糖: "; cout<<setprecision(2)<<sugarkg; cout<<"kg"<<endl;
		cout<<"\t21 中杯杯子: "<<stock.Mcup<<endl;
		cout<<"\t22 大杯杯子: "<<stock.Lcup<<endl;
		cout<<"\n\t -需要補貨嗎?(y/n): ";
		char x;
		string snum = "";
		int num;
		if(flag == 0){
			do{
			x = getch();
			if(x == 'y' || x == 'n')
				break;
			}while(true);
			cout<<x<<endl;
		}
		else{
			x = 'y';
			cout<<x<<endl;
		}
		if(x == 'y'){
			flag = 1;
			cout<<"\t 請輸入欲補貨的商品(1~22): ";
			do{
				x = getch();
				if(x >= '0' && x <= '9'){
					cout<<x;
					snum += x;
				}
			}while(x != 13);

			stringstream geek(snum);
			geek>>num;
			if(num >= 1 && num <=18){
				cout<<"\n\t 請輸入欲補貨的容量(ml): ";
			}
			else if(num == 19 || num == 20){
				cout<<"\n\t 請輸入欲補貨的重量(克): ";
			}
			else if(num == 21 || num == 22){
				cout<<"\n\t 請輸入欲補貨的數量(杯): ";
			}
			else{
				cout<<"請輸入正確數字！"<<endl;
			}
		}	
		else 
			flag = 0;
	}while(flag != 0);
}