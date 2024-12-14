#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// 철수의 가방
vector<string> player_bag;

// 아트록스의 정보
const int ATROX_HEALTH = 100;
const int ATROX_ATTACK = 15;

// 아무무의 정보
const int AMUMU_HEALTH = 150;
const int AMUMU_ATTACK = 20;

// 히든 던전 관련 변수
bool hidden_dungeon_unlocked = false;
bool amumu_boss_unlocked = false;
int monster_defeat_count = 0; // 물리친 몬스터 수

// 플레이어(철수)의 체력과 공격력
int player_health = 100;
int player_attack = 10;

// 플레이어 레벨링 관련 변수
int player_level = 1;
int player_exp = 0;
int next_level_exp = 100; // 다음 레벨까지 필요한 경험치

// 아이템의 ASCII 아트 함수들
void DisplayAxeArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡀⠀⠀⠀⠀⠀⣀⢔⢊⠇⡺⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⢋⢛⠝⢌⠎⡆⠆⠖⡊⠍⢔⢐⠔⠱⠘⡼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢐⢐⠌⡂⢅⠌⡌⢌⠢⢑⠰⠕⢌⢊⠠⢮⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢐⢐⠡⡨⠂⢅⠪⡐⠌⡂⢅⠅⡃⡢⠐⣣⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⢴⢥⢬⢲⢹⣪⠃⠃⠓⠘⠴⢌⡢⡘⣠⡳⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡪⡎⡎⣎⢺⠀⠀⠀⠀⠀⠀⠈⠒⡵⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡪⡪⡪⡞⡼⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡹⣜⢜⢎⠮⣺⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡺⡜⡕⣕⢝⢼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡽⡸⡸⣸⢜⢼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡗⡕⡝⡜⡜⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡗⣵⢱⢱⣹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣏⢎⢎⢧⠺⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⡎⣎⢮⢪⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡪⡪⡪⡪⣳⠀⠀⠀⠀⠀⠀⠀⠀                          " << endl;
}//피묻은 도끼

void DisplayArmorArt() {
    cout << "   _________   " << endl;
    cout << "  |  ____  |  " << endl;
    cout << "  | |    | |  " << endl;
    cout << "  | |    | |  " << endl;
    cout << "  | |    | |  " << endl;
    cout << "  | |____| |  " << endl;
    cout << "  |________|  " << endl;
}//천갑옷

void DisplayArmor2Art() {
    cout << "⣞⣾⣲⣗⣷⣺⣞⣶⣳⣗⣾⣺⣖⣷⣳⡖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣗⣷⣺⣞⣶⣳⣗⣾⣺⣖⣷⣳⣞⣾⣲" << endl;
    cout << "⣷⣳⣟⠞⠞⠗⠟⠞⠗⠟⠞⢗⢟⣞⡷⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⢾⣺⠗⠟⠞⠗⠟⠞⠗⠟⢞⢗⣟⣞⣗" << endl;
    cout << "⣞⣷⣻⠄⠀⠀⠀⠂⠐⠨⡈⡢⢸⡯⣯⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣻⣽⡃⠀⠀⠀⡐⠠⢈⠊⠔⢰⢯⡷⣯" << endl;
    cout << "⣷⣳⢿⠠⠀⠄⢐⠡⢊⢐⢐⠄⢕⠍⡇⡫⣶⢶⣖⠀⠀⠀⠀⠀⠀⣖⣶⣲⡪⢣⠹⡀⠄⠠⢐⠠⢂⢂⠅⠅⢕⡿⣽⣳" << endl;
    cout << "⣗⣯⢿⡁⡐⢈⢐⠨⡐⡐⠔⡈⡢⠣⠱⠩⢯⢟⢞⣀⣀⣀⣀⣀⡀⡗⡿⡺⡪⢊⠎⡂⡐⡀⡐⠌⡂⠢⠨⡨⢒⣟⡷⡯" << endl;
    cout << "⣗⡿⣽⡂⡊⡐⡐⡐⠔⡈⡂⡂⡂⠐⡀⠌⡪⢢⠣⣟⡾⣾⣺⢾⣽⢸⢐⠕⢌⠐⢌⢐⢐⠐⠌⠢⠨⡨⠨⡐⢸⣺⡽⣯" << endl;
    cout << "⣷⣻⣽⡢⡲⡨⡢⡊⢆⠆⡊⡐⠄⠁⠀⠀⡑⠁⡑⠉⠍⠃⠋⠙⠘⠌⡊⠜⡠⢑⢐⠔⡐⠡⡑⡅⡣⡢⡱⢬⢸⣞⣯⢷" << endl;
    cout << "⣗⣟⣾⡪⡪⡪⡪⡸⡨⡢⢂⠊⠄⠀⠀⠀⡀⠂⠠⠈⠠⠈⠠⠁⡈⠢⡈⡢⠨⡐⡐⡐⠌⠌⢔⢱⢑⢜⢜⢜⢼⣺⡽⣯" << endl;
    cout << "⣿⣽⢷⣿⢿⡿⣇⢇⢇⠇⠀⠄⠁⠄⠂⠐⢀⠈⠠⠡⠡⡡⠡⡑⢄⢑⢐⠄⠕⡐⡐⠌⠌⠌⢜⢜⢜⢼⣿⢿⣻⣯⣿⢷⠀" << endl;
    cout << "⠓⠛⠛⠙⠛⠛⢣⣧⣧⡇⠐⠈⡀⠂⡈⢐⠠⠨⠠⠡⡑⢄⢑⢐⢐⢐⠔⡈⡂⡢⠨⠨⠨⢊⢸⣼⣼⡜⠛⠛⠛⠙⠚⠛⠀" << endl;
    cout << "         ⢸⣯⣷⡇⠠⠁⡀⠂⡀⠂⢌⠌⢌⠌⠔⡐⡐⡐⡁⡂⡢⢂⠢⢂⠅⠕⠡⡁⢺⣿⣽⡇⠀⠀" << endl;
    cout << "         ⢸⣿⣽⡇⠌⡂⡂⠐⡀⠌⡂⢌⠢⡈⡂⡢⢊⢐⢐⠔⡐⡐⠡⢂⠊⢌⢇⠕⢽⡷⣟⡇⠀⠀⠀" << endl;
    cout << "         ⢸⣷⣟⡇⠌⠔⡠⢁⠠⢐⠠⠡⢂⢂⠢⢂⠢⢂⢂⠢⢂⢊⠌⡂⠅⢕⢜⢸⢸⣿⢿⡇⠀⠀" << endl;
    cout << "         ⢸⡿⣾⡇⢅⢑⠐⠄⠕⡠⠡⡡⠡⢂⠑⢄⢑⢐⢐⠡⢂⢂⢂⢊⠌⢢⢱⢘⢼⣿⣻⡇⠀⠀⠀" << endl;
    cout << "         ⢸⣿⣻⡇⡲⡰⡡⢑⠡⢂⠑⢄⢑⢐⠡⡁⡂⡢⢁⠊⠔⡐⡱⢰⢘⢌⢆⢣⢹⣾⣟⡇⠀⠀⠀⠀" << endl;
    cout << "         ⢸⣯⣿⡇⡕⡜⡄⡅⡊⡄⡅⢅⡂⡢⣁⢂⢢⢂⢅⢊⢌⡐⢜⢌⢎⢢⢣⡑⢽⣯⡿⡇⠀⠀⠀" << endl;
    cout << "         ⢸⡿⣾⡇⡇⡇⡇⢎⠪⡂⡇⡣⡊⢎⢢⠣⡱⡸⢰⢑⢕⢸⢨⢢⠱⣑⢕⡪⢽⣷⢿⡇⠀⠀⠀" << endl;
    cout << "         ⠈⠉⠉⢱⣷⡷⡗⡕⡕⡕⡱⡘⡜⡸⢰⢑⠕⡜⢌⢆⢣⢱⢸⢰⢱⢺⣞⣾⡎⠉⠉⠁⠀⠀⠀⠀" << endl;
    cout << "              ⠸⠷⠿⣏⣎⣎⢎⣪⢸⡨⣊⢎⣢⢣⡱⣡⢣⡱⣘⡜⣜⣜⡺⠿⡽⠇⠀⠀⠀⠀⠀⠀" << endl;
}//가죽갑옷

void DisplayPotionArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡜⡛⡻⡤⡤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⠩⢌⡪⡪⡒⠄⠈⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⡵⡕⡵⡹⡪⠂⡀⠌⡛⠛⠛⠛⡤⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢯⡨⠨⠈⠄⡡⠀⠂⠀⠀⠀⠀⠀⠈⠱⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⣵⠱⡠⢁⠡⡈⡀⡂⡀⡀⡀⠀⢀⠓⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢀⢵⡲⣝⢮⢯⡺⣝⢞⡖⣆⠁⠖⣎⡱⣂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⢐⢯⣯⣺⢕⣗⣝⢮⡳⣝⢮⡳⡥⢪⣣⠚⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢗⡸⢾⢽⡯⣷⢿⡽⣽⢽⡽⣽⡺⣝⢮⠅⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢣⡋⡯⣟⣯⣿⡽⣯⣟⡾⣝⣗⠇⣽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠮⡹⠺⣞⣯⡷⣟⠾⢝⡢⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "                                                                   " << endl;
}//빨간 포션

void DisplaySwordArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢔⢀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⢢⢂⠂⠄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⡇⢅⠂⠄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⡘⡠⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⡱⡐⡐⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠨⠐⠄⠂⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠡⠡⡀⠂⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠂⠅⢄⠈⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⢂⠅⢄⠠⢀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢌⢪⢐⢀⢂⢀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢌⡒⢔⢀⠂⢄⢔⠕⡑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢌⢆⠮⡑⢅⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢔⠕⡡⣪⡪⣚⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠣⠑⠀⠀⠈⠹⣪⡲⡱⡠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⢜⠌⡑⡄⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⡀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
}//날카로운 철검

void DisplayMaceArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢤⢴⣞⡞⡖⣆⡀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⢾⢪⢣⣳⢵⢺⡪⡧⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⣜⣮⢜⣼⢵⡳⡕⣗⢽⠊⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣪⢿⡫⣎⡣⣣⢳⡝⣟⢮⠊⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡔⡯⣪⢧⡷⣳⠻⡕⣟⢞⠕⠅⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡪⣞⡜⡎⡧⡳⡱⡱⣍⠮⠓⠁⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢜⢮⡫⣪⢺⠼⢼⢺⢏⠇⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⣎⡞⡕⣝⡲⡕⡟⠬⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⡎⡏⣎⢮⢞⢕⢕⠕⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢤⣳⢵⡫⣚⢮⢱⡱⠑⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢺⡸⡪⡳⡱⣱⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢴⡹⢜⢜⢌⡎⡎⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⢱⢣⢣⢱⢱⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⣎⠧⣳⢵⢱⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⣎⠧⢱⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢱⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠱⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
}//야만의 몽둥이

// 미노타우르스의 ASCII 아트를 출력하는 함수
void DisplayMinotaurArt() {
    cout << "       __     __         " << endl;
    cout << "      /  \\~~~/  \\       " << endl;
    cout << "    ,----(     )----.    " << endl;
    cout << "   /      \\_^_/      \\  " << endl;
    cout << "  |        | |        |  " << endl;
    cout << "   \\    __/   \\__    /  " << endl;
    cout << "    '--/         \\--'   " << endl;
    cout << "      |  AXE!!!   |      " << endl;
    cout << "      \\___________/      " << endl;
}

