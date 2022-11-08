#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <string>
#include <iomanip>
using namespace std;

class Sea_Battle
{
private:

    string base[12][14];
    string opponent_base_hidden[12][14];
    string opponent_base_visible[12][14];
    string example_base[12][14];
    string copy_example_base[12][14];
    int air_defence_place[6];
    int purchased_air_defense=-1;
    int Coordinates_y;
    int Coordinates_x;
    int number_of_ships=0;
    int total_ship=0;
    string water="";
    string ship="";
    int input;
    int money_copy;
    int money=100;//max 150
    int amount_air_defence=0;
    int amount_bomber=0;
    int amount_fighter=0;
    int amount_torpedo=0;
    int amount_radar=0;
    int amount_nuc=0;
    string buy_sell=" Buy ";
    string half_air_defence="";
    string not_hit="";
    string use_cancel="Use Equipment";
    string ship_hit="><";
    bool show_column=true;
    bool show_row=true;
    bool turn=true;
    int opponent_review[100];
    int opponent_review_counter=0;
    bool hit_ship=false;
    bool show_opp_ground=false;
    bool inf_money=false;
    bool just_AI=false;
    int sleep_time=1000;
    bool opponent_rapide=false;
public:

    void set_main_data()
    {
        srand(time(0));
        ship+=char(219);
        ship+=char(219);
        water+=char(177);
        water+=char(177);
        not_hit+=char(176);
        not_hit+=char(176);
        money+=rand()%50;
        money_copy=money;
        half_air_defence+=char(204);
        reset_opp_visible_base();
        frame_maker(opponent_base_visible,true);
        layout_reset(opponent_base_hidden);
        make_random_layout(opponent_base_hidden,2);
        frame_maker(opponent_base_hidden,true);
        make_random_layout(example_base,3);
        frame_maker(example_base,true);
        make_random_layout(example_base,3);
        frame_maker(example_base,true);
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
                copy_example_base[i][j]=example_base[i][j];
        }
        for(int i=0;i<6;i++)
            air_defence_place[i]=0;
    }
    void reset_opp_visible_base()
    {
        int counter=0;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
            {
                opponent_base_visible[i][j]="";
                opponent_base_visible[i][j]+=char(177);
                opponent_base_visible[i][j]+=char(177);
                counter++;
                if(counter%2==0)
                {
                    opponent_base_visible[i][j]="";
                    opponent_base_visible[i][j]+=char(178);
                    opponent_base_visible[i][j]+=char(178);
                }
            }
            counter++;
        }
    }
    void sea_battle_intro(bool ingame)
    {
        if(ingame==true)
        {
            cout<<"\n\t\t\t\t       --------------\n\t\t\t\t       ";
            cout<<": Sea Battle :\n\t\t\t\t       --------------\n\n";
        }
        else
        {
            cout<<"\n      --------------\n      ";
            cout<<": Sea Battle :\n      --------------\n\n";
        }
    }
    int numchecker(int min_num,int max_num)
    {
        int num;
        while(!(cin>>num)||(num>max_num)||(num<min_num))
        {
            cout<<"\n::Invalid input::\n\n => ";
            cin.clear();
            cin.ignore(100,'\n');
        }
        return num;
    }
    void choose_base()
    {
        system("cls");
        sea_battle_intro(false);
        cout<<" Choose your base:\n\n Press 0 to change your layout.\n";
        cout<<" Press 1 to confirm the layout and start the game.\n\n";
        cout<<" Your layout:\n\n";
        make_random_layout(base,1);
        frame_maker(base,true);
        for(int i=0;i<12;i++)
        {
            cout<<"\t\t";
            for(int j=0;j<14;j++)
                cout<<base[i][j];
            cout<<endl;
        }
        cout<<"\n\n => ";
        input=numchecker(0,1);
        switch(input)
        {
        case 0:
            system("cls");
            sea_battle_intro(false);
            choose_base();
            break;
        case 1:
            system("cls");
        }
    }
    void frame_maker(string ground[][14],bool reset_all)
    {
        string drown_block="";
        drown_block+=char(176);
        drown_block+=char(176);
        if(reset_all==false)
        {
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<14;j++)
                {
                    if(ground[i][j]==drown_block)
                    {
                        if(i==0||i==11)
                        {
                            string repeat="";
                            if(j<12)
                            {
                                repeat+=char(205);
                                repeat+=char(205);
                            }
                            ground[i][j]=repeat;
                        }
                        if((j==0)||(j==13))
                        {
                            if((i==0)&&(j==0))
                                ground[i][j]=char(201);
                            else if((i==11)&&(j==0))
                                ground[i][j]=char(200);
                            else if((i==11)&&(j==13))
                                ground[i][j]=char(188);
                            else if((i==0)&&(j==13))
                                ground[i][j]=char(187);
                            else
                                ground[i][j]=char(186);
                        }
                        if((j==1)||(j==12))
                        {
                            if((i>0)&&(i<11))
                                ground[i][j]=" ";
                        }
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<12;i++)
            {
                for(int j=0;j<14;j++)
                {
                    if(i==0||i==11)
                    {
                        string repeat="";
                        if(j<12)
                        {
                            repeat+=char(205);
                            repeat+=char(205);
                        }
                        ground[i][j]=repeat;
                    }
                    if((j==0)||(j==13))
                    {
                        if((i==0)&&(j==0))
                            ground[i][j]=char(201);
                        else if((i==11)&&(j==0))
                            ground[i][j]=char(200);
                        else if((i==11)&&(j==13))
                            ground[i][j]=char(188);
                        else if((i==0)&&(j==13))
                            ground[i][j]=char(187);
                        else
                            ground[i][j]=char(186);
                    }
                    if((j==1)||(j==12))
                    {
                        if((i>0)&&(i<11))
                            ground[i][j]=" ";
                    }
                }
            }
        }
    }
    void layout_reset(string ground[][14])
    {
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
                ground[i][j]=water;
        }
    }
    bool neighbor_checker(int ship_type,string ground[][14])
    {
        int counter=0;
        if(ground[Coordinates_y][Coordinates_x-1]==ship)
            counter++;
        if(ground[Coordinates_y-1][Coordinates_x-1]==ship)
            counter++;
        if(ground[Coordinates_y-1][Coordinates_x]==ship)
            counter++;
        if(ground[Coordinates_y][Coordinates_x+1]==ship)
            counter++;
        if(ground[Coordinates_y+1][Coordinates_x+1]==ship)
            counter++;
        if(ground[Coordinates_y+1][Coordinates_x]==ship)
            counter++;
        if(ground[Coordinates_y-1][Coordinates_x+1]==ship)
            counter++;
        if(ground[Coordinates_y+1][Coordinates_x-1]==ship)
            counter++;
        if(counter==ship_type)
            return true;
        else
            return false;
    }
    void make_random_layout(string ground[][14],int base_type)
    {
        while(1)
        {
            if(base_type==1)
                layout_reset(base);
            if(base_type==2)
                layout_reset(opponent_base_hidden);
            if(base_type==3)
                layout_reset(example_base);
            Coordinates_y=rand()%6+3;
            Coordinates_x=rand()%6+4;
            ground[Coordinates_y][Coordinates_x]=ship;
            if(rand()%2==0)
            {
                ground[Coordinates_y][Coordinates_x-1]=ship;
                ground[Coordinates_y][Coordinates_x+1]=ship;
                ground[Coordinates_y][Coordinates_x+2]=ship;
            }
            else
            {
                ground[Coordinates_y-1][Coordinates_x]=ship;
                ground[Coordinates_y+1][Coordinates_x]=ship;
                ground[Coordinates_y+2][Coordinates_x]=ship;
            }
            total_ship++;
            for(number_of_ships=0;number_of_ships<2;)// 3ta
            {
                int right_place=0;
                Coordinates_y=2+(rand()%8);
                Coordinates_x=3+(rand()%8);
                if(neighbor_checker(0,ground)==true)
                    right_place++;
                else
                    continue;
                if(rand()%2==0)
                {
                    Coordinates_x--;
                    if(neighbor_checker(0,ground)==true)
                        right_place++;
                    else
                        continue;
                    Coordinates_x+=2;
                    if(neighbor_checker(0,ground)==true)
                        right_place++;
                    else
                        continue;
                    Coordinates_x--;
                    if(right_place==3)
                    {
                        ground[Coordinates_y][Coordinates_x]=ship;
                        ground[Coordinates_y][Coordinates_x-1]=ship;
                        ground[Coordinates_y][Coordinates_x+1]=ship;
                        number_of_ships++;
                    }
                }
                else
                {
                    Coordinates_y--;
                    if(neighbor_checker(0,ground)==true)
                        right_place++;
                    else
                        continue;
                    Coordinates_y+=2;
                    if(neighbor_checker(0,ground)==true)
                        right_place++;
                    else
                        continue;
                    Coordinates_y--;
                    if(right_place==3)
                    {
                        ground[Coordinates_y][Coordinates_x]=ship;
                        ground[Coordinates_y-1][Coordinates_x]=ship;
                        ground[Coordinates_y+1][Coordinates_x]=ship;
                        number_of_ships++;
                    }
                }
            }
            total_ship+=number_of_ships;
            for(number_of_ships=0;number_of_ships<3;)// 2ta
            {
                int right_place=0;
                Coordinates_y=2+(rand()%8);
                Coordinates_x=3+(rand()%8);
                if(neighbor_checker(0,ground)==true)
                    right_place++;
                else
                    continue;
                if(rand()%2==0)
                {
                    if(rand()%2==0)
                    {
                        Coordinates_x--;
                        if(neighbor_checker(0,ground)==true)
                            right_place++;
                        else
                            continue;//Ali Sadeghi
                        Coordinates_x++;
                        if(right_place==2)
                        {
                            ground[Coordinates_y][Coordinates_x]=ship;
                            ground[Coordinates_y][Coordinates_x-1]=ship;
                            number_of_ships++;
                        }
                    }
                    else
                    {
                        Coordinates_x++;
                        if(neighbor_checker(0,ground)==true)
                            right_place++;
                        else
                            continue;
                        Coordinates_x--;
                        if(right_place==2)
                        {
                            ground[Coordinates_y][Coordinates_x]=ship;
                            ground[Coordinates_y][Coordinates_x+1]=ship;
                            number_of_ships++;
                        }
                    }
                }
                else
                {
                    if(rand()%2==0)
                    {
                        Coordinates_y--;
                        if(neighbor_checker(0,ground)==true)
                            right_place++;
                        else
                            continue;
                        Coordinates_y++;
                        if(right_place==2)
                        {
                            ground[Coordinates_y][Coordinates_x]=ship;
                            ground[Coordinates_y-1][Coordinates_x]=ship;
                            number_of_ships++;
                        }
                    }
                    else
                    {
                        Coordinates_y++;
                        if(neighbor_checker(0,ground)==true)
                            right_place++;
                        else
                            continue;
                        Coordinates_y--;
                        if(right_place==2)
                        {
                            ground[Coordinates_y][Coordinates_x]=ship;
                            ground[Coordinates_y+1][Coordinates_x]=ship;
                            number_of_ships++;
                        }
                    }
                }
            }
            total_ship+=number_of_ships;
            for(number_of_ships=0;number_of_ships<4;)// 1ta
            {
                Coordinates_y=1+(rand()%10);
                Coordinates_x=2+(rand()%10);
                if(ground[Coordinates_y][Coordinates_x]!=ship)
                {
                    if(neighbor_checker(0,ground)==true)
                    {
                        ground[Coordinates_y][Coordinates_x]=ship;
                        number_of_ships++;
                    }
                }
            }
            total_ship+=number_of_ships;
            if(total_ship==10)
                break;
            else
                total_ship=0;
        }
    }
    bool repeat_checker_process(int location_a,int location_b)
    {
        if((base[location_a][0]==half_air_defence)||(base[location_b][0]==half_air_defence))
            return true;
        else
            return false;
    }
    bool repeat_checker_function()
    {
        bool process;
        switch(input)
        {
        case 0:
            process=repeat_checker_process(1,2);
            break;
        case 1:
            process=repeat_checker_process(3,4);
            break;
        case 2:
            process=repeat_checker_process(5,6);
            break;
        case 3:
            process=repeat_checker_process(7,8);
            break;
        case 4:
            process=repeat_checker_process(9,10);
            break;
        case 5:
            process=repeat_checker_process(2,3);
            break;
        case 6:
            process=repeat_checker_process(4,5);
            break;
        case 7:
            process=repeat_checker_process(6,7);
            break;
        case 8:
            process=repeat_checker_process(8,9);
            break;
        case 9:
            process=false;
        }
        return process;
    }
    void air_defence_process(int location_a,int location_b)
    {
        base[location_a][0]=char(204);
        base[location_b][0]=char(204);
        base[location_a][1]=char(187);
        base[location_b][1]=char(188);
        amount_air_defence++;
        money-=10;
        air_defence_place[++purchased_air_defense]=location_a;
        air_defence_place[++purchased_air_defense]=location_b;
        air_defence();
    }
    void air_defence()
    {
        system("cls");
        sea_battle_intro(false);
        cout<<" In which line do you want to place air defense ? (";
        cout<<amount_air_defence<<"/3)\n\n";
        for(int i=0;i<12;i++)
        {
            cout<<"\t";
            if((i%2==0)&&(i<10)&&(i>1))
                cout<<(i/2)+4<<" ";
            else
            {
                if((i>1)&&(i<10))
                    cout<<char(192)<<" ";
                else
                    cout<<"  ";
            }
            if((i%2!=0)&&(i<10))
                cout<<i/2<<" ";
            else
            {
                if((i>0)&&(i<11))
                    cout<<char(192)<<" ";
                else
                    cout<<"  ";
            }
            for(int j=0;j<14;j++)
                cout<<base[i][j];
            cout<<endl;
        }
        if(amount_air_defence<3)
        {
            cout<<" 9) Go Back\n\n => ";
            while(1)
            {
                input=numchecker(0,9);
                if(repeat_checker_function()==false)
                    break;
                else
                    cout<<"\n You can't put two air defenses in one place !\n\n => ";
            }
            switch(input)
            {
            case 0:
                air_defence_process(1,2);
                break;
            case 1:
                air_defence_process(3,4);
                break;
            case 2:
                air_defence_process(5,6);
                break;
            case 3:
                air_defence_process(7,8);
                break;
            case 4:
                air_defence_process(9,10);
                break;
            case 5:
                air_defence_process(2,3);
                break;
            case 6:
                air_defence_process(4,5);
                break;
            case 7:
                air_defence_process(6,7);
                break;
            case 8:
                air_defence_process(8,9);
                break;
            case 9:
                buy_stuff();
            }
        }
        else
        {
            cout<<"You can only have 3 air defenses !\n\n";
            system("Pause");
            buy_stuff();
        }
    }
    void buy_process(int &type_amount,int max_amount,int type_price,string type_name)
    {
        if(type_amount<max_amount)
        {
            type_amount++;
            money-=type_price;
            buy_stuff();
        }
        else
        {
            cout<<"\n You can no longer choose "<<type_name<<" !\n\n ";
            system("Pause");
            buy_stuff();
        }
    }
    void debt_solver_process(int &type_amount,int type_price)
    {
        if(type_amount>0)
        {
            type_amount--;
            money+=type_price;
        }
        else
        {
            cout<<"\n You can't sell this item !\n\n";
            system("Pause");
            system("cls");
        }
    }
    void debt_solver()
    {
        switch(input)
        {
        case 2:
            if(amount_air_defence>0)
            {
                amount_air_defence=0;
                money+=30;
                for(int i=1;i<11;i++)
                    base[i][0]=char(186);
            }
            else
            {
                cout<<"\n You can't sell this item !\n\n";
                system("Pause");
                system("cls");
            }
            break;
        case 3:
            debt_solver_process(amount_torpedo,10);
            break;
        case 4:
            debt_solver_process(amount_fighter,15);
            break;
        case 5:
            debt_solver_process(amount_bomber,12);
            break;
        case 6:
            debt_solver_process(amount_radar,15);
            break;
        case 7:
            debt_solver_process(amount_nuc,90);
            break;
        }
    }
    void buy_stuff_menu()
    {
        sea_battle_intro(false);
        if(money>0)
            buy_sell=" Buy ";
        static int reload=0;
        cout<<"\n Determine your layout:\n (you are left)\t\t\t\t ";
        cout<<"Money:\n\t\t\t\t\t"<<char(218);
        for(int i=0;i<15;i++)
            cout<<char(196);
        cout<<char(191);
        cout<<"\n 0) Reset layout\t\t\t"<<char(179);
        if(inf_money==false&&money<150)
        {
            int i=0;
            if(money>10)
            {
                for(i;i<money/10;i++)
                {
                    cout<<char(176);
                    if(i==((money/10)-1))
                    {
                        for(i;i<14;i++)
                            cout<<" ";
                    }
                }
            }
            else if(money>=0)
            {
                cout<<" ";
                for(i;i<14;i++)
                    cout<<" ";
            }
            else
                cout<<"You are in debt";
        }
        else
        {
            for(int i=0;i<15;i++)
                cout<<char(176);
        }
        cout<<char(179)<<"  "<<money<<",000 $";
        cout<<"\n 1) Confirm layout and start\t\t"<<char(192);;
        for(int i=0;i<15;i++)
            cout<<char(196);
        cout<<char(217);
        cout<<"\n\t\t\t\t\t";
        for(int j=0;j<14;j++)
            cout<<base[0][j];
        if(buy_sell==" Buy ")
            cout<<"\n 2)"<<buy_sell<<"Air Defense ("<<amount_air_defence<<"/3)\t"<<char(26)<<" 10k\t";
        else
            cout<<"\n 2)"<<buy_sell<<"All Air Defense ("<<amount_air_defence<<"/3)\t"<<char(26)<<" 10k\t";
        for(int j=0;j<14;j++)
            cout<<base[1][j];
        cout<<"\n 3)"<<buy_sell<<"Torpedo Carrier ("<<amount_torpedo<<"/2)\t"<<char(26)<<" 10k\t";
        for(int j=0;j<14;j++)
            cout<<base[2][j];
        cout<<"\n 4)"<<buy_sell<<"Fighter ("<<amount_fighter<<"/2)\t\t"<<char(26)<<" 15k\t";
        for(int j=0;j<14;j++)
            cout<<base[3][j];
        cout<<"\n 5)"<<buy_sell<<"Bomber ("<<amount_bomber<<"/2)\t\t"<<char(26)<<" 12k\t";
        for(int j=0;j<14;j++)
            cout<<base[4][j];
        cout<<"\n 6)"<<buy_sell<<"Radar ("<<amount_radar<<"/1)\t\t"<<char(26)<<" 15k\t";
        for(int j=0;j<14;j++)
            cout<<base[5][j];
        cout<<"\n 7)"<<buy_sell<<"Nuclear Bomb ("<<amount_nuc<<"/1)\t"<<char(26)<<" 90k\t";
        for(int j=0;j<14;j++)
            cout<<base[6][j];
        cout<<"\n\t\t\t\t\t";
        for(int j=0;j<14;j++)
            cout<<base[7][j];
        cout<<"\n 8) View Aircraft Information\t\t";
        for(int j=0;j<14;j++)
            cout<<base[8][j];
        cout<<"\n 9) Advance Setting\t\t\t";
        for(int j=0;j<14;j++)
            cout<<base[9][j];
        for(int i=10;i<12;i++)
        {
            cout<<"\n\t\t\t\t\t";
            for(int j=0;j<14;j++)
                cout<<base[i][j];
        }
        if(money<0)
        {
            buy_sell=" Sell ";
            static int reload=1;
            reload++;
            if(reload%2==0)
            {
                system("cls");
                buy_stuff_menu();
            }
            if(money<0)
            {
                cout<<"\n You can not be in debt !\n Which one do you want to sell ?\n\n => ";
                input=numchecker(2,7);
                debt_solver();
                system("cls");
                buy_stuff_menu();
            }
        }
        else
            cout<<"\n => ";
    }
    void boolChanger(bool &adv_input)
    {
        if(adv_input==true)
            adv_input=false;
        else
            adv_input=true;
    }
    void adv_setting()
    {
        system("cls");
        sea_battle_intro(false);
        cout<<boolalpha;
        cout<<" Choose an option:\n\n";
        cout<<" 1) Show opponent ground in the game ("<<show_opp_ground<<")\n";
        cout<<" 2) Become rich ("<<inf_money<<")\n";
        cout<<" 3) Just AI play ("<<just_AI<<")\n";
        cout<<" 4) Opponent sonic mode("<<opponent_rapide<<")\n";
        cout<<" 5) Go back\n";
        cout<<"\n => ";
        int adv_input=numchecker(1,5);
        switch(adv_input)
        {
        case 1:
            boolChanger(show_opp_ground);
            break;
        case 2:
            boolChanger(inf_money);
            reset_stuff();
            break;
        case 3:
            boolChanger(just_AI);
            break;
        case 4:
            boolChanger(opponent_rapide);
            break;
        case 5:
            buy_stuff();
        }
        adv_setting();
    }
    void example_bomber_process(int i,int j)
    {
        if(example_base[i][j]==ship)
            example_base[i][j]=ship_hit;
        if(example_base[i][j]==water)
            example_base[i][j]=not_hit;
    }
    void show_information()
    {
        system("cls");
        sea_battle_intro(false);
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
                example_base[i][j]=copy_example_base[i][j];
        }
        cout<<" Which explanation do you want to see?\n\n 1)Air defence\n 2)Torpedo carrier\n 3)Fighter\n 4)Bomber\n 5)Radar\n 6)Nuclear bomb\n 7)Go back\n\n => ";
        input=numchecker(1,7);
        int random_place_a;
        int random_place_b;
        int repeat_memory=0;
        int counter=0;
        switch(input)
        {
        case 1:
        {
            int air_defence_counter=0;
            int air_defence_place_example[6];
            for(int i=0;i<6;i++)
                air_defence_place_example[i]=0;
            for(int i=0;i<3;i++)
            {
                random_place_a=(rand()%8)+1;
                while(1)
                {
                    if((example_base[random_place_a][1]==" ")&&(example_base[random_place_a+1][1]==" "))
                    {
                        if(random_place_a!=repeat_memory)
                            break;
                    }
                    else
                        random_place_a=(rand()%8)+1;
                }
                example_base[random_place_a][0]=char(204);
                example_base[random_place_a+1][0]=char(204);
                example_base[random_place_a][1]=char(187);
                example_base[random_place_a+1][1]=char(188);
                air_defence_place_example[air_defence_counter++]=random_place_a;
                air_defence_place_example[air_defence_counter++]=++random_place_a;
            }
            system("cls");
            sea_battle_intro(false);
            cout<<" On your own ground, you can put 3 air defenses that prevent the opponent from attacking.\n";
            cout<<" Each air defense has two barrels for firing and covers two rows and can only defend that row once.\n\n";
            for(int i=0;i<12;i++)
            {
                cout<<"\t\t";
                for(int j=0;j<14;j++)
                    cout<<example_base[i][j];
                cout<<endl;
            }
            Sleep(1000);
            while(1)
            {
                random_place_b=(rand()%8)+1;
                for(int i=0;i<6;i++)
                {
                    if(random_place_b==air_defence_place_example[i])
                    {
                        Sleep(1000);
                        example_base[random_place_b][0]=char(186);
                        example_base[random_place_b][1]=" ";
                        air_defence_place_example[i]=0;
                        counter++;
                        system("cls");
                        sea_battle_intro(false);
                        cout<<" On your own ground, you can put 3 air defenses that prevent the opponent from attacking.\n";
                        cout<<" Each air defense has two barrels for firing and covers two rows and can only defend that row once.\n\n";
                        for(int i=0;i<12;i++)
                        {
                            cout<<"\t\t";
                            for(int j=0;j<14;j++)
                                cout<<example_base[i][j];
                            cout<<endl;
                        }
                        if(counter==5)//PRBLM...
                        {
                            cout<<"\n\n ";
                            system("Pause");
                            show_information();
                        }
                    }
                }
            }
        }
        case 2:
            for(counter;counter<3;counter++)
            {
                random_place_a=(rand()%10)+1;
                while(1)
                {
                    if(random_place_a!=repeat_memory)
                        break;
                    else
                        random_place_a=(rand()%10)+1;
                }
                system("cls");
                sea_battle_intro(false);
                cout<<" You enter the row number and destroy the entire row.\n\n";
                for(int i=0;i<12;i++)
                {
                    cout<<"\n\t\t";
                    for(int j=0;j<14;j++)
                    {
                        if(i==random_place_a)
                        {
                            if(example_base[random_place_a][j]==ship)
                                example_base[random_place_a][j]=ship_hit;
                            if(example_base[random_place_a][j]==water)
                                example_base[random_place_a][j]=not_hit;
                        }
                        cout<<example_base[i][j];
                    }
                }
                Sleep(1000);
                repeat_memory=random_place_a;
            }
            cout<<"\n\n ";
            system("Pause");
            show_information();
        case 3:
            for(counter;counter<2;counter++)
            {
                random_place_a=(rand()%8)+1;
                while(1)
                {
                    if(random_place_a==repeat_memory||random_place_a+1==repeat_memory||random_place_a-1==repeat_memory)
                        random_place_a=(rand()%9)+1;
                    else
                        break;
                }
                system("cls");
                sea_battle_intro(false);
                cout<<" You enter the top row number and it will destroy the whole row and the bottom row.\n\n";
                for(int i=0;i<12;i++)
                {
                    cout<<"\n\t\t";
                    for(int j=0;j<14;j++)
                    {
                        if(i==random_place_a)
                        {
                            if(example_base[random_place_a][j]==ship)
                                example_base[random_place_a][j]=ship_hit;
                            if(example_base[random_place_a][j]==water)
                                example_base[random_place_a][j]=not_hit;
                            if(example_base[random_place_a+1][j]==ship)
                                example_base[random_place_a+1][j]=ship_hit;
                            if(example_base[random_place_a+1][j]==water)
                                example_base[random_place_a+1][j]=not_hit;
                        }
                        cout<<example_base[i][j];
                    }
                }
                Sleep(1000);
            }
            cout<<"\n\n ";
            system("Pause");
            show_information();
        case 4:
            for(counter;counter<2;counter++)
            {
                random_place_a=(rand()%8)+2;
                random_place_b=(rand()%8)+4;
                system("cls");
                sea_battle_intro(false);
                cout<<" You enter the coordinates of the middle house of a 3 x 3 square and randomly 6 out of 9 houses are get bombed.";
                cout<<"\n(This is just an example and 6 houses may not be hit)\n";
                int array_memory[6];
                for(int i=0;i<6;i++)
                    array_memory[i]=0;
                for(int i=0;i<12;i++)
                {
                    for(int j=0;j<14;j++)
                    {
                        if(i==random_place_a&&j==random_place_b)
                        {
                            for(int randomizer=0;randomizer<6;randomizer++)
                            {
                                input=rand()%9;
                                while (1)
                                {
                                    int repeat_counter=0;
                                    for(int checker=0;checker>6;checker++)
                                    {
                                        if(checker==input)
                                            repeat_counter++;
                                    }
                                    if(repeat_counter==0)
                                        break;
                                    else
                                        input=rand()%9;
                                }
                                int arrsize = sizeof(array_memory)/sizeof(array_memory[0]);
                                array_memory[arrsize+1]=input;
                                switch(input)
                                {
                                case 0:
                                    example_bomber_process(random_place_a-1,random_place_b-1);
                                    break;
                                case 1:
                                    example_bomber_process(random_place_a,random_place_b-1);
                                    break;
                                case 2:
                                    example_bomber_process(random_place_a+1,random_place_b-1);
                                    break;
                                case 3:
                                    example_bomber_process(random_place_a-1,random_place_b);
                                    break;
                                case 4:
                                    example_bomber_process(random_place_a,random_place_b);
                                    break;
                                case 5:
                                    example_bomber_process(random_place_a+1,random_place_b);
                                    break;
                                case 6:
                                    example_bomber_process(random_place_a-1,random_place_b+1);
                                    break;
                                case 7:
                                    example_bomber_process(random_place_a,random_place_b+1);
                                    break;
                                case 8:
                                    example_bomber_process(random_place_a+1,random_place_b+1);
                                    break;
                                }
                            }
                        }
                    }
                }
                for(int i=0;i<12;i++)
                {
                    cout<<"\n\t\t";
                    for(int j=0;j<14;j++)
                        cout<<example_base[i][j];
                }
                Sleep(1000);
            }
            cout<<"\n\n ";
            system("Pause");
            show_information();
        case 5:
            random_place_a=(rand()%6)+3;
            random_place_b=(rand()%6)+4;
            system("cls");
            sea_battle_intro(false);
            cout<<" Enter the coordinates of the house in the middle of the 3 x 3 square and it will show you the location of the\n opponent's land ships for a while ";
            cout<<"(here the place of the opponent's ships can be seen, this is not the case in the game)\n\n";
            for(int i=0;i<12;i++)
            {
                cout<<"\n\t\t";
                for(int j=0;j<14;j++)
                    cout<<example_base[i][j];
            }
            Sleep(1000);
            system("cls");
            sea_battle_intro(false);
            cout<<" Enter the coordinates of the house in the middle of the 3 * 3 square and it will show you the location of the\nopponent's land ships for a while ";
            cout<<"(here the place of the opponent's ships can be seen, this is not the case in the game)\n\n";
            release_radar(example_base,random_place_a,random_place_b,true);
            for(int i=0;i<12;i++)
            {
                cout<<"\n\t\t";
                for(int j=0;j<14;j++)
                    cout<<example_base[i][j];
            }
            Sleep(3000);
            system("cls");
            sea_battle_intro(false);
            cout<<" Enter the coordinates of the house in the middle of the 3 * 3 square and it will show you the location of the\nopponent's land ships for a while ";
            cout<<"(here the place of the opponent's ships can be seen, this is not the case in the game)\n\n";
            for(int i=0;i<12;i++)
            {
                cout<<"\n\t\t";
                for(int j=0;j<14;j++)
                    cout<<copy_example_base[i][j];
            }
            Sleep(1000);
            cout<<"\n\n ";
            system("Pause");
            show_information();
        case 6:
            random_place_a=(rand()%4)+4;
            random_place_b=(rand()%4)+5;
            system("cls");
            sea_battle_intro(false);
            cout<<" Enter the coordinates of the house in the middle of the 7 * 7 square and there will be a lot of damage!\n\n";
            for(int i=0;i<12;i++)
            {
                cout<<"\n\t\t";
                for(int j=0;j<14;j++)
                    cout<<example_base[i][j];
            }
            Sleep(1000);
            system("cls");
            sea_battle_intro(false);
            cout<<" Enter the coordinates of the house in the middle of the 7 * 7 square and there will be a lot of damage!\n\n";
            release_nuc(random_place_a,random_place_b,true);
            for(int i=0;i<12;i++)
            {
                cout<<"\n\t\t";
                for(int j=0;j<14;j++)
                    cout<<example_base[i][j];
            }
            Sleep(3000);
            cout<<"\n\n ";
            system("Pause");
            show_information();
        case 7:
            buy_stuff();
            start_game();
        }
    }
    void reset_stuff()
    {
        amount_air_defence=0;
        amount_bomber=0;
        amount_fighter=0;
        amount_torpedo=0;
        amount_radar=0;
        amount_nuc=0;
        for(int i=1;i<11;i++)
            base[i][0]=char(186);
        for(int i=1;i<11;i++)
            base[i][1]=" ";
        if(inf_money==false)
            money=money_copy;
        else
            money=3000;
        for(int i=0;i<6;i++)
            air_defence_place[i]=0;
        purchased_air_defense=-1;
    }
    void buy_stuff()
    {
        system("cls");
        buy_stuff_menu();
        input=numchecker(0,9);
        switch(input)
        {
        case 0:
            reset_stuff();
            buy_stuff();
            break;
        case 1:
            start_game();
            break;
        case 2:
            if(amount_air_defence<3)
                air_defence();
            else
                buy_process(amount_air_defence,3,0,"Air Defence");
            break;
        case 3:
            buy_process(amount_torpedo,2,10,"Torpedo Carrier");
            break;
        case 4:
            buy_process(amount_fighter,2,15,"Fighter");
            break;
        case 5:
            buy_process(amount_bomber,2,12,"Bomber");
            break;
        case 6:
            buy_process(amount_radar,1,15,"Radar");
            break;
        case 7:
            buy_process(amount_nuc,1,90,"Nuclear Bomb");
            break;
        case 8:
            show_information();
            break;
        case 9:
            adv_setting();
        }
    }
    void hit_ship_congrats()
    {
        if(hit_ship==true)
        {
            int random_congrats=rand()%5;
            static int last_congrats=6;
            if(last_congrats==random_congrats)
            {
                hit_ship_congrats();
                return;
            }
            switch(random_congrats)
            {
            case 0:
                cout<<"   Nice!      ";
                break;
            case 1:
                cout<<"   Bravo!     ";
                break;
            case 2:
                cout<<" Well done!   ";
                break;
            case 3:
                cout<<"   Sweet!     ";
                break;
            case 4:
                cout<<"  Awesome!    ";
                break;
            }
            last_congrats=random_congrats;
        }
        else
            cout<<"\t";
    }
    void game_menu()
    {
        system("cls");
        sea_battle_intro(true);
        cout<<" "<<char(218);
        for(int i=0;i<88;i++)
            cout<<char(196);
        cout<<char(191);
        cout<<"\n "<<char(179)<<" 0."<<use_cancel<<" || ";
        if(use_cancel=="Cancel")
        {
            cout<<"1.Torpedo Carrier("<<amount_torpedo;
            cout<<") 2.Fighter("<<amount_fighter<<") 3.Bomber("<<amount_bomber;
            cout<<") 4.Radar("<<amount_radar<<") 5.Nuclear Bomb("<<amount_nuc<<") ";
        }
        else
        {
            for(int i=0;i<9;i++)
                cout<<"\t";
            cout<<"  ";
        }
        cout<<char(179)<<endl<<" "<<char(195);
        for(int i=0;i<88;i++)
            cout<<char(196);
        cout<<char(180);
        cout<<endl<<" "<<char(179);
        for(int i=0;i<11;i++)
            cout<<"\t";
        cout<<"  "<<char(179);
        cout<<"\n "<<char(179)<<"      Your Base :\t\t\t\t\t   Opponent Base :\t\t";
        cout<<"  "<<char(179)<<endl;
        for(int i=0;i<12;i++)
        {
            if((i<=10)&&(i>=1))
                cout<<" "<<char(179)<<"   "<<setw(2)<<setfill(' ')<<i<<" ";
            else
                cout<<" "<<char(179)<<"      ";
            for(int j=0;j<14;j++)
                cout<<base[i][j];
            cout<<"     ";
            switch(i)
            {
            case 2:
                cout<<"\t";
                hit_ship_congrats();
                break;
            case 4:
                cout<<char(218);
                for(int i=0;i<15;i++)
                    cout<<char(196);
                cout<<char(191);
                break;
            case 5:
                if(turn==true)//=>
                {
                    cout<<char(179)<<"  "<<char(201);
                    for(int i=0;i<8;i++)
                        cout<<char(205);
                    cout<<char(190)<<"\\  "<<char(179);
                }
                else//<=
                {
                    cout<<char(179)<<"  /"<<char(212);
                    for(int i=0;i<8;i++)
                        cout<<char(205);
                    cout<<char(187)<<"  "<<char(179);
                }
                break;
            case 6:
                if(turn==true)//=>
                {
                    cout<<char(179)<<"  "<<char(200);
                    for(int i=0;i<8;i++)
                        cout<<char(205);
                    cout<<char(184)<<"/  "<<char(179);
                }
                else//<=
                {
                    cout<<char(179)<<"  \\"<<char(213);
                    for(int i=0;i<8;i++)
                        cout<<char(205);
                    cout<<char(188)<<"  "<<char(179);
                }
                break;
            case 7:
                cout<<char(192);
                for(int i=0;i<15;i++)
                    cout<<char(196);
                cout<<char(217);
                break;
            default:
                cout<<"\t\t";
            }
            cout<<"\t   ";
            for(int j=0;j<14;j++)
                cout<<opponent_base_visible[i][j];
            if((i<=10)&&(i>=1))
                cout<<left<<" "<<setw(2)<<setfill(' ')<<i;
            if(show_opp_ground==false)
                cout<<right<<"\t  "<<char(179);
            else
            {
                cout<<right<<"\t  "<<char(179)<<"\t";
                for(int j=0;j<14;j++)
                    cout<<opponent_base_hidden[i][j];
            }
            cout<<endl;
        }
        cout<<" "<<char(179)<<"\t  ";
        for(int i=10;i>0;i--)
            cout<<setw(2)<<setfill(' ')<<i;
        cout<<"\t\t\t\t    ";
        if(show_row==true)
        {
            for(int i=1;i<10;i++)
                cout<<setw(2)<<setfill(' ')<<i;
            cout<<" 10\t  ";
        }
        else
            cout<<"\t\t\t\t  ";
        cout<<char(179)<<endl<<" "<<char(179);
        for(int i=0;i<11;i++)
            cout<<"\t";
        cout<<"  "<<char(179)<<endl<<" "<<char(192);
        for(int i=0;i<88;i++)
            cout<<char(196);
        cout<<char(217)<<"\n  ";
    }
    void use_cancel_changer()
    {
        if(use_cancel=="Cancel")
            use_cancel="Use Equipment";
        else
            use_cancel="Cancel";
    }
    void release_torpido(int input)
    {
        int counter=0;
        for(int i=2;i<12;i++)
        {
            if(opponent_base_hidden[input][i]==ship)
            {
                opponent_base_visible[input][i]=ship_hit;
                counter++;
            }
            else
                opponent_base_visible[input][i]=not_hit;
            Sleep(30);
            game_menu();
            drown_checker_opponent();
        }
        show_column=true;
        show_row=false;
        if(counter>0)
        {
            hit_ship=true;
            use_cancel_changer();
            start_game();
        }
    }
    void release_fighter(int input)
    {
        int counter=0;
        for(int j=2;j<12;j++)
        {
            if(opponent_base_hidden[input][j]==ship)
            {
                opponent_base_visible[input][j]=ship_hit;
                counter++;
            }
            else
                opponent_base_visible[input][j]=not_hit;
            if(opponent_base_hidden[input+1][j]==ship)
            {
                opponent_base_visible[input+1][j]=ship_hit;
                counter++;
            }
            else
                opponent_base_visible[input+1][j]=not_hit;
            Sleep(30);
            game_menu();
            drown_checker_opponent();
        }
        show_column=true;
        show_row=false;
        if(counter>0)
        {
            hit_ship=true;
            use_cancel_changer();
            start_game();
        }
    }
    int release_bomber_process(int row,int column)
    {
        int counter=0;
        if(opponent_base_hidden[row][column]==ship)
        {
            opponent_base_visible[row][column]=ship_hit;
            counter++;
        }
        else
            opponent_base_visible[row][column]=not_hit;
        Sleep(30);
        frame_maker(opponent_base_visible,false);
        game_menu();
        return counter;
    }
    void release_bomber(int row,int column)
    {
        static int counter=0;
        int repeat_counter=0;
        for(int i=0;i<6;i++)
        {
            repeat_counter++;
            switch(rand()%9)
            {
            case 0:
                if(opponent_base_visible[row-1][column-1]==not_hit||opponent_base_visible[row-1][column-1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row-1,column-1);
                break;
            case 1:
                if(opponent_base_visible[row][column-1]==not_hit||opponent_base_visible[row][column-1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row,column-1);
                break;
            case 2:
                if(opponent_base_visible[row+1][column-1]==not_hit||opponent_base_visible[row+1][column-1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row+1,column-1);
                break;
            case 3:
                if(opponent_base_visible[row-1][column]==not_hit||opponent_base_visible[row-1][column]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row-1,column);
                break;
            case 4:
                if(opponent_base_visible[row][column]==not_hit||opponent_base_visible[row][column]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row,column);
                break;
            case 5:
                if(opponent_base_visible[row+1][column]==not_hit||opponent_base_visible[row+1][column]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row+1,column);
                break;
            case 6:
                if(opponent_base_visible[row-1][column+1]==not_hit||opponent_base_visible[row-1][column+1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row-1,column+1);
                break;
            case 7:
                if(opponent_base_visible[row][column+1]==not_hit||opponent_base_visible[row][column+1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row,column+1);
                break;
            case 8:
                if(opponent_base_visible[row+1][column+1]==not_hit||opponent_base_visible[row+1][column+1]==ship_hit)
                    i--;
                else
                    counter+=release_bomber_process(row+1,column+1);
                break;
                drown_checker_opponent();
            }
            if(repeat_counter>30)
                i=6;
            drown_checker_opponent();
        }
        if(counter>0)
        {
            hit_ship=true;
            use_cancel_changer();
            start_game();
        }
    }
    void release_radar(string ground[][14],int row,int column,bool example_function)
    {
        row--;
        column--;
        string copy_opponent_base[12][14];
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
                copy_opponent_base[i][j]=ground[i][j];
        }
        for(int i=-1;i<4;i++)
        {
            for(int j=-1;j<4;j++)
            {
                if(i==-1||i==3)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(196);
                    ground[row+i][column+j]+=char(196);
                }
                if(j==-1)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(179);
                    ground[row+i][column+j]+=" ";
                }
                if(j==3)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=" ";
                    ground[row+i][column+j]+=char(179);
                }
                if(i==-1&&j==-1)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(218);
                    ground[row+i][column+j]+=char(196);
                }
                if(i==-1&&j==3)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(196);
                    ground[row+i][column+j]+=char(191);
                }
                if(i==3&&j==3)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(196);
                    ground[row+i][column+j]+=char(217);
                }
                if(i==3&&j==-1)
                {
                    ground[row+i][column+j]="";
                    ground[row+i][column+j]+=char(192);
                    ground[row+i][column+j]+=char(196);
                }
            }
        }
        if(example_function==true)
            return;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                opponent_base_visible[row+i][column+j]=opponent_base_hidden[row+i][column+j];
        }
        frame_maker(opponent_base_visible,false);
        for(int i=7;i>0;i--)
        {
            Sleep(1000);
            system("cls");
            game_menu();
            cout<<"Timer: "<<i<<"s\n";
        }
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
                opponent_base_visible[i][j]=copy_opponent_base[i][j];
        }
    }
    int release_nuc_process(int &counter,int row,int column,bool example_function)
    {
        if(example_function==false)
        {
            if(opponent_base_hidden[row][column]==ship)
            {
                opponent_base_visible[row][column]=ship_hit;
                counter++;
            }
            if(opponent_base_hidden[row][column]==water)
                opponent_base_visible[row][column]=not_hit;
            return counter;
        }
        else
        {
            if(example_base[row][column]==ship)
                example_base[row][column]=ship_hit;
            if(example_base[row][column]==water)
                example_base[row][column]=not_hit;
        }
    }
    void release_nuc(int row,int column,bool example_function)
    {
        int counter=0;
        int even=0;
        for(int i=-3;i<4;i++)
        {
            for(int j=-3;j<4;j++)
            {
                even++;
                if(even%2==0)
                    counter=release_nuc_process(counter,row+i,column+j,example_function);
            }
        }
        for(int i=-2;i<3;i++)
        {
            for(int j=-2;j<3;j++)
            {
                if((i==-2&&j==-2)||(i==-2&&j==2))
                    counter=counter;
                else if((i==2&&j==-2)||(i==2&&j==2))
                    counter=counter;
                else
                    counter=release_nuc_process(counter,row+i,column+j,example_function);
            }
        }
        if(example_function==false)
        {
            drown_checker_opponent();
            if(counter>0)
            {
                hit_ship=true;
                start_game();
            }
        }
    }
    void use_stuff()
    {
        cout<<"What equipment do you want to use?\n\n ==> ";
        input=numchecker(0,5);
        system("cls");
        int column;
        int row;
        switch(input)
        {
        case 0:
            use_cancel_changer();
            start_game();
            break;
        case 1:
            show_column=true;
            show_row=false;
            game_menu();
            if(amount_torpedo>0)
            {
                cout<<"In which row do you want to use?\n\n ==> ";
                while(1)
                {
                    input=numchecker(1,10);
                    static int duplicate_row=11;
                    if(duplicate_row==input)
                        cout<<"\n  You can't bomb same row!\n\n ==> ";
                    else
                    {
                        duplicate_row=input;
                        break;
                    }
                }
                amount_torpedo--;
                release_torpido(input);
                use_cancel_changer();
                opponent_turn();
            }
            else
            {
                cout<<"You can not choose torpedo carrier!\n\n  ";
                system("Pause");
                use_cancel_changer();
            }
            start_game();
        case 2:
            show_column=true;
            show_row=false;
            game_menu();
            if(amount_fighter>0)
            {
                cout<<"NOTE: you have to enter the top row.\n  In which row do you want to use?\n\n ==> ";
                while(1)
                {
                    input=numchecker(1,9);
                    static int duplicate_row=11;
                    if(duplicate_row==input)
                        cout<<"\n  You can't bomb same row!\n\n ==> ";
                    else
                    {
                        duplicate_row=input;
                        break;
                    }
                }
                amount_fighter--;
                release_fighter(input);
                use_cancel_changer();
                opponent_turn();
            }
            else
            {
                cout<<"You can not choose torpedo carrier!\n\n  ";
                system("Pause");
                use_cancel_changer();
            }
            start_game();
        case 3:
            show_column=false;
            show_row=true;
            game_menu();
            if(amount_bomber>0)
            {
                cout<<"NOTE: you have to enter the middle column.\n  In which column do you want to use?\n\n ==> ";
                column=numchecker(2,9);
                show_column=true;
                show_row=false;
                system("cls");
                game_menu();
                cout<<"Middle column = "<<column;
                cout<<"\n\n  NOTE: you have to enter the middle row.\n  In which row do you want to use?\n\n ==> ";
                row=numchecker(2,9);
                amount_bomber--;
                column++;
                release_bomber(row,column);
                use_cancel_changer();
                opponent_turn();
            }
            else
            {
                cout<<"You can not choose bomber!\n\n  ";
                system("Pause");
                use_cancel_changer();
            }
            start_game();
        case 4:
            show_column=false;
            show_row=true;
            game_menu();
            if(amount_radar>0)
            {
                cout<<"NOTE: you have to enter the middle column.\n  In which column do you want to use?\n\n ==> ";
                column=numchecker(2,9);
                show_column=true;
                show_row=true;
                system("cls");
                game_menu();
                cout<<"Middle column = "<<column;
                cout<<"\n\n  NOTE: you have to enter the middle row.\n  In which row do you want to use?\n\n ==> ";
                row=numchecker(2,9);
                amount_radar--;//Ali Sadeghi
                column++;
                release_radar(opponent_base_visible,row,column,false);
                use_cancel_changer();
                opponent_turn();
            }
            else
            {
                cout<<"You can not choose radar!\n\n  ";
                system("Pause");
                use_cancel_changer();
            }
            start_game();
        case 5:
            show_column=false;
            show_row=true;
            game_menu();
            if(amount_nuc>0)
            {
                cout<<"NOTE: you have to enter the middle column(3<X<8).\n  In which column do you want to use?\n\n ==> ";
                column=numchecker(4,7);
                show_column=true;
                show_row=false;
                system("cls");
                game_menu();
                cout<<"Middle column = "<<column;
                cout<<"\n\n  NOTE: you have to enter the middle row(3<X<8).\n  In which row do you want to use?\n\n ==> ";
                row=numchecker(4,7);
                amount_nuc--;
                column++;
                release_nuc(row,column,false);
                use_cancel_changer();
                opponent_turn();
            }
            else
            {
                cout<<"You can not choose nuclear bomb!\n\n  ";
                system("Pause");
                use_cancel_changer();
            }
            start_game();
        }
    }
    bool smart_opponent_checker(int row,int column)
    {
        if((base[row][column]==ship_hit)||(base[row][column]==ship))
        {
            if((base[row][column+1]==ship)||(base[row][column-1]==ship)||(base[row-1][column]==ship)||(base[row+1][column]==ship))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool smart_opponent(int row,int column)
    {
        switch(rand()%4)
        {
        case 0:
            if((base[row][column+1]!=not_hit)&&(base[row][column+1]!=ship_hit))
            {
                if(base[row][column+1]==ship)
                {
                    column++;
                    base[row][column]=ship_hit;
                    while(1)
                    {
                        if(smart_opponent_checker(row,column)==true)
                        {
                            game_menu();
                            column++;
                            base[row][column]=ship_hit;
                            Sleep(sleep_time);
                            game_menu();
                        }
                        else
                        {
                            turn=true;
                            start_game();
                        }
                    }
                    game_menu();
                    return false;
                }
                else
                {
                    base[row][column+1]=not_hit;
                    opponent_review[opponent_review_counter]=row;
                    opponent_review_counter++;
                    opponent_review[opponent_review_counter]=column;
                    opponent_review_counter++;
                }
                Sleep(sleep_time);
                game_menu();
            }
            else
                smart_opponent(row,column);
            break;
        case 1:
            if((base[row][column-1]!=not_hit)&&(base[row][column-1]!=ship_hit))
            {
                if(base[row][column-1]==ship)
                {
                    column--;
                    base[row][column]=ship_hit;
                    while(1)
                    {
                        if(smart_opponent_checker(row,column)==true)
                        {
                            game_menu();
                            column--;
                            base[row][column]=ship_hit;
                            Sleep(sleep_time);
                            game_menu();
                        }
                        else
                        {
                            turn=true;
                            start_game();
                        }
                    }
                    game_menu();
                    return false;
                }
                else
                {
                    base[row][column-1]=not_hit;
                    opponent_review[opponent_review_counter]=row;
                    opponent_review_counter++;
                    opponent_review[opponent_review_counter]=column;
                    opponent_review_counter++;
                }
                Sleep(sleep_time);
                game_menu();
            }
            else
                smart_opponent(row,column);
            break;
        case 2:
            if((base[row-1][column]!=not_hit)&&(base[row-1][column]!=ship_hit))
            {
                if(base[row-1][column]==ship)
                {
                    row--;
                    base[row][column]=ship_hit;
                    while(1)
                    {
                        if(smart_opponent_checker(row,column)==true)
                        {
                            game_menu();
                            row--;
                            base[row][column]=ship_hit;
                            Sleep(sleep_time);
                            game_menu();
                        }
                        else
                        {
                            turn=true;
                            start_game();
                        }
                    }
                    game_menu();
                    return false;
                }
                else
                {
                    base[row-1][column]=not_hit;
                    opponent_review[opponent_review_counter]=row;
                    opponent_review_counter++;
                    opponent_review[opponent_review_counter]=column;
                    opponent_review_counter++;
                }
                Sleep(sleep_time);
                game_menu();
            }
            else
                smart_opponent(row,column);
            break;
        case 3:
            if((base[row+1][column]!=not_hit)&&(base[row+1][column]!=ship_hit))
            {
                if(base[row+1][column]==ship)
                {
                    row++;
                    base[row][column]=ship_hit;
                    while(1)
                    {
                        if(smart_opponent_checker(row,column)==true)
                        {
                            game_menu();
                            row++;
                            base[row][column]=ship_hit;
                            Sleep(sleep_time);
                            game_menu();
                        }
                        else
                        {
                            turn=true;
                            start_game();
                        }
                    }
                    game_menu();
                    return false;
                }
                else
                {
                    base[row+1][column]=not_hit;
                    opponent_review[opponent_review_counter]=row;
                    opponent_review_counter++;
                    opponent_review[opponent_review_counter]=column;
                    opponent_review_counter++;
                }
                Sleep(sleep_time);
                game_menu();
            }
            else
                smart_opponent(row,column);
        }
        return true;
    }
    void opponent_remaining_process(int i,int j)
    {
        Sleep(sleep_time);
        base[i][j]=ship_hit;
        game_menu();
    }
    void opponent_remaining_cleaner()
    {
        for(int i=1;i<11;i++)
        {
            for(int j=4;j<12;j++)
            {
                if((base[i][j]!=water)&&(base[i][j-1]!=water)&&(base[i][j-2]!=water))
                {
                    if((base[i][j]==ship)&&(base[i][j-1]==ship)&&(base[i][j-2]==ship))
                        continue;
                    if((base[i][j]==ship_hit)&&(base[i][j-1]==ship_hit)&&(base[i][j-2]==ship_hit))
                        continue;
                    if((base[i][j]==ship)&&(base[i][j-1]==ship)&&(base[i][j-2]==ship_hit))
                    {
                        opponent_remaining_process(i,j-1);
                        opponent_remaining_process(i,j);
                    }
                    if((base[i][j]==ship)&&(base[i][j-1]==ship_hit)&&(base[i][j-2]==ship_hit))
                        opponent_remaining_process(i,j);
                    if((base[i][j]==ship_hit)&&(base[i][j-1]==ship_hit)&&(base[i][j-2]==ship))
                        opponent_remaining_process(i,j-2);
                    if((base[i][j]==ship_hit)&&(base[i][j-1]==ship)&&(base[i][j-2]==ship))
                    {
                        opponent_remaining_process(i,j-1);
                        opponent_remaining_process(i,j-2);
                    }
                }
            }
        }
        for(int i=3;i<11;i++)
        {
            for(int j=2;j<12;j++)
            {
                if((base[i][j]!=water)&&(base[i-1][j]!=water)&&(base[i-2][j]!=water))
                {
                    if((base[i][j]==ship)&&(base[i-1][j]==ship)&&(base[i-2][j]==ship))
                        continue;
                    if((base[i][j]==ship_hit)&&(base[i-1][j]==ship_hit)&&(base[i-2][j]==ship_hit))
                        continue;
                    if((base[i][j]==ship)&&(base[i-1][j]==ship)&&(base[i-2][j]==ship_hit))
                    {
                        opponent_remaining_process(i-1,j);
                        opponent_remaining_process(i,j);
                    }
                    if((base[i][j]==ship)&&(base[i-1][j]==ship_hit)&&(base[i-2][j]==ship_hit))
                        opponent_remaining_process(i,j);
                    if((base[i][j]==ship_hit)&&(base[i-1][j]==ship_hit)&&(base[i-2][j]==ship))
                        opponent_remaining_process(i-2,j);
                    if((base[i][j]==ship_hit)&&(base[i-1][j]==ship)&&(base[i-2][j]==ship))
                    {
                        opponent_remaining_process(i-1,j);
                        opponent_remaining_process(i-2,j);
                    }
                }
            }
        }
    }
    void opponent_turn()
    {
        if(opponent_rapide==false)
            sleep_time=1000;
        else
            sleep_time=0;
        Sleep(sleep_time);
        while(1)
        {
            static int counter=-2;
            if(counter+2<opponent_review_counter)
            {
                counter+=2;
                game_menu();
                if(smart_opponent(opponent_review[counter],opponent_review[counter+1])==true)
                    start_game();
            }
            opponent_remaining_cleaner();
            int column=rand()%10+2;
            int row=rand()%10+1;
            turn=false;
            for(int i=0;i<6;i++)
            {
                if(row==air_defence_place[i])
                {
                    base[row][0]=char(186);
                    base[row][1]=" ";
                    air_defence_place[i]=0;
                    turn=true;
                    start_game();
                }
            }
            if((base[row][column]==not_hit)||(base[row][column]==ship_hit))
                continue;
            game_menu();
            if(base[row][column]==water)
            {
                base[row][column]=not_hit;
                turn=true;
                start_game();
            }
            else
            {
                base[row][column]=ship_hit;
                if(smart_opponent_checker(row,column)==true)
                {
                    smart_opponent(row,column);
                    turn=true;
                    start_game();
                }
                else
                    continue;
            }
        }
    }
    void start_game()
    {
        endgame_checker();
        show_column=true;
        show_row=true;
        drown_checker_player();
        game_menu();
        if(just_AI==false)
        {
            hit_ship=false;
            cout<<"Use equipment or choose a block. (first number is column)\n\n ==> ";
            input=numchecker(0,10);
            switch(input)
            {
            case 0:
                use_cancel_changer();
                system("cls");
                game_menu();
                use_stuff();
                break;
            default:
                show_column=false;
                show_row=true;
                game_menu();
                cout<<"0)Cancel\n  column = "<<input<<"\n\n  Row = ";
                int row;
                row=numchecker(0,10);
                if(row==0)
                    start_game();
                if((opponent_base_visible[row][input+1]==not_hit)||(opponent_base_visible[row][input+1]==ship_hit))
                {
                    system("cls");
                    game_menu();
                    cout<<"You can not bomb a place twice!\n\n  ";
                    system("Pause");
                    start_game();
                }
                if(opponent_base_hidden[row][input+1]==ship)
                {
                    opponent_base_visible[row][input+1]=ship_hit;
                    drown_checker_opponent();
                    hit_ship=true;
                    start_game();
                }
                else
                    opponent_base_visible[row][input+1]=not_hit;
                drown_checker_opponent();
                game_menu();
                opponent_turn();
                start_game();
            }
        }
        else
        {
            while(1)
                opponent_turn();
        }
    }
    int drown_neighbor_checker_both(int i,int j,bool player_base)
    {
        int counter=0;
        if(player_base==false)
        {
            if(opponent_base_visible[i][j+1]==ship_hit)
                counter++;
            else if(opponent_base_hidden[i][j+1]==ship)
                counter=-10;
            if(opponent_base_visible[i][j-1]==ship_hit)
                counter++;
            else if(opponent_base_hidden[i][j-1]==ship)
                counter=-10;
            if(opponent_base_visible[i+1][j]==ship_hit)
                counter++;
            else if(opponent_base_hidden[i+1][j]==ship)
                counter=-10;
            if(opponent_base_visible[i-1][j]==ship_hit)
                counter++;
            else if(opponent_base_hidden[i-1][j]==ship)
                counter=-10;
        }
        else
        {
            if(base[i][j]!=ship_hit)
                return -10;
            if(base[i][j+1]==ship_hit)
                counter++;
            else if(base[i][j+1]==ship)
                counter=-10;
            if(base[i][j-1]==ship_hit)
                counter++;
            else if(base[i][j-1]==ship)
                counter=-10;
            if(base[i+1][j]==ship_hit)
                counter++;
            else if(base[i+1][j]==ship)
                counter=-10;
            if(base[i-1][j]==ship_hit)
                counter++;
            else if(base[i-1][j]==ship)
                counter=-10;
        }
        return counter;
    }
    void drown_radius_both(string ground[][14],int i,int j)
    {
        ground[i][j+1]=not_hit;
        ground[i+1][j+1]=not_hit;
        ground[i+1][j-1]=not_hit;
        ground[i+1][j]=not_hit;
        ground[i-1][j+1]=not_hit;
        ground[i-1][j-1]=not_hit;
        ground[i][j-1]=not_hit;
        ground[i-1][j]=not_hit;
        frame_maker(ground,false);
    }
    void drown_4block_both(string ground[][14],int first_i,int first_j,int secend_i,int secend_j)
    {
        if(secend_i==first_i)
        {
            drown_radius_both(ground,first_i,first_j);
            drown_radius_both(ground,secend_i,secend_j);
            drown_radius_both(ground,secend_i,secend_j+1);
            drown_radius_both(ground,secend_i,secend_j+2);
            ground[first_i][first_j]=ship_hit;
            ground[secend_i][secend_j]=ship_hit;
            ground[secend_i][secend_j+1]=ship_hit;
            ground[secend_i][secend_j+2]=ship_hit;
        }
        else
        {
            drown_radius_both(ground,first_i,first_j);
            drown_radius_both(ground,secend_i,secend_j);
            drown_radius_both(ground,secend_i+1,secend_j);
            drown_radius_both(ground,secend_i+2,secend_j);
            ground[first_i][first_j]=ship_hit;
            ground[secend_i][secend_j]=ship_hit;
            ground[secend_i+1][secend_j]=ship_hit;
            ground[secend_i+2][secend_j]=ship_hit;
        }
    }
    void drown_3or4_opponent(int first_i,int first_j,int secend_i,int secend_j)
    {
        if((opponent_base_visible[secend_i+2][secend_j]==ship_hit)&&(opponent_base_visible[secend_i+1][secend_j]==ship_hit))
            drown_4block_both(opponent_base_visible,first_i,first_j,secend_i,secend_j);
        else if((opponent_base_visible[secend_i][secend_j+2]==ship_hit)&&(opponent_base_visible[secend_i][secend_j+1]==ship_hit))
            drown_4block_both(opponent_base_visible,first_i,first_j,secend_i,secend_j);
        else if(((opponent_base_hidden[secend_i][secend_j+2]!=ship)&&(opponent_base_hidden[secend_i+1][secend_j]!=ship))||((secend_i!=10)&&(opponent_base_hidden[secend_i+2][secend_j]!=ship)&&(opponent_base_hidden[secend_i][secend_j+1]!=ship)))
        {
            drown_radius_both(opponent_base_visible,first_i,first_j);
            drown_radius_both(opponent_base_visible,secend_i,secend_j);
            if(secend_i==first_i)
                drown_radius_both(opponent_base_visible,secend_i,secend_j+1);
            else
                drown_radius_both(opponent_base_visible,secend_i+1,secend_j);
            opponent_base_visible[first_i][first_j]=ship_hit;
            opponent_base_visible[secend_i][secend_j]=ship_hit;
            if(secend_i==first_i)
                opponent_base_visible[secend_i][secend_j+1]=ship_hit;
            else
                opponent_base_visible[secend_i+1][secend_j]=ship_hit;
        }
    }
    void drown_2block_both(string ground[][14],int first_i,int first_j,int secend_i,int secend_j)
    {
        drown_radius_both(ground,first_i,first_j);
        drown_radius_both(ground,secend_i,secend_j);
        ground[first_i][first_j]=ship_hit;
        ground[secend_i][secend_j]=ship_hit;
    }
    void drown_checker_opponent()
    {
        for(int i=1;i<11;i++)
        {
            for(int j=2;j<12;j++)
            {
                if(opponent_base_visible[i][j]==ship_hit)
                {
                    int main_hit_i=i;
                    int main_hit_j=j;
                    switch(drown_neighbor_checker_both(i,j,false))
                    {
                    case 0://1ta
                        drown_radius_both(opponent_base_visible,i,j);
                        break;
                    case 1://else
                        if((opponent_base_visible[i+1][j]==ship_hit)&&(i!=10))
                        {
                            if(opponent_base_visible[i+2][j]==ship_hit)
                                drown_3or4_opponent(main_hit_i,main_hit_j,i+1,j);
                        }
                        if((opponent_base_visible[i][j+2]==ship_hit)&&(opponent_base_visible[i][j+1]==ship_hit))
                            drown_3or4_opponent(main_hit_i,main_hit_j,i,j+1);
                        if(((opponent_base_hidden[i][j+2]!=ship)&&(opponent_base_hidden[i][j-1]!=ship)&&(opponent_base_hidden[i][j+1]==ship))
                           ||((opponent_base_hidden[i+2][j]!=ship)&&(opponent_base_hidden[i-1][j]!=ship)&&(opponent_base_hidden[i+1][j]==ship)))
                        {
                            if(opponent_base_visible[i][j+1]==ship_hit)
                                drown_2block_both(opponent_base_visible,i,j+1,main_hit_i,main_hit_j);
                            else if(opponent_base_visible[i+1][j]==ship_hit)
                                drown_2block_both(opponent_base_visible,i+1,j,main_hit_i,main_hit_j);
                        }
                    }
                }
            }
        }
    }
    void drown_3block_player(int first_i,int first_j,int secend_i)
    {
        if(first_i==secend_i)
        {
            drown_radius_both(base,first_i,first_j);
            drown_radius_both(base,first_i,first_j+1);
            drown_radius_both(base,first_i,first_j+2);
            base[first_i][first_j]=ship_hit;
            base[first_i][first_j+1]=ship_hit;
            base[first_i][first_j+2]=ship_hit;
        }
        else
        {
            drown_radius_both(base,first_i,first_j);
            drown_radius_both(base,first_i+1,first_j);
            drown_radius_both(base,first_i+2,first_j);
            base[first_i][first_j]=ship_hit;
            base[first_i+1][first_j]=ship_hit;
            base[first_i+2][first_j]=ship_hit;
        }
    }
    void drown_checker_player()
    {
        for(int i=1;i<11;i++)
        {
            for(int j=2;j<12;j++)
            {
                if(base[i][j]==ship_hit)
                {
                    if(drown_neighbor_checker_both(i,j,true)==0)
                    {
                        drown_radius_both(base,i,j);
                        base[i][j]=ship_hit;
                    }
                    else if(drown_neighbor_checker_both(i,j,true)==1)
                    {
                        if(drown_neighbor_checker_both(i+1,j,true)==1)
                            drown_2block_both(base,i,j,i+1,j);
                        if(drown_neighbor_checker_both(i,j+1,true)==1)
                            drown_2block_both(base,i,j,i,j+1);
                        if(drown_neighbor_checker_both(i+1,j,true)==2)
                        {
                            if(drown_neighbor_checker_both(i+2,j,true)==1)
                                drown_3block_player(i,j,i+1);
                            else if(drown_neighbor_checker_both(i+2,j,true)==2)
                                drown_4block_both(base,i,j,i+1,j);
                        }
                        if(drown_neighbor_checker_both(i,j+1,true)==2)
                        {
                            if(drown_neighbor_checker_both(i,j+2,true)==1)
                                drown_3block_player(i,j,i);
                            else if(drown_neighbor_checker_both(i,j+2,true)==2)
                                drown_4block_both(base,i,j,i,j+1);
                        }
                    }
                }
            }
        }
    }
    void endgame_screen(bool player_won,int round)
    {
        system("cls");
        sea_battle_intro(true);
        cout<<" "<<char(218);
        for(int i=0;i<88;i++)
            cout<<char(196);
        cout<<char(191);
        cout<<endl<<" "<<char(179);
        for(int i=0;i<11;i++)
            cout<<"\t";
        cout<<"  "<<char(179);
        cout<<"\n "<<char(179)<<"      Your Base :\t\t\t\t\t   Opponent Base :\t\t";
        cout<<"  "<<char(179)<<endl;
        for(int i=0;i<12;i++)
        {
            if((i<=10)&&(i>=1))
                cout<<" "<<char(179)<<"   "<<setw(2)<<setfill(' ')<<i<<" ";
            else
                cout<<" "<<char(179)<<"      ";
            for(int j=0;j<14;j++)
                cout<<base[i][j];
            if(i!=9)
                cout<<"\t";
            switch(i)
            {
            case 1:
                cout<<"  __    __";
                break;
            case 2:
                cout<<" /\     /";
                break;
            case 3:
                cout<<"|  _  |  _";
                break;
            case 4:
                cout<<" \\ _|  \\ _|";
                break;
            case 7:
                if(player_won==true)
                    cout<<"  You Won!    ";
                else
                    cout<<"  You Lost!   ";
                break;
            case 9:
                cout<<"     Round played : "<<round;
                break;
            default:
                cout<<"     \t";
            }
            cout<<"\t   ";
            for(int j=0;j<14;j++)
            {
                if(opponent_base_visible[i][j]==not_hit&&opponent_base_hidden[i][j]==ship)
                    cout<<ship;
                else
                    cout<<opponent_base_visible[i][j];
            }
            if((i<=10)&&(i>=1))//Ali Sadeghi
                cout<<left<<" "<<setw(2)<<setfill(' ')<<i;
            cout<<right<<"\t  "<<char(179)<<endl;
        }
        cout<<" "<<char(179)<<"\t  ";
        for(int i=10;i>0;i--)
            cout<<setw(2)<<setfill(' ')<<i;
        cout<<"\t\t\t\t    ";
        if(show_row==true)
        {
            for(int i=1;i<10;i++)
                cout<<setw(2)<<setfill(' ')<<i;
            cout<<" 10\t  ";
        }
        else
            cout<<"\t\t\t\t  ";
        cout<<char(179)<<endl<<" "<<char(179);
        for(int i=0;i<11;i++)
            cout<<"\t";
        cout<<"  "<<char(179)<<endl<<" "<<char(192);
        for(int i=0;i<88;i++)
            cout<<char(196);
        cout<<char(217)<<"\n  Thanks for playing <3\n\n  ";
        system("Pause");
        exit(0);
    }
    void endgame_checker()
    {
        static int round=0;
        round++;
        int found_opponent_ship=0;
        int found_player_ship=0;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<14;j++)
            {
                if((opponent_base_hidden[i][j]==ship)&&(opponent_base_visible[i][j]!=ship_hit))
                    found_opponent_ship++;
                if(base[i][j]==ship)
                    found_player_ship++;
            }
        }
        if(found_opponent_ship==0)
            endgame_screen(true,round);
        if(found_player_ship==0)
            endgame_screen(false,round);
    }
};
int main()
{
    Sea_Battle sb;
    sb.set_main_data();
    sb.choose_base();
    sb.buy_stuff();
    sb.start_game();
}
