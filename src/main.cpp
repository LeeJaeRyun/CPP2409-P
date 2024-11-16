#include <iostream>
#include <string>
using namespace std;

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

// 소개 스토리를 출력하는 함수
void displayIntro() {
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
}

// 플레이어의 선택에 따른 결과를 처리하는 함수
// C++의 switch 문을 사용하여 선택에 따른 결과를 구분
void processChoice(int choice) {
    switch (choice) {
        case 1:
            displayMinotaurArt();
            cout << "도끼를 든 미노타우르스가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            break;
        case 2:
            displayBoarArt();
            cout << "야생 멧돼지가 돌진해옵니다!\n";
            cout << "전투를 시작합니다\n";
            break;
        case 3:
            displayTreasureArt();
            cout << "보물상자를 발견했습니다.\n";
            break;
        default:
            cout << "잘못된 선택입니다. 다시 선택해 주세요.\n";
    }
}

int main() {
    int choice;

    // ASCII 아트와 소개 스토리를 출력합니다
    displayAsciiArt();
    displayIntro();

    // 올바른 선택이 입력될 때까지 반복
    while (true) {
        // 선택지를 보여주고 플레이어의 입력을 받음
        presentChoices();
        cout << "선택을 입력하세요 (1-3): ";
        cin >> choice;

        // 선택이 유효한지 확인
        if (choice >= 1 && choice <= 3) {  // choice가 1, 2, 3 중 하나인지 확인
            processChoice(choice);         // 유효한 선택이면 해당 선택을 처리
            break;                         // 유효한 입력 시 반복문 종료
        } else {
            cout << "잘못된 선택입니다. 다시 선택해 주세요.\n";  // 잘못된 입력일 때 경고 메시지 출력
        }
    }

    return 0;
}
