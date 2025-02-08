#include<bits/stdc++.h>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include "snake.cpp"
#include "food.cpp"
using namespace std;

#define LENGTH 30
#define WIDTH 30

snake s({LENGTH / 2, WIDTH / 2}, 1);
food f;

class Grid
{
private:
    int length, breadth;

public:
    COORD snake_pos = s.get_pos();
    Grid(int len, int bre,int p) : length(len), breadth(bre) {
        node* snake_body = s.get_body();
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < breadth; j++) {
                if (i == 0 || i == length - 1 || j == 0 || j == breadth - 1) {
                    cout << "🌳";
                }
                else if (i == f.get_pos().Y && j == f.get_pos().X) {
                    cout << f.v[f.K];
                }
                else {
                    bool is_snake = false;
                    node* temp = snake_body;
                    while (temp) {
                        if (i == temp->pos.Y && j == temp->pos.X) {
                            cout << s.colour[p-1];
                            is_snake = true;
                            break;
                        }
                        temp = temp->next;
                    }
                    if (!is_snake) {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }
};

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void tutorial()
{
    cout << R"(​🇹​​🇭​​🇪​ ​🇸​​🇳​​🇦​​🇰​​🇪​ ​🇬​​🇦​​🇲​​🇪​ ​🇮​​🇸​ ​🇦​ ​🇸​​🇮​​🇲​​🇵​​🇱​​🇪​ ​🇬​​🇦​​🇲​​🇪​ ​🇮​​🇳​ ​🇼​​🇭​​🇮​​🇨​​🇭​ ​🇾​​🇴​​🇺​ ​🇫​​🇪​​🇪​​🇩​ ​🇸​​🇳​​🇦​​🇰​​🇪​ ​🇹​​🇴​ ​🇲​​🇦​​🇰​​🇪​ ​🇮​​🇹​ ​🇬​​🇷​​🇴​​🇼​, ​🇸​​🇨​​🇴​​🇷​​🇮​​🇳​​🇬​ ​🇵​​🇴​​🇮​​🇳​​🇹​​🇸​.
    ​🇩​​🇮​​🇫​​🇫​​🇪​​🇷​​🇪​​🇳​​🇹​ ​🇫​​🇴​​🇴​​🇩​​🇸​ ​🇭​​🇦​​🇻​​🇪​ ​🇩​​🇮​​🇫​​🇫​​🇪​​🇷​​🇪​​🇳​​🇹​ ​🇸​​🇨​​🇴​​🇷​​🇪​​🇸​ ​🇹​​🇴​ ​🇹​​🇭​​🇪​​🇲​.
    ​🇵​​🇷​​🇪​​🇸​​🇸​ ( ​🇦​ / ​🇱​​🇪​​🇫​​🇹​ ​🇦​​🇷​​🇷​​🇴​​🇼​ ) ​🇹​​🇴​ ​🇲​​🇴​​🇻​​🇪​ ​🇱​​🇪​​🇫​​🇹​
    ​🇵​​🇷​​🇪​​🇸​​🇸​ ( ​🇸​ / ​🇩​​🇴​​🇼​​🇳​ ​🇦​​🇷​​🇷​​🇴​​🇼​ ) ​🇹​​🇴​ ​🇲​​🇴​​🇻​​🇪​ ​🇩​​🇴​​🇼​​🇳​
    ​🇵​​🇷​​🇪​​🇸​​🇸​ ( ​🇩​ / ​🇷​​🇮​​🇬​​🇭​​🇹​ ​🇦​​🇷​​🇷​​🇴​​🇼​ ) ​🇹​​🇴​ ​🇲​​🇴​​🇻​​🇪​ ​🇷​​🇮​​🇬​​🇭​​🇹​
    ​🇵​​🇷​​🇪​​🇸​​🇸​ ( ​🇼​ / ​🇺​​🇵​ ​🇦​​🇷​​🇷​​🇴​​🇼​ ) ​🇹​​🇴​ ​🇲​​🇴​​🇻​​🇪​ ​🇺​​🇵​

    ​🇫​​🇴​​🇴​​🇩​ ⦂
​    🇳​​🇴​​🇷​​🇲​​🇦​​🇱​ ⦂ ❝ 🐇 ❝ , ❝ 🪿  ❝ , ❝ 🥚 ❝  -- ​🇸​​🇨​​🇴​​🇷​​🇪​​🇸​ ⦂ 1️0
​    🇪​​🇽​​🇴​​🇹​​🇮​​🇨 ​⦂ ❝ 🦢 ❝ , ❝ 🦩 ❝           -- ​🇸​​🇨​​🇴​​🇷​​🇪​​🇸​ ⦂ 2️0️
​    🇺​​🇱​​🇹​​🇷​​🇦​ ​🇪​​🇽​​🇴​​🇹​​🇮​​🇨 ​⦂ ❝ 🦚 ❝              -- ​🇸​​🇨​​🇴​​🇷​​🇪​​🇸​ ⦂ 3️0️

    ​🇷​​🇺​​🇱​​🇪​​🇸 ​⦂

    1️⃣) ​🇪​​🇦​​🇹​ ​🇫​​🇴​​🇴​​🇩​ ​🇹​​🇴​ ​🇮​​🇳​​🇨​​🇷​​🇪​​🇦​​🇸​​🇪​ ​🇱​​🇪​​🇳​​🇬​​🇹​​🇭​ ​🇦​​🇳​​🇩​ ​🇸​​🇨​​🇴​​🇷​​🇪​
    2️⃣) ​🇮​​🇫​ ​🇸​​🇳​​🇦​​🇰​​🇪​❜​🇸​ ​🇭​​🇪​​🇦​​🇩​ ​🇭​​🇮​​🇹​​🇸​ ​🇦​​🇳​​🇾​ ​🇼​​🇦​​🇱​​🇱​ ​🇴​​🇷​ ​🇮​​🇹​​🇸​​🇪​​🇱​​🇫​ ​🇹​​🇭​​🇪​ ​🇬​​🇦​​🇲​​🇪​ ​🇪🇳​​🇩​​🇸​

