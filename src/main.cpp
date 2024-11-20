#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 플레이어(철수)의 체력과 공격력
int playerHealth = 100;
int playerAttack = 10;

// 던전에서 잠든 철수의 ASCII 아트를 출력하는 함수
void displayAsciiArt() {
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
}

// 미노타우르스의 ASCII 아트를 출력하는 함수
void displayMinotaurArt() {
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
void displayBoarArt() {
    cout << "      /\\   ___   /\\     " << endl;
    cout << "     //\\\\ (o o) //\\\\   " << endl;
    cout << "    ||   \\\\_^_//   ||   " << endl;
    cout << "     \\\\    '-'    //    " << endl;
    cout << "      '-.........-'      " << endl;
}

// 보물상자의 ASCII 아트를 출력하는 함수
void displayTreasureArt() {
    cout << "      ___________       " << endl;
    cout << "     /           \\      " << endl;
    cout << "    / $$$$$$$$$$  \\     " << endl;
    cout << "   | $$$$$$$$$$$$ |     " << endl;
    cout << "   | $$$$$$$$$$$$ |     " << endl;
    cout << "    \\_____[T]____/      " << endl;
}

// 해골전사의 ASCII 아트를 출력하는 함수
void displaySkeletonWarriorArt() {
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
void displayWitchArt() {
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
void displayGoblinWarriorArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\_______/    " << endl;
    cout << "     //   \\\\     " << endl;
    cout << "    ||     ||    " << endl;
}


// 고블린 궁수의 ASCII 아트를 출력하는 함수
void displayGoblinArcherArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\--| |--/    " << endl;
    cout << "       | |       " << endl;
}

// 고블린 마법사의 ASCII 아트를 출력하는 함수
void displayGoblinMageArt() {
    cout << "     .----.     " << endl;
    cout << "    /  o o \\    " << endl;
    cout << "   |    ^    |   " << endl;
    cout << "   |  \\___/  |   " << endl;
    cout << "    \\_-===-_/    " << endl;
    cout << "     /     \\     " << endl;
}

//사망 메시지 출력 함수
void displayDieArt() {
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
void displayIntro() {
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
void presentChoices() {
    cout << "\n어떻게 할까요?\n";
    cout << "1. 첫번째 길로 간다\n";
    cout << "2. 두번째 길로 간다\n";
    cout << "3. 세번째 길로 간다\n";
    cout << "0. 게임종료\n";
}

// 플레이어와 몬스터의 전투 함수
void battle(string monsterName, int monsterHealth, int monsterAttack) {
    cout << monsterName << "과(와) 전투를 시작합니다!\n";

    while (monsterHealth > 0 && playerHealth > 0) {
        cout << "\n철수 체력: " << playerHealth << " / " << "몬스터 체력: " << monsterHealth << "\n";
        cout << "1. 싸운다\n2. 도망친다\n";
        cout << "행동을 선택하세요 (1-2): ";
        int action;
        cin >> action;

        if (action == 1) {
            // 싸운다
            cout << "철수가 " << monsterName << "을(를) 공격합니다! " << monsterName << " 체력 -" << playerAttack << "\n";
            monsterHealth -= playerAttack;

            if (monsterHealth > 0) {
                // 몬스터의 공격
                cout << monsterName << "이(가) 철수를 공격합니다! 철수 체력 -" << monsterAttack << "\n";
                playerHealth -= monsterAttack;
            }
        } else if (action == 2) {
            // 도망친다
            playerHealth -= 5; // 도망 시 체력 감소
            cout << "도망치던 도중, " << monsterName << "이(가) 날린 공격에 스쳐 체력이 5 줄었습니다.\n";
            cout << "현재 체력: " << playerHealth << "\n";
            return; // 도망 성공, 전투 종료
        } else {
            cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }

    if (playerHealth <= 0) {
        cout << "철수가 쓰러졌습니다. 게임 종료.\n";
        displayDieArt();
        exit(0);
    } else if (monsterHealth <= 0) {
        cout << monsterName << "을(를) 물리쳤습니다!\n";
        cout << "남은 체력: " << playerHealth << "\n";
    }
}


// 보물상자를 발견했을 때 아이템을 랜덤으로 드랍하는 함수
void dropItem(int path) {
    int itemIndex;

    if (path == 1) {
        // 첫 번째 길 아이템 리스트
        string items[] = {"피묻은 도끼", "가죽갑옷", "빨간포션"};
        itemIndex = rand() % 3;
        cout << "보물상자에서 " << items[itemIndex] << "을(를) 얻었습니다!" << endl;
    } else if (path == 2) {
        // 두 번째 길 아이템 리스트
        string items[] = {"날카로운 철검", "빨간포션", "천갑옷"};
        itemIndex = rand() % 3;
        cout << "보물상자에서 " << items[itemIndex] << "을(를) 얻었습니다!" << endl;
    } else if (path == 3) {
        // 세 번째 길 아이템 리스트
        string items[] = {"야만의 몽둥이", "빨간포션"};
        itemIndex = rand() % 2;
        cout << "보물상자에서 " << items[itemIndex] << "을(를) 얻었습니다!" << endl;
    }
}

// 플레이어의 선택에 따른 결과를 처리하는 함수
void processChoice(int choice) {
    int event = rand() % 4; // 0, 1, 2, 3 중 랜덤 이벤트 선택 -> 선택지가 4개인 3번째 길을 고려하여 수정
    if (choice == 1) {
        // 첫 번째 길: 미노타우르스, 멧돼지, 보물상자
        if (event == 0) {
            displayMinotaurArt();
            cout << "도끼를 든 미노타우르스가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            battle("미노타우르스", 50, 7);
        } else if (event == 1) {
            displayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            dropItem(1); // 첫 번째 길 아이템 드랍
        } else {
            displayBoarArt();
            cout << "야생 멧돼지가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            battle("야생 멧돼지", 20, 5);
        }
    } else if (choice == 2) {
        // 두 번째 길: 해골전사, 마녀, 보물상자
        if (event == 0) {
            displayWitchArt();
            cout << "마녀가 당신을 노려봅니다!\n";
            cout << "전투를 시작합니다\n";
            battle("마녀", 11, 10);
        } else if (event == 1) {
            displayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            dropItem(2); // 두 번째 길 아이템 드랍
        } else {
            displaySkeletonWarriorArt();
            cout << "해골전사가 나타났습니다!\n";
            cout << "전투를 시작합니다\n";
            battle("해골 전사", 15, 7);
        }
    } else if (choice == 3) {
        // 세 번째 길: 고블린 전사, 궁수, 마법사, 보물상자
        if (event == 0) {
            displayGoblinWarriorArt();
            cout << "고블린 전사가 나타났습니다!\n";
            cout << "전투를 시작합니다\n";
            battle("고블린 전사", 20, 5);
        } else if (event == 1) {
            displayGoblinArcherArt();
            cout << "고블린 궁수가 당신을 겨누고 있습니다!\n";
            cout << "전투를 시작합니다\n";
            battle("고블린 궁수", 15, 3);
        } else if (event == 2) {
            displayGoblinMageArt();
            cout << "고블린 마법사가 주문을 외우고 있습니다!\n";
            cout << "전투를 시작합니다\n";
            battle("고블린 마법사", 11, 7);
        } else {
            displayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            dropItem(3); // 세 번째 길 아이템 드랍
        }
    }
}


int main() {
    int choice;
    srand(time(0));
    // ASCII 아트와 소개 스토리를 출력합니다
    displayAsciiArt();
    displayIntro();

    // 올바른 선택이 입력될 때까지 반복
    while (true) {
        // 선택지를 보여주고 플레이어의 입력을 받음
        presentChoices();
        cout << "선택을 입력하세요 (0-3): ";
        cin >> choice;

        if (choice == 0) {
            displayDieArt();
            cout << "게임을 종료합니다. 철수는 당신이 끝까지 지켜봐주지 않아 고독사했습니다." << endl;
            break; // 0을 선택하면 게임 종료
        }

        // 선택이 유효한지 확인
        if (choice >= 1 && choice <= 3) {  // choice가 1, 2, 3 중 하나인지 확인
            processChoice(choice);         // 유효한 선택이면 해당 선택을 처리
        } else {
            cout << "잘못된 선택입니다. 다시 선택해 주세요.\n";  // 잘못된 입력일 때 경고 메시지 출력
        }
    }

    return 0;
}