// 멧돼지의 ASCII 아트를 출력하는 함수
void DisplayBoarArt() {
    cout << "      /\\   ___   /\\     " << endl;
    cout << "     //\\\\ (o o) //\\\\   " << endl;
    cout << "    ||   \\\\_^_//   ||   " << endl;
    cout << "     \\\\    '-'    //    " << endl;
    cout << "      '-.........-'      " << endl;
}

// 보물상자의 ASCII 아트를 출력하는 함수
void DisplayTreasureArt() {
    cout << "      ___________       " << endl;
    cout << "     /           \\      " << endl;
    cout << "    / $$$$$$$$$$  \\     " << endl;
    cout << "   | $$$$$$$$$$$$ |     " << endl;
    cout << "   | $$$$$$$$$$$$ |     " << endl;
    cout << "    \\_____[T]____/      " << endl;
}

// 해골전사의 ASCII 아트를 출력하는 함수
void DisplaySkeletonWarriorArt() {
    cout << "      .-.          " << endl;
    cout << "     (o.o)         " << endl;
    cout << "      |=|          " << endl;
    cout << "     __|__         " << endl;
    cout << "   //.=|=.\\\\       " << endl;
    cout << "  // .=|=. \\\\      " << endl;
    cout << "  \\\\ .=|=. //      " << endl;
    cout << "   \\\\(_=_)//       " << endl;
    cout << "    (:| |:)        " << endl;
    cout << "     || ||         " << endl;
    cout << "     () ()         " << endl;
}

// 마녀의 ASCII 아트를 출력하는 함수
void DisplayWitchArt() {
    cout << "        ______        " << endl;
    cout << "     .-'      `-.     " << endl;
    cout << "    /    .--.    \\    " << endl;
    cout << "   /  _.-'    '-._\\   " << endl;
    cout << "   | (_ o      o _) | " << endl;
    cout << "    \\   '._.--._.'  / " << endl;
    cout << "     '-.          .-'  " << endl;
    cout << "        `--------`     " << endl;
}

// 고블린 전사의 ASCII 아트를 출력하는 함수
void DisplayGoblinWarriorArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\_______/    " << endl;
    cout << "     //   \\\\     " << endl;
    cout << "    ||     ||    " << endl;
}

// 고블린 궁수의 ASCII 아트를 출력하는 함수
void DisplayGoblinArcherArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\--| |--/    " << endl;
    cout << "       | |       " << endl;
}

// 고블린 마법사의 ASCII 아트를 출력하는 함수
void DisplayGoblinMageArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\_-===-_/    " << endl;
    cout << "     /     \\     " << endl;
}

// 대악마 아트록스의 ASCII 아트를 출력하는 함수
void DisplayAtroxArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡛⢲⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠼⠙⢧⣦⣀⢀⠠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⢤⡴⡶⣟⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣷⣫⡟⡿⣽⠀⠀⠀⢀⠀⠀⡀⠀⠀⠀⢹⡾⡻⡮⣯⡳⣿⣦⡤⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⡦⣴⢾⣳⡷⡵⡽⣹⡄⠀⣐⡇⢀⢾⡀⠀⠀⢀⡿⡵⣫⡿⣳⡻⣗⣯⡃⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠈⠀⠈⣿⣪⡯⣻⡻⣮⣻⢪⣳⡗⣮⡫⣶⣂⣤⣾⣽⣻⣽⣹⣗⡿⡾⣽⣾⠖⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⡶⠺⣯⢯⢿⢝⣯⣗⣷⢽⢷⡿⣼⡹⣽⣟⣞⣗⡿⣽⢾⢗⣷⢽⡼⣷⠃⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠁⠀⣿⣼⣳⣟⢷⢯⠏⠩⢻⢧⡿⣞⡷⣯⣯⣿⠍⢫⡯⣟⢾⢯⢟⣿⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡾⣿⡪⢯⡏⠀⠀⠺⣳⡯⣺⢾⡷⣿⠁⠀⠸⡽⡨⣺⡳⡯⡎⡂⠀⣀⢧⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⡿⣽⡻⡮⣻⠆⠀⠀⠀⡯⣯⢿⣽⣿⠅⠀⠀⠀⢹⢝⡷⡽⣝⡿⡜⢯⠋⠃⡌⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢈⣯⢷⢹⡽⣾⠀⠀⠀⠀⣽⢯⣿⣳⣿⣅⠀⠀⠀⣾⣫⢯⡸⣝⢮⡍⣒⢮⢻⠸⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣝⡮⣿⠽⡀⠀⢠⣻⡽⣯⣟⡞⡷⡽⡇⠀⠀⣿⡺⣯⢳⡽⡝⡙⠈⡪⢴⢜⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⣷⣟⡎⠀⠀⢠⡳⣷⣻⣯⠟⠳⣯⣻⡂⠀⠀⢹⣯⣿⢽⡼⡏⠨⡪⠫⢊⢦⠌⡂⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣷⠀⠀⣮⣿⣽⡾⠁⠀⠀⢼⡺⠀⠀⠀⠀⢻⠸⣟⣯⡇⠀⠉⢜⠙⢨⢢⡬⡆⢅⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⣟⢾⢮⠀⠀⠀⠀⡢⣿⠀⠀⠀⠀⠀⠀⠙⢯⡇⠀⠀⢑⠔⠽⣪⢫⣇⡀⢀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠘⡽⣝⣗⠀⠀⠀⠪⠞⠀⠀⠀⠀⠀⠀⠀⠈⠇⠀⠀⠀⠁⠈⢜⢧⢳⢕⡔⡀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠗⡷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡐⢭⣳⢝⣮⠰⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣳⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠅⡫⣎⢎⡇⠄⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠈⠪⠌⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "대악마 아트록스가 당신을 노려봅니다. 그의 존재만으로도 공기가 무겁습니다!\n";
}

