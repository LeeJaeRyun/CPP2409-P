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
const int ATROX_ATTACK = 0;

// 아무무의 정보
const int AMUMU_HEALTH = 150;
const int AMUMU_ATTACK = 0;

// 히든 던전 관련 변수
bool hidden_dungeon_unlocked = false;
bool amumu_boss_unlocked = false;
int monster_defeat_count = 0; // 물리친 몬스터 수

// 플레이어(철수)의 체력과 공격력
int player_health = 100;
int player_attack = 10;

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


// 플레이어와 몬스터의 전투 함수
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

        if (monster_defeat_count >= 4 && !hidden_dungeon_unlocked) {
            hidden_dungeon_unlocked = true;
            cout << "\n히든 던전이 열렸습니다: 대악마 아트록스의 방!\n";
        }

        if (monster_name == "대악마 아트록스") {
            cout << "축하합니다! 대악마 아트록스를 물리쳤습니다!\n";
            cout << "아트록스가 사용했던 '다르킨의 검'을 획득했습니다!\n";
            player_bag.push_back("다르킨의 검");
            amumu_boss_unlocked = true; // 아무무 보스 방 잠금 해제
            cout << "슬픈 미라 아무무의 방이 열렸습니다!\n";
        } else if (monster_name == "슬픈 미라 아무무") {
            cout << "축하합니다! 슬픈 미라 아무무를 물리쳤습니다!\n";
            cout << "철수는 이 던전을 탈출했습니다. 게임 클리어!\n";
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

    cout << "보물상자에서 " << item << "을(를) 얻었습니다!\n";
    player_bag.push_back(item);
}

// 가방 내용을 출력하는 함수
void ViewBag() {
    if (player_bag.empty()) {
        cout << "가방이 비어 있습니다.\n";
    } else {
        cout << "철수의 가방 내용:\n";
        for (int i = 0; i < player_bag.size(); i++) {
            cout << i + 1 << ". " << player_bag[i] << "\n";
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
        cout << "선택을 입력하세요 (0-5): ";
        cin >> choice;

        if (choice == 0) {
            DisplayDieArt();
            cout << "게임을 종료합니다. 철수는 당신이 끝까지 지켜봐주지 않아 고독사했습니다." << endl;
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