    ​🇹​​🇴​ ​🇨​​🇴​​🇳​​🇹​​🇮​​🇳​​🇺​​🇪​ ​🇼​​🇮​​🇹​​🇭​ ​🇬​​🇦​​🇲​​🇪​ ​🇵​​🇷​​🇪​​🇸​​🇸​ ❜​🇨​❜ ⦂
    ​🇵​​🇷​​🇪​​🇸​​🇸​ ​🇪​​🇸​​🇨​ ​🇹​​🇴​ ​🇪​​🇽​​🇮​​🇹 ​⦂
)" << endl;
}

void gamestart(int a){
    int k = -1,score = 0;
    bool game_over = false;
    cout << "\033[1;93m"; 
    cout << R"(𝙋𝙍𝙀𝙎𝙎 𝙏 𝙏𝙊 𝙎𝙀𝙀 𝙏𝙐𝙏𝙊𝙍𝙄𝘼𝙇𝙎 𝘼𝙉𝘿 𝙍𝙐𝙇𝙀𝙎:)" << endl;
    cout << R"(𝙋𝙍𝙀𝙎𝙎 𝘾 𝙏𝙊 𝘾𝙊𝙉𝙏𝙄𝙉𝙐𝙀 𝙏𝙃𝙀 𝙂𝘼𝙈𝙀:)" << endl;
    cout << R"(𝙋𝙍𝙀𝙎𝙎 𝙀𝙎𝘾 𝙏𝙊 𝙀𝙓𝙄𝙏)" << endl;
     cout << "\033[0m\n";
    while(1)
    {
        if(kbhit())
        {
            char ch=getch();
            switch(ch)
            {
                case 't' : {tutorial();}
            }
            if(ch==27) exit(0);
            if(ch=='c') 
            {
                system("cls");
                break;
                }
        }
    }
    int p;
    cout << "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜" << endl; 
    cout << "⬜  CHOOSE A COLOUR FOR SNAKE ⬜" << endl;
    cout << "⬜      CLICK 1 FOR : 🟩      ⬜" << endl;
    cout << "⬜      CLICK 2 FOR : 🟦      ⬜" << endl;
    cout << "⬜      CLICK 3 FOR : 🟨      ⬜" << endl;
    cout << "⬜      CLICK 4 FOR : 🟧      ⬜" << endl;
    cout << "⬜      CLICK 5 FOR : 🟪      ⬜" << endl;
    cout << "⬜      CLICK 6 FOR : 🟥      ⬜" << endl;
    cout << "⬜                            ⬜" << endl;
    cout << "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜" << endl; 
    cout << "ENTER THE NUMBER:";
    cin >> p;
    system("cls");
    cout << "\033[1;36m"; 
     cout <<"\t\t\t\t"<< R"(
    █░░ █▀▀ ▀█▀    █▀   █▄▄ █▀▀ █▀▀ █ █▄░█
    █▄▄ ██▄ ░█░    ▄█   █▄█ ██▄ █▄█ █ █░▀█
    )";
    cout <<"\t"<< R"(
     𝐏𝐑𝐄𝐒𝐒 𝐄𝐍𝐓𝐄𝐑 𝐓𝐎 𝐁𝐄𝐆𝐈𝐍 𝐓𝐇𝐄 𝐆𝐀𝐌𝐄 )";
    cout << "\033[0m\n";
    while(1)
    {
        if(kbhit())
        {
             char ch = getch();
            if( ch==13 || ch==10 ) break;
        }
    }
    system("cls");
     while (!game_over) {
        srand(time(NULL));
        Sleep(a);
        if (k == -1) {
            system("cls");
            k = 0;
        }
        cout << endl << endl;
        Grid G(LENGTH, WIDTH, p);
        cout << endl;
        cout << "SCORE: " << score;
        while(_kbhit()) {
            switch (_getch()) {
                case 'w': s.change_dir('w'); break;
                case 'a': s.change_dir('a'); break;
                case 's': s.change_dir('s'); break;
                case 'd': s.change_dir('d'); break;
                case 72: s.change_dir('w'); break;
                case 80: s.change_dir('s'); break;
                case 75: s.change_dir('a'); break;
                case 77: s.change_dir('d'); break;
            }
        }
        s.move_snake();
        if (s.collided()) {
            game_over = true;
            s.set_pos(LENGTH/2,WIDTH/2);
            s.change_dir('\0');
        }
        if (s.eaten(f.get_pos())) {
            int value=f.scores[f.K];
            score += value;
            while(value>0)
            {
                s.grow();
                value-=10;
            }
            int j=f.gen_food();
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {2, 0});
    }
    system("cls");
    cout << "\033[1;91m"; 
    cout <<"\t\t\t"<< R"(
      █▀▀ ▄▀█ █▀▄▀█ █▀▀   █▀█ █░█ █▀▀ █▀█   
      █▄█ █▀█ █░▀░█ ██▄   █▄█ ▀▄▀ ██▄ █▀▄      
    )";
    cout<<endl;
    cout <<"\t"<< "𝐅𝐈𝐍𝐀𝐋 𝐒𝐂𝐎𝐑𝐄:" << score << endl;
    cout << "\033[0m\n";
    cout << "\033[1;93m"; 
    cout<<R"(𝐏𝐑𝐄𝐒𝐒 '𝐑' 𝐅𝐎𝐑 𝐑𝐄𝐒𝐓𝐀𝐑𝐓 )"<<endl;
    cout<<R"( 𝐏𝐑𝐄𝐒𝐒 '𝐄' 𝐅𝐎𝐑 𝐄𝐗𝐈𝐓:)";
    cout << "\033[0m\n";

    while(1)
    {
        if(kbhit())
        {
            char ch = getch();
            switch(ch)
            {
                case 'r' : 
                { system("cls"); gamestart(60);}
                case 'e' : 
                {exit(0);}
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    hideCursor();
    cout << "\033[1;95m"; 
     cout <<"\t\t\t\t"<< R"(
    █▀ █▄░█ ▄▀█ █▄▀ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀
    ▄█ █░▀█ █▀█ █░█ ██▄   █▄█ █▀█ █░▀░█ ██▄
    )";
    cout << "\033[0m\n";
    Sleep(2000);
    system("cls");
    gamestart(60);
    return 0;
}