//다르킨의 검의 ASCII 아트를0 출력하는 함수
void DisplayDarkinSwordArt(){
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⡣⡃⡆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢪⢪⢪⠪⡸⡰⢱⢑⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢜⢜⢜⢜⡐⢌⠔⢌⡪⡪⢢⢃⢇⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⢇⢇⢇⢗⡪⢦⡱⡱⡱⡪⡢⡣⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⠢⢌⠜⡰⡱⡕⣝⢕⢧⣣⠓⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢢⡺⡮⣎⢮⡳⣝⢵⡢⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⢣⢣⡫⡪⡣⡫⡪⣳⠝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⢣⡺⡼⣜⢮⢝⡮⣲⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⢜⢮⢺⢸⡱⡝⢮⠞⠀⠀⢀⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠈⠑⢣⡣⡣⣣⢳⢹⢜⢦⢄⡠⡳⣕⢽⢕⢦⢄⠀⠀⢤⡫⣖⢤⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡔⡵⡱⡳⡱⡸⡱⡝⡎⡎⢎⢋⢇⡣⡣⡱⡸⡘⡌⣇⡣⡣⡣⡣⣇⢯⡪⡣⡣⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⡀⣄⠀⠀⢀⢔⢧⢳⡱⡙⡔⡑⡌⡪⣪⡸⡰⡱⣱⢳⢥⡣⡣⡱⡸⡘⡌⣇⡣⡣⡣⡣⣇⢯⡪⡣⡣⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⡠⡣⣫⢪⣓⢕⢕⠕⡕⣱⢕⣕⢕⢜⣜⢮⡪⡺⡪⡪⣇⢗⡝⡮⢮⡪⡪⡺⣕⢝⢮⢪⢺⢪⡣⡫⡪⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠠⢑⠹⢸⢸⠬⡳⣕⢕⢝⢼⡱⡕⣇⢇⢗⢕⢝⠐⠄⠅⠣⡊⡐⠠⢁⢊⢜⡁⠀⠀⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠑⠐⢅⠋⢎⢎⠎⠊⠆⡇⠧⠁⠀⠑⡱⡢⡨⠠⢡⢪⢪⢢⢣⠰⡪⡪⡪⢕⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠁⠣⠁⠀⠀⠀⠈⠀⠀⠀⠢⢣⢣⠫⢋⢈⠊⠎⡎⢂⠐⠄⡑⡍⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⢡⣑⠐⡠⢈⡢⡣⡢⣊⢐⡔⡵⡱⡢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⡸⡰⡹⡔⠂⢇⢇⢇⠎⢐⠈⠎⢎⠖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠨⢪⠊⠄⡑⢐⢐⢅⢆⠡⡈⡢⡣⡢⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢆⢏⢦⢢⠡⡣⡣⡣⡓⠌⡚⢜⢎⢎⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠅⡣⢣⠣⢑⠈⠌⡘⡜⡠⢁⠂⡂⡜⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡑⡬⣐⠨⢐⢜⢜⢜⢔⠔⡜⡎⣎⢎⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⢣⢣⢣⠫⢈⠪⠪⡪⢊⢐⠠⢁⠣⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠡⡃⠌⡐⡈⢔⢕⢅⢆⠌⡄⣏⢕⢆⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡎⣎⢳⡰⠨⢪⢪⢪⠪⠨⢘⠸⢜⠜⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠜⡰⠕⡁⠅⠢⡈⡎⡌⢌⢐⢐⢰⢅⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⡅⡌⢂⠡⢨⢪⢲⢰⠠⡡⡪⡲⡱⡱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢱⢱⡱⡕⡌⠪⡪⡪⡪⢊⢨⠑⠣⡣⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠡⢃⢇⠃⠄⠅⡂⢥⢱⢐⠈⠌⡂⡖⡤⣀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢒⢥⢡⠨⡰⡱⡱⡱⡱⡡⣣⢣⢣⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢜⢜⢜⢜⢜⢬⢪⠪⢎⢎⢮⢺⢸⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠈⠘⢜⢪⢪⡪⡝⡜⡎⣎⢎⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠌⠪⡪⡪⡪⡪⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
}


// 슬픈 미라 아무무의 ASCII 아트를 출력하는 함수
void DisplayAmumuArt() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⢟⢵⣵⣧⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣵⣽⣛⢟⢟⢟⢟⡟⣟⢟⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⢿⡻⡿⣵⣵⣵⣵⣵⢝⢼⢸⢜⢎⢞⢜⢎⡟⣟⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⢟⡕⣇⢗⢝⢎⢗⢝⢎⡏⣿⡻⣟⢿⡻⣵⣽⣼⣮⣮⣮⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣟⢿⣻⣻⡻⣟⣵⣽⣼⣵⢕⡕⣕⢵⢱⡹⡪⡳⡹⣚⢎⢗⢝⢮⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡕⣎⢮⢲⢪⡪⡪⣎⢗⢝⢮⡻⣟⣟⢿⡻⣮⣮⣷⣽⣼⣼⢕⡝⣜⢜⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣟⣟⣟⣟⢿⡻⣮⣧⣧⣷⣽⢜⢜⢆⢧⢣⡳⡹⣚⡺⡚⣎⢗⣟⣟⣟⢿⡻⣤⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡲⡱⣒⢎⢮⢪⡳⡹⣚⡺⡪⣟⢿⡻⣟⢿⡻⣵⣵⣵⣽⣼⣼⢔⢖⢕⣕⢭⣿⣤⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣟⢿⣻⡻⣵⠓⠀⠠⠀⠚⡜⣎⢮⢺⢸⢪⡪⡳⠙⠀⢀⠀⠋⡿⣻⢟⣟⢟⣿⡪⣿⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡪⡲⡹⢘⠐⠈⢀⠐⠠⣻⢟⣮⣮⣧⣧⣷⣽⢀⠈⡀⠀⠅⡃⡗⣕⢕⣿⠛⣮⢇⣟⣤⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣵⣽⣮⠂⠌⠌⡐⠨⠐⣕⢵⢹⡪⡳⡹⣚⢎⢂⠂⡂⠅⠡⡀⣧⣧⣷⣿⠀⠀⠛⣶⠛⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡳⡹⡹⢤⢅⢆⢥⢻⣮⣮⣧⣧⣯⣾⣼⡪⡳⡰⡠⡥⢅⢯⢺⡱⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣷⣽⣼⣵⣵⢕⢇⢗⡕⣏⢮⢳⢹⡚⣎⢿⡻⣟⢵⡻⣧⣷⣵⣽⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⠀⠀⠛⣷⢝⢮⣳⡻⣟⣟⣟⢿⣵⣵⣵⣵⣵⣵⣕⢧⡫⡮⣷⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣵⡕⣟⣤⣤⣤⠛⠛⣮⣾⣮⣶⣷⣵⣷⣽⣮⣷⣽⣮⣿⣿⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣮⣮⣮⢮⢻⣤⢿⣵⣵⣵⣦⢇⡖⡕⡎⡖⡕⣕⢕⢟⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣿⡪⡎⡞⡎⡗⡝⣟⣟⢿⡻⣟⣵⣵⣽⣼⣮⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡳⣻⡻⣿⢿⣵⣽⣶⣮⣮⢎⢮⡪⡳...\n";
    cout << "슬픈 미라 아무무가 당신을 바라보며 흐느낍니다...\n";
}

// 사망 메시지 출력 함수
void DisplayDieArt() {
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□■□□□□□□□□" << endl;
    cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□" << endl;
    cout << "■■□□□■■■■■■■■□■□□□□■□□□□□■■■■■■□■□□■■■■■■" << endl;
    cout << "■■□□■■□■■□□■■□■□□□□■□□□□□■■□□■■□■□□■■□□■■" << endl;
    cout << "□■□□■■□■□□□□■□■□□□□■□□□□□■□□□□■□■□□■□□□□■" << endl;
    cout << "□■■□■□□■□□□□■□■□□□□■□□□□□■□□□□■□■□□■■■■■■" << endl;
    cout << "□■■■■□□■□□□□■□■□□□□■□□□□□■□□□□■□■□□■□□□□□" << endl;
    cout << "□□■■■□□■■□□■■□■■□□■■□□□□□■■□□■■□■□□■■□□□■" << endl;
    cout << "□□■■□□□■■■■■■□■■■■■■□□□□□■■■■■■□■□□■■■■■■" << endl;
    cout << "□□■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
    cout << "□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□" << endl;
}

// 소개 스토리를 출력하는 함수
void DisplayIntro() {
    cout << "□■■■■■■□□□■□□■■■■■■■□□■□□□□■□□□□■□■□□□□□■□□□□□■□□□□□□□□■□□□□■□□□□□□■■□□□□■□□□■□□□□□□□■□□□□□□□□□□□□■" << endl;
    cout << "□■■■■■■□□□■□□■■■■■■■□□■□□■■■■■□□■□■□□□□□■□□□□□■□□□□□□□□■□□□□■□□□□■■■■■■□□■□□□■□□□□□□□■□□□■■■■■■□□□■" << endl;
    cout << "□■□□□□□□□□■□□□□□■□□□□□■□□■■□■■□□■□■□□□□□■□□□□□■□□□□□□□■■□□□□■■■□□■■□□■■□□■□□□■□□□□□□□■■■□□□□□□■□□□■" << endl;
    cout << "□■□□□□■■■■■□□□□■■□□■■■■□□■□□□■□□■□■□□□□□■□■■■■■□□□□□□■■■■■□□■□□□□■□□□□■□□■□□□■□□□□□□□■□□□□□□□■■□□□■" << endl;
    cout << "□■□□□□□□□□■□□□■■■■□□□□■□□■□□□■■■■□■□□□□■■□■■■■■□□□□□■■■□■■■□■□□□□■□□□□■□□■■■■■■■■■■■□■□□□□□□□■■□□□■" << endl;
    cout << "□■■■■■■■■□■□□■■■□■■■□□■□□■□□□■■■■□■□□□□■■■□□□□■□□□□■■□□□□■■□■□□□□■□□□□■□□■■■■■■■□□□□□■□□□□□□□■■□□□■" << endl;
    cout << "□■■■■■■■□□■□■■■□□□■■□□■□□■□□□■□□■□■□□□■■■■■□□□■□□□□□□■■■■■■■■□□□□■□□□□■□□■□□□□□□□□□□□■□□□□□□■■□□□□■" << endl;
    cout << "□□□■□□□□□□■□□□□■□□□□□□■□□■■□■■□□■□■□□■■□□■■■□□■□□□□□□□□□□□□□■□□□□■■□□■■□□■□□□□■■■■■■■■□□□□■■■□□□□□■" << endl;
    cout << "□□□■□□□□□□■□□□□■□□□□□□■□□■■■■■□□■□■□■■□□□□■■□□■□□□□□□□□□□□□□■□□□□■■■■■■□□■□□□□■■□□□□□■□□□■■■□□□□□□■" << endl;
    cout << "□□□■□□□□□□□□□□□■□□□□□□□□□□□□□□□□■□■□□□□□□□□□□□■□□□□□□□■■■■■■■□□□□□□□□□□□□■□□□□■■□□□□□■□□□■□□□□□□□□■" << endl;
    cout << "□□□■□□□□□□□□□□□■□□□□□□□□□□□□□□□□■□■□□□□□□□□□□□■□□□□□□□■□□□□□□□□□□□□□□□□□□■□□□□■■□□□□□■□□□□□□□□□□□□■" << endl;
    cout << "□□□■■■■■■■■□□□□■■■■■■■■□□□□□□□□□■□■□□□□□□□□□□□■□□□□□□□■■■■■■■■□□□□□□□□□□□■□□□□■■■■■■■■□□□□□□□□□□□□■" << endl;
    cout << "        zZZ...        " << endl;
    cout << "      .-''''''''-.    " << endl;
    cout << "    .'            '.  " << endl;
    cout << "   /                \\ " << endl;
    cout << "  |   ~~~      ~~~   |" << endl;
    cout << "  |   -            - |" << endl;
    cout << "  |      '.___.'     |" << endl;
    cout << "   \\                / " << endl;
    cout << "    '.            .'  " << endl;
    cout << "      '-........-'" << endl;
    cout << "한밤중, 코딩에 집중하던 철수는 졸음에 못 이겨 그만 책상에 고꾸라져 잠이 들고 말았습니다.\n";
    cout << "얼마나 시간이 흘렀을까, 깨달아 보니 낯선 돌바닥 위. 주변은 차갑고 축축한 공기로 가득 찼습니다.\n";
    cout << "눈앞엔 고대 유적 같은 돌기둥들이 우뚝 서 있고, 어둠 속에서 흐릿한 불빛이 깜박입니다.\n";
    cout << "‘여긴... 어디지?’ 철수는 아찔한 느낌에 사로잡혔습니다. 뒤를 돌아보니 더는 돌아갈 길이 없었습니다.\n";
    cout << "갑자기 멀리서 낮게 울리는 소리—짐승의 숨소리 같은 것이 들려옵니다.\n";
    cout << "“살아남으려면 뭔가를 찾아야 해...” 철수는 두근거리는 가슴을 안고 주변을 살피기 시작했습니다.\n";
    cout << "손을 뻗어 벽을 더듬는 순간, 날카로운 금속의 감촉이 느껴졌습니다.\n";
    cout << "철수는 작은 칼을 발견하고 움켜쥐었습니다. 이제, 이 던전에서 생존을 위한 첫 발걸음을 내디딥니다.\n\n";
    cout << "앞을 보니 세 가지 길이 있습니다.\n\n";
}

//게임 클리어 출력 함수
void DisplayGameClear() {
    cout << "□□□□□□□□■□■□□■■■■■■□□□■□□□□□□■■■■■■■■□□□■■■■■■□□□■□□□□■■□□□□□■" << endl;
    cout << "□■■■■■□□■□■□□■■□□■■□□□■□□□□□□□□□□□□□■□□□■■■■■■□□□■□□■■■■■■□□□■" << endl;
    cout << "□□□□□■□□■□■□□■□□□□■□□□■□□□□□■■■■■■■■■□□□□□□□□■□□□■□□■■□□■■□□□■" << endl;
    cout << "□□□□■■□□■□■□□■□□□□■□□□■□□□□□□■■□□□□□■□□□□□□□□■□□□■□□■□□□□■□□□■" << endl;
    cout << "□□□□■■■■■□■□□■■□□■■□□□■□□□□■■■■■■■■■■■■□■■■■■■□□□■□□■□□□□■■■■■" << endl;
    cout << "□□□□■■■■■□■□□■■■■■■□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□■□□■□□□□■□□□■" << endl;
    cout << "□□□■■□□□■□■□□□□□□□□□□□■□□□□□□□□□□□□□□□□□■□□□□□□□□■□□■□□□□■□□□■" << endl;
    cout << "□□■■■□□□■□■□□□□■■■■■■■■□□□□□□■■■■■■■■□□□■□□□□□□□□■□□■■□□■■□□□■" << endl;
    cout << "□■■□□□□□■□■□□□□■□□□□□□■□□□□□□□□□□□□□■□□□■■■■■■■■□■□□■■■■■■□□□■" << endl;
    cout << "□■□□□□□□■□■□□□□■□□□□□□■□□□□□□■■■■■■■■□□□□□□□□□□□□■□□□□□□□□□□□■" << endl;
    cout << "□□□□□□□□■□■□□□□■□□□□□□■□□□□□□■□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□■" << endl;
    cout << "□□□□□□□□■□■□□□□■■■■■■■■□□□□□□■■■■■■■■■□□□□□□□□□□□■□□□□□□□□□□□■" << endl;
}

// 플레이어에게 선택지를 보여주는 함수
void PresentChoices() {
    cout << "\n어떻게 할까요?\n";
    cout << "1. 첫번째 길로 간다\n";
    cout << "2. 두번째 길로 간다\n";
    cout << "3. 세번째 길로 간다\n";
    if (hidden_dungeon_unlocked) {
        cout << "4. 히든 던전: 대악마 아트록스의 방\n";
    }
    if (amumu_boss_unlocked) {
        cout << "5. 슬픈 미라 아무무의 방\n";
    }
    cout << "0. 게임종료\n";
    cout << "9. 가방을 열다\n";
}

// 아이템을 사용하는 함수
void UseItem() {
    if (player_bag.empty()) {
        cout << "가방에 사용할 아이템이 없습니다.\n";
        return;
    }

    cout << "사용할 아이템을 선택하세요:\n";
    for (int i = 0; i < player_bag.size(); i++) {
        cout << i + 1 << ". " << player_bag[i] << "\n";
    }
    cout << "0. 취소\n";
    cout << "선택을 입력하세요: ";

    string item_choice_str;
    cin >> item_choice_str; // 입력을 문자열로 받음

    // 숫자로 변환
    try {
        int item_choice = stoi(item_choice_str); // 문자열을 정수로 변환
        if (item_choice == 0) {
            cout << "아이템 사용을 취소했습니다.\n";
            return;
        }

        if (item_choice < 1 || item_choice > player_bag.size()) {
            cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
            return;
        }

        string selected_item = player_bag[item_choice - 1];

        if (selected_item == "빨간포션") {
            player_health += 20;
            cout << "빨간포션을 사용했습니다. 체력이 20 증가했습니다. 현재 체력: " << player_health << "\n";
        }
        else if (selected_item == "피묻은 도끼") {
            player_attack += 5;
            cout << "피묻은 도끼를 사용했습니다. 공격력이 5 증가했습니다. 현재 공격력: " << player_attack << "\n";
        }
        else if (selected_item == "날카로운 철검") {
            player_attack += 7;
            cout << "날카로운 철검을 사용했습니다. 공격력이 7 증가했습니다. 현재 공격력: " << player_attack << "\n";
        }
        else if (selected_item == "야만의 몽둥이") {
            player_attack += 6;
            cout << "야만의 몽둥이를 사용했습니다. 공격력이 6 증가했습니다. 현재 공격력: " << player_attack << "\n";
        }
        else if (selected_item == "천갑옷") {
            player_health += 25;
            cout << "천갑옷을 사용했습니다. 체력이 25 증가했습니다. 현재 체력: " << player_health << "\n";
        }
        else if (selected_item == "가죽갑옷") {
            player_health += 30;
            cout << "가죽갑옷을 사용했습니다. 체력이 30 증가했습니다. 현재 체력: " << player_health << "\n";
        }
        else if (selected_item == "다르킨의 검") {
            // 사용 여부 확인
            cout << "다르킨의 검을 사용할 경우 체력이 크게 줄어들수있습니다. 그래도 사용하시겠습니까? (y/n): ";
            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                player_attack += 20;
                player_health -= 50;
                cout << "다르킨의 검을 사용했습니다. 공격력이 20 증가하고 체력이 50 감소했습니다.\n";
                cout << "현재 공격력: " << player_attack << ", 현재 체력: " << player_health << "\n";

                if (player_health <= 0) {
                    cout << "다르킨의 검을 사용한 후 체력이 모두 소진되었습니다. 게임 종료.\n";
                    exit(0);
                }
            }
            else {
                cout << "다르킨의 검 사용을 취소했습니다.\n";
                return;
            }
        }
        else {
            cout << "이 아이템은 사용할 수 없습니다.\n";
            return;
        }

        // 사용한 아이템을 가방에서 제거
        player_bag.erase(player_bag.begin() + (item_choice - 1));

    } catch (invalid_argument& e) {
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        return;
    } catch (out_of_range& e) {
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        return;
    }
}

// 레벨업 체크 함수
void CheckLevelUp() {
    while (player_exp >= next_level_exp) {
        player_exp -= next_level_exp; // 초과된 경험치를 다음 레벨로 넘김
        player_level++;
        next_level_exp += 50; // 레벨업 시 다음 레벨까지 필요한 경험치 증가
        player_attack += 5; // 레벨업 보상: 공격력 증가
        player_health += 20; // 레벨업 보상: 체력 증가
        cout << "\n축하합니다! 레벨 " << player_level << "로 올라섰습니다!\n";
        cout << "공격력이 5 증가하여 " << player_attack << "이(가) 되었고, 체력이 20 증가하여 " << player_health << "이(가) 되었습니다.\n";
    }
}

// 플레이어와 몬스터의 전투 함수 (경험치 획득 추가)
void Battle(string monster_name, int monster_health, int monster_attack) {
    cout << monster_name << "과(와) 전투를 시작합니다!\n";

    while (monster_health > 0 && player_health > 0) {
        cout << "\n철수 체력: " << player_health << " / " << monster_name << " 체력: " << monster_health << "\n";
        cout << "1. 싸운다\n2. 도망친다\n";
        cout << "행동을 선택하세요 (1-2): ";
        int action;
        cin >> action;

        if (action == 1) {
            cout << "철수가 " << monster_name << "을(를) 공격합니다! " << monster_name << " 체력 -" << player_attack << "\n";
            monster_health -= player_attack;

            if (monster_health > 0) {
                cout << monster_name << "이(가) 철수를 공격합니다! 철수 체력 -" << monster_attack << "\n";
                player_health -= monster_attack;
            }
        } else if (action == 2) {
            player_health -= 5;
            cout << "도망치던 도중, " << monster_name << "이(가) 날린 공격에 스쳐 체력이 5 줄었습니다.\n";
            cout << "현재 체력: " << player_health << "\n";
            return;
        } else {
            cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }

    if (player_health <= 0) {
        cout << "철수가 쓰러졌습니다. 게임 종료.\n";
        exit(0);
    } else if (monster_health <= 0) {
        cout << monster_name << "을(를) 물리쳤습니다!\n";
        monster_defeat_count++; // 물리친 몬스터 수 증가
        cout << "현재 물리친 몬스터 수: " << monster_defeat_count << "\n";

        // 경험치 획득
        int exp_gained = rand() % 20; //랜덤 경험치
        player_exp += exp_gained;
        cout << "경험치 " << exp_gained << "을(를) 획득했습니다! 현재 경험치: " << player_exp << " / " << next_level_exp << "\n";

        // 레벨업 확인
        CheckLevelUp();

        if (monster_defeat_count >= 4 && !hidden_dungeon_unlocked) {
            hidden_dungeon_unlocked = true;
            cout << "\n히든 던전이 열렸습니다: 대악마 아트록스의 방!\n";
        }

        if (monster_name == "대악마 아트록스") {
            DisplayDarkinSwordArt();
            cout << "축하합니다! 대악마 아트록스를 물리쳤습니다!\n";
            cout << "아트록스가 사용했던 '다르킨의 검'을 획득했습니다!\n";
            player_bag.push_back("다르킨의 검");
            amumu_boss_unlocked = true; // 아무무 보스 방 잠금 해제
            cout << "슬픈 미라 아무무의 방이 열렸습니다!\n";
        } else if (monster_name == "슬픈 미라 아무무") {
            cout << "축하합니다! 슬픈 미라 아무무를 물리쳤습니다!\n";
            cout << "철수는 이 던전을 탈출했습니다. 게임 클리어!\n";
            DisplayGameClear();
            exit(0); // 게임 종료
        }
    }
}


// 히든 던전의 전투 함수
void EnterHiddenDungeon() {
    cout << "\n대악마 아트록스의 방에 들어갑니다...\n";
    DisplayAtroxArt();
    Battle("대악마 아트록스", ATROX_HEALTH, ATROX_ATTACK);
}

// 슬픈 미라 아무무의 방 진입 함수
void EnterAmumuBossRoom() {
    cout << "\n슬픈 미라 아무무의 방에 들어갑니다...\n";
    DisplayAmumuArt();
    Battle("슬픈 미라 아무무", AMUMU_HEALTH, AMUMU_ATTACK);
}

// 보물상자를 발견했을 때 아이템을 랜덤으로 드랍하는 함수
void DropItem(int path) {
    int item_index;
    string item;

    if (path == 1) {
        string items[] = {"피묻은 도끼", "가죽갑옷", "빨간포션"};
        item_index = rand() % 3;
        item = items[item_index];
    } else if (path == 2) {
        string items[] = {"날카로운 철검", "빨간포션", "천갑옷"};
        item_index = rand() % 3;
        item = items[item_index];
    } else {
        string items[] = {"야만의 몽둥이", "빨간포션"};
        item_index = rand() % 2;
        item = items[item_index];
    }
    if (item == "피묻은 도끼") {
        DisplayAxeArt();
    } else if (item == "가죽갑옷") {
        DisplayArmor2Art();
    } else if (item == "빨간포션") {
        DisplayPotionArt();
    } else if (item == "날카로운 철검") {
        DisplaySwordArt();
    } else if (item == "천갑옷") {
        DisplayArmorArt();
    } else if (item == "야만의 몽둥이") {
        DisplayMaceArt();
    }
    cout << "보물상자가 천천히 열리며 그 속에서 " << item << "을(를) 발견했습니다!\n";
    player_bag.push_back(item);
}

// 가방 내용을 출력하고 아이템을 사용할 수 있는 옵션을 제공하는 함수
void ViewBag() {
    if (player_bag.empty()) {
        cout << "가방이 비어 있습니다.\n";
    } else {
        cout << "철수의 가방 내용:\n";
        for (int i = 0; i < player_bag.size(); i++) {
            cout << i + 1 << ". " << player_bag[i] << "\n";
        }
        cout << "\n아이템을 사용하시겠습니까? (y/n): ";
        char use_choice;
        cin >> use_choice;
        if (use_choice == 'y' || use_choice == 'Y') {
            UseItem();
        }
    }
}


// 플레이어의 선택에 따른 결과를 처리하는 함수
void ProcessChoice(int choice) {
    int event = rand() % 4; // 0, 1, 2, 3 중 랜덤 이벤트 선택 -> 선택지가 4개인 3번째 길을 고려하여 수정
    if (choice == 1) {
        // 첫 번째 길: 미노타우르스, 멧돼지, 보물상자
        if (event == 0) {
            DisplayMinotaurArt();
            cout << "도끼를 든 미노타우르스가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("미노타우르스", 50, 7);
        } else if (event == 1) {
            DisplayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            DropItem(1); // 첫 번째 길 아이템 드랍
        } else {
            DisplayBoarArt();
            cout << "야생 멧돼지가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("야생 멧돼지", 20, 5);
        }
    } else if (choice == 2) {
        // 두 번째 길: 해골전사, 마녀, 보물상자
        if (event == 0) {
            DisplayWitchArt();
            cout << "마녀가 당신을 노려봅니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("마녀", 11, 10);
        } else if (event == 1) {
            DisplayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            DropItem(2); // 두 번째 길 아이템 드랍
        } else {
            DisplaySkeletonWarriorArt();
            cout << "해골전사가 나타났습니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("해골 전사", 15, 7);
        }
    } else if (choice == 3) {
        // 세 번째 길: 고블린 전사, 궁수, 마법사, 보물상자
        if (event == 0) {
            DisplayGoblinWarriorArt();
            cout << "고블린 전사가 나타났습니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("고블린 전사", 20, 5);
        } else if (event == 1) {
            DisplayGoblinArcherArt();
            cout << "고블린 궁수가 당신을 겨누고 있습니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("고블린 궁수", 15, 3);
        } else if (event == 2) {
            DisplayGoblinMageArt();
            cout << "고블린 마법사가 주문을 외우고 있습니다!\n";
            cout << "전투를 시작합니다\n";
            Battle("고블린 마법사", 11, 7);
        } else {
            DisplayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            DropItem(3); // 세 번째 길 아이템 드랍
        }
    } else if (choice == 4 && hidden_dungeon_unlocked) {
        EnterHiddenDungeon();
    } else if (choice == 5 && amumu_boss_unlocked) {
        EnterAmumuBossRoom();
    }
}

// 메인 함수
int main() {
    int choice;
    srand(time(0));
    DisplayIntro();

    while (true) {
        PresentChoices();
        cout << "선택을 입력하세요 (0-5, 9): ";
        cin >> choice;

        if (choice == 0) {
            DisplayDieArt();
            cout << "게임을 종료합니다. 철수는 탐험을 포기하기로 했습니다. 다음엔 더 강해진 모습으로 돌아올거죠?" << endl;
            break;
        }

        if (choice == 9) {
            ViewBag();
            continue;
        }

        cout << "현재 물리친 몬스터 수: " << monster_defeat_count << "\n";

        if (choice >= 1 && choice <= 3 || (choice == 4 && hidden_dungeon_unlocked) || (choice == 5 && amumu_boss_unlocked)) {
            ProcessChoice(choice);
        } else {
            cout << "잘못된 선택입니다. 다시 선택해 주세요.\n";
        }
    }

    return 0;
}
