#include <iostream>
#include <time.h>
#include <stdlib.h>

#define PRINT_LINE std::cout << "==================================" << std::endl
#define PRINT_INPUT_ARROW std::cout << ">> "

#define MAX_NAME_LENGTH 16
#define ITEM_DESCRIPTION_LENGTH 512
#define MAX_INVENTORY_SIZE 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

//메인 메뉴 enum
enum MAIN_MENU {

    MAIN_MENU_NONE,
    MAIN_MENU_MAP,
    MAIN_MENU_STORE,
    MAIN_MENU_INVENTORY,
    MAIN_MENU_EXIT

};

//맵 타입 enum
enum MAP_TYPE {

    MAP_TYPE_NONE,
    MAP_TYPE_NORMAL,
    MAP_TYPE_HARD,
    MAP_TYPE_INSANE,
    MAP_TYPE_BACK

};

//직업 enum
enum JOB {

    JOB_NONE,
    JOB_KNIGHT,
    JOB_ARCHER,
    JOB_WIZARD,
    JOB_END

};

//전투 행동 enum
enum BATTLE_ACT {

    BATTLE_ACT_NONE,
    BATTLE_ACT_ATTACK,
    BATTLE_ACT_RUN

};

//아이템 타입 enum
enum ITEM_TYPE {

    ITEM_TYPE_NONE,
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_ARMOR,
    ITEM_TYPE_BACK

};

//상점 메뉴 enum
enum STORE_MENU {

    STORE_MENU_NONE,
    STORE_MENU_WEAPON,
    STORE_MENU_ARMOR,
    STORE_MENU_BACK

};

//아이템 구조체
struct Item {

    char Name[MAX_NAME_LENGTH];
    char TypeName[MAX_NAME_LENGTH];

    ITEM_TYPE type;

    int Min;
    int Max;
    int BuyPrice;
    int SellPrice;
    
    char Description[ITEM_DESCRIPTION_LENGTH];

};

//인벤토리 구조체
struct Inventory
{

    Item Item[MAX_INVENTORY_SIZE];
    int ItemCount;
    int Gold;

};

//플레이어 구조체
struct Player
{

    char Name[MAX_NAME_LENGTH];
    char JobName[MAX_NAME_LENGTH];

    JOB Job;

    int ATKMin; //최소 공격력
    int ATKMax; //최대 공격력
    int DEFMin; //최소 방어력
    int DEFMax; //최대 방어력
    int HP; //현재 체력
    int HPMax; //최대 체력
    int MP; //현재 마나
    int MPMax; //최대 마나
    int Exp; //현재 경험치
    int Level; //현재 레벨
    
    Inventory inventory;

};

//몬스터 구조체
struct Monster
{

    char Name[MAX_NAME_LENGTH];

    int ATKMin; //최소 공격력
    int ATKMax; //최대 공격력
    int DEFMin; //최소 방어력
    int DEFMax; //최대 방어력
    int HP; //현재 체력
    int HPMax; //최대 체력
    int MP; //현재 마나
    int MPMax; //최대 마나
    int Exp; //지급 경험치
    int Level; //몬스터 레벨
    int GoldMin; //최소 지급 골드
    int GoldMax; //최대 지급 골드

};

int main()
{

    srand((unsigned)time(0));

    Player Player = {};

    //플레이어 이름 입력 메뉴
    while (true) {

        system("cls");

        PRINT_LINE;
        std::cout << "[!] 이름을 입력해주세요." << std::endl;
        PRINT_LINE;
        PRINT_INPUT_ARROW;

        std::cin.getline(Player.Name, 100);

        if (std::strlen(Player.Name) <= MAX_NAME_LENGTH) {

            break;

        }
        else {

            std::cout << "[!] 이름의 최대 길이는 " << MAX_NAME_LENGTH << "글자입니다." << std::endl;

            system("pause");

            continue;

        }

    }

    //직업 선택 메뉴
    while (true) {

        system("cls");

        PRINT_LINE;
        std::cout << "[!] 직업을 선택해주세요." << std::endl;
        PRINT_LINE;
        std::cout << "[1] 기사" << std::endl;
        std::cout << "[2] 궁수" << std::endl;
        std::cout << "[3] 마법사" << std::endl;
        PRINT_LINE;
        PRINT_INPUT_ARROW;

        int SelectedJob;

        std::cin >> SelectedJob;

        if (std::cin.fail()) {

            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;

        }

        if (SelectedJob > JOB_NONE && SelectedJob < JOB_END) {

            Player.Job = (JOB)SelectedJob;

            Player.Exp = 0;
            Player.Level = 1;
            Player.inventory.Gold = 10000;

            switch (Player.Job) {

            //기사 선택
            case JOB_KNIGHT:

                strcpy_s(Player.JobName, "기사");

                Player.ATKMin = 5;
                Player.ATKMax = 10;
                Player.DEFMin = 15;
                Player.DEFMax = 20;
                Player.HPMax = 500;
                Player.HP = 500;
                Player.MPMax = 100;
                Player.MP = 100;
                break;

            //궁수 선택
            case JOB_ARCHER:

                strcpy_s(Player.JobName, "궁수");

                Player.ATKMin = 10;
                Player.ATKMax = 15;
                Player.DEFMin = 10;
                Player.DEFMax = 15;
                Player.HPMax = 400;
                Player.HP = 400;
                Player.MPMax = 200;
                Player.MP = 200;

                break;

            //마법사 선택
            case JOB_WIZARD:

                strcpy_s(Player.JobName, "마법사");

                Player.ATKMin = 15;
                Player.ATKMax = 20;
                Player.DEFMin = 5;
                Player.DEFMax = 10;
                Player.HPMax = 300;
                Player.HP = 300;
                Player.MPMax = 300;
                Player.MP = 300;

                break;

            }

            break;

        }
        else {

            continue;
        }
    }
    //몬스터 생성
    Monster MonsterArr[MAP_TYPE_BACK - 1] = {};

    //고블린 생성
    strcpy_s(MonsterArr[0].Name, "고블린");
    MonsterArr[0].ATKMin = 20;
    MonsterArr[0].ATKMax = 30;
    MonsterArr[0].DEFMin = 2;
    MonsterArr[0].DEFMax = 5;
    MonsterArr[0].HPMax = 100;
    MonsterArr[0].HP = 100;
    MonsterArr[0].MPMax = 10;
    MonsterArr[0].MP = 10;
    MonsterArr[0].Level = 1;
    MonsterArr[0].Exp = 1000;
    MonsterArr[0].GoldMin = 500;
    MonsterArr[0].GoldMax = 1500;

    //트롤 생성
    strcpy_s(MonsterArr[1].Name, "트롤");
    MonsterArr[1].ATKMin = 80;
    MonsterArr[1].ATKMax = 130;
    MonsterArr[1].DEFMin = 60;
    MonsterArr[1].DEFMax = 90;
    MonsterArr[1].HPMax = 2000;
    MonsterArr[1].HP = 2000;
    MonsterArr[1].MPMax = 100;
    MonsterArr[1].MP = 100;
    MonsterArr[1].Level = 5;
    MonsterArr[1].Exp = 7000;
    MonsterArr[1].GoldMin = 6000;
    MonsterArr[1].GoldMax = 8000;

    //드래곤 생성
    strcpy_s(MonsterArr[2].Name, "드래곤");
    MonsterArr[2].ATKMin = 250;
    MonsterArr[2].ATKMax = 500;
    MonsterArr[2].DEFMin = 200;
    MonsterArr[2].DEFMax = 400;
    MonsterArr[2].HPMax = 30000;
    MonsterArr[2].HP = 30000;
    MonsterArr[2].MPMax = 60000;
    MonsterArr[2].MP = 60000;
    MonsterArr[2].Level = 10;
    MonsterArr[2].Exp = 30000;
    MonsterArr[2].GoldMin = 20000;
    MonsterArr[2].GoldMax = 50000;

    //상점에서 판매할 아이템 목록을 생성한다.
    Item StoreWeapon[STORE_WEAPON_MAX] = {};
    Item StoreArmor[STORE_ARMOR_MAX] = {};

    //각 아이템 정보를 설정해준다.
    strcpy_s(StoreWeapon[0].Name, "롱소드");
    strcpy_s(StoreWeapon[0].Description, "가장 기본적인 검.");
    strcpy_s(StoreWeapon[0].TypeName, "검");
    StoreWeapon[0].type = ITEM_TYPE_WEAPON;
    StoreWeapon[0].Min = 10;
    StoreWeapon[0].Max = 20;
    StoreWeapon[0].BuyPrice = 2000;
    StoreWeapon[0].SellPrice = 1400;

    strcpy_s(StoreWeapon[1].Name, "곡궁");
    strcpy_s(StoreWeapon[1].Description, "가장 기본적인 활.");
    strcpy_s(StoreWeapon[1].TypeName, "활");
    StoreWeapon[1].type = ITEM_TYPE_WEAPON;
    StoreWeapon[1].Min = 15;
    StoreWeapon[1].Max = 25;
    StoreWeapon[1].BuyPrice = 2500;
    StoreWeapon[1].SellPrice = 1750;

    strcpy_s(StoreWeapon[2].Name, "나무 완드");
    strcpy_s(StoreWeapon[2].Description, "가장 기본적인 완드.");
    strcpy_s(StoreWeapon[2].TypeName, "완드");
    StoreWeapon[2].type = ITEM_TYPE_WEAPON;
    StoreWeapon[2].Min = 20;
    StoreWeapon[2].Max = 30;
    StoreWeapon[2].BuyPrice = 3000;
    StoreWeapon[2].SellPrice = 2100;

    //로비 메뉴
    while (true) {

        system("cls");

        PRINT_LINE;
        std::cout << "※ 로비 ※ " << std::endl;
        PRINT_LINE;
        std::cout << "[1] 맵 열기" << std::endl;
        std::cout << "[2] 상점 열기" << std::endl;
        std::cout << "[3] 인벤토리 열기" << std::endl;
        std::cout << "[4] 종료" << std::endl;
        PRINT_LINE;
        std::cout << "[!] 메뉴를 선택해주세요." << std::endl;
        PRINT_LINE;
        PRINT_INPUT_ARROW;
        
        int InputNum;

        std::cin >> InputNum;

        if (std::cin.fail()) {

            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;

        }

        //게임 종료
        if (InputNum == MAIN_MENU_EXIT) {

            std::cout << "[!] 게임을 종료합니다." << std::endl;

            break;

        }

        switch (InputNum) {
           
        //맵 메뉴
        case MAIN_MENU_MAP:

            while (true) {

                system("cls");

                PRINT_LINE;
                std::cout << "※ 맵 ※ " << std::endl;
                PRINT_LINE;
                std::cout << "[1] NORMAL" << std::endl;
                std::cout << "[2] HARD" << std::endl;
                std::cout << "[3] INSANE" << std::endl;
                std::cout << "[4] 뒤로가기" << std::endl;
                PRINT_LINE;
                std::cout << "[!] 맵을 선택해주세요." << std::endl;
                PRINT_LINE;
                PRINT_INPUT_ARROW;

                std::cin >> InputNum;

                if (std::cin.fail()) {

                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    continue;

                }

                if (InputNum == MAP_TYPE_BACK) {

                    break;

                }

                Monster Monster = MonsterArr[InputNum - 1];

                while (true) {

                    switch (InputNum) {

                    case MAP_TYPE_NORMAL:

                        PRINT_LINE;
                        std::cout << "※ NORMAL ※ " << std::endl;
                        PRINT_LINE;

                        break;

                    case MAP_TYPE_HARD:

                        PRINT_LINE;
                        std::cout << "※ HARD ※ " << std::endl;
                        PRINT_LINE;

                        break;

                    case MAP_TYPE_INSANE:

                        PRINT_LINE;
                        std::cout << "※ INSANE ※ " << std::endl;
                        PRINT_LINE;

                        break;

                    }

                    system("cls");

                    //플레이어 정보 출력
                    PRINT_LINE;
                    std::cout << "※ 플레이어 정보 ※" << std::endl;
                    PRINT_LINE;
                    std::cout << "이름 | " << Player.Name << std::endl;
                    std::cout << "직업 | " << Player.JobName << std::endl;
                    std::cout << "레벨 | " << Player.Level << " / 경험치 | " << Player.Exp << std::endl;
                    std::cout << "체력 | " << Player.HP << "/(" << Player.HPMax << ")" << std::endl;
                    std::cout << "마나 | " << Player.MP << "/(" << Player.MPMax << ")" << std::endl;
                    std::cout << "공격력 | " << Player.ATKMin << " ~ " << Player.ATKMax << std::endl;
                    std::cout << "방어력 | " << Player.DEFMin << " ~ " << Player.DEFMax << std::endl;
                    std::cout << "보유 골드 | " << Player.inventory.Gold << "G" << std::endl;
                    PRINT_LINE;

                    std::cout << std::endl;

                    //몬스터 정보 출력
                    PRINT_LINE;
                    std::cout << "※ 몬스터 정보 ※" << std::endl;
                    PRINT_LINE;
                    std::cout << "이름 | " << Monster.Name << std::endl;
                    std::cout << "레벨 | " << Monster.Level << " / 경험치 | " << Monster.Exp << std::endl;
                    std::cout << "체력 | " << Monster.HP << "/(" << Monster.HPMax << ")" << std::endl;
                    std::cout << "마나 | " << Monster.MP << "/(" << Monster.MPMax << ")" << std::endl;
                    std::cout << "공격력 | " << Monster.ATKMin << " ~ " << Monster.ATKMax << std::endl;
                    std::cout << "방어력 | " << Monster.DEFMin << " ~ " << Monster.DEFMax << std::endl;
                    PRINT_LINE;

                    std::cout << "[1] 공격하기" << std::endl;
                    std::cout << "[2] 도망가기" << std::endl;
                    PRINT_LINE;
                    PRINT_INPUT_ARROW;

                    std::cin >> InputNum;

                    if (std::cin.fail()) {

                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        continue;

                    }
                    else if (InputNum == BATTLE_ACT_RUN) {

                        break;
                    }


                    switch (InputNum) {

                    case BATTLE_ACT_ATTACK:
                    {
                        int ATK = rand() % (Player.ATKMax - Player.ATKMin + 1) + Player.ATKMin;
                        int DEF = rand() % (Monster.DEFMax - Monster.DEFMin + 1) + Monster.DEFMin;

                        int DMG = ATK - DEF;

                        DMG = DMG < 1 ? 1 : DMG;

                        Monster.HP = Monster.HP - DMG;

                        std::cout << "[!] " << Player.Name << " 이(가) " << Monster.Name << "에게 " << DMG << "만큼의 데미지를 입혔습니다!" << std::endl;

                        if (Monster.HP <= 0) {

                            std::cout << "[!] " << Monster.Name << " 이(가) 쓰러졌습니다!" << std::endl;

                            Player.Exp = Player.Exp + Monster.Exp;

                            int EarnedGold = Player.inventory.Gold + (rand() % (Monster.GoldMax - Monster.GoldMin + 1) + Monster.GoldMin);
                            Player.inventory.Gold = EarnedGold;

                            std::cout << "[!] 경험치를 " << Monster.Exp << " 만큼 획득했습니다!" << std::endl;
                            std::cout << "[!] 골드를 " << EarnedGold << "G 만큼 획득했습니다!" << std::endl;

                            Monster.HP = Monster.HPMax;
                            Monster.MP = Monster.MPMax;

                            system("pause");

                            break;

                        } else { 
                        
                            int ATK = rand() % (Monster.ATKMax - Monster.ATKMin + 1) + Monster.ATKMin;
                            int DEF = rand() % (Player.DEFMax - Player.DEFMin + 1) + Player.DEFMin;

                            int DMG = ATK - DEF;

                            DMG = DMG < 1 ? 1 : DMG;

                            Player.HP = Player.HP - DMG;

                            std::cout << "[!] " << Monster.Name << " 이(가) " << Player.Name << "에게 " << DMG << "만큼의 데미지를 입혔습니다!" << std::endl;

                            if (Player.HP <= 0) {

                                std::cout << "[!] " << Player.Name << " 이(가) 쓰러졌습니다!" << std::endl;

                                int LostExp = Player.Exp * 0.1f;
                                int LostGold = Player.inventory.Gold * 0.1f;

                                Player.Exp = Player.Exp - LostExp;
                                Player.inventory.Gold = Player.inventory.Gold - LostGold;

                                std::cout << "[!] 경험치를 " << LostExp << " 만큼 잃었습니다..." << std::endl;
                                std::cout << "[!] 골드를 " << LostGold << "G 만큼 잃었습니다..." << std::endl;

                                Player.HP = Player.HPMax;
                                Player.MP = Player.MPMax;

                                system("pause");

                                break;

                            }
                        }

                        system("pause");

                    }

                        break;

                    default:

                        break;

                    }

                }
                
            }

            break;

        //상점 메뉴
        case MAIN_MENU_STORE:

            while (true) {

                system("cls");

                PRINT_LINE;
                std::cout << "※ 상점 ※ " << std::endl;
                PRINT_LINE;
                std::cout << "[1] 무기 상점" << std::endl;
                std::cout << "[2] 방어구 상점" << std::endl;
                std::cout << "[3] 뒤로가기" << std::endl;
                PRINT_LINE;
                std::cout << "[!] 상점을 선택해주세요." << std::endl;
                PRINT_LINE;
                PRINT_INPUT_ARROW;

                std::cin >> InputNum;

                if (std::cin.fail()) {

                    std::cin.clear();
                    std::cin.ignore(1024, '\n');

                    continue;

                }
                else if (InputNum == STORE_MENU_BACK) {

                    break;

                }

                switch (InputNum) {

                case STORE_MENU_WEAPON:

                    while (true) {

                        system("cls");

                        PRINT_LINE;
                        std::cout << "※ 무기 상점 ※ " << std::endl;
                        PRINT_LINE;

                        //판매 목록을 보여준다.
                        for (int i = 0; i < STORE_WEAPON_MAX; ++i) {

                            std::cout << "[" << i + 1 << "] " << StoreWeapon[i].Name << std::endl;
                            std::cout << "종류 : " << StoreWeapon[i].TypeName << std::endl;
                            std::cout << "공격력 : " << StoreWeapon[i].Min << " ~ " << StoreWeapon[i].Max << std::endl;
                            std::cout << "구매 가격 : " << StoreWeapon[i].BuyPrice << "G" << std::endl;
                            std::cout << "판매 가격 : " << StoreWeapon[i].SellPrice << "G" << std::endl;
                            std::cout << "《" << StoreWeapon[i].Description << "》" << std::endl;
                            PRINT_LINE;

                        }

                        std::cout << "[" << STORE_WEAPON_MAX + 1 << "] 뒤로가기" << std::endl;
                        PRINT_LINE;
                        std::cout << "[!] 보유 금액 : " << Player.inventory.Gold << "G" << std::endl;
                        std::cout << "[!] 남은 공간 : " << MAX_INVENTORY_SIZE - Player.inventory.ItemCount << std::endl;
                        PRINT_LINE;
                        PRINT_INPUT_ARROW;

                        std::cin >> InputNum;

                        if (std::cin.fail()) {

                            std::cin.clear();
                            std::cin.ignore(1024, '\n');

                            continue;

                        }
                        else if (InputNum == STORE_WEAPON_MAX + 1) {

                            break;

                        }
                        else if (InputNum > STORE_WEAPON_MAX + 1 || InputNum < 1) {

                            std::cout << "[!] 잘못 선택하셨습니다." << std::endl;
                            system("pause");
                            continue;

                        }

                        int WeaponIndex = InputNum - 1;

                        if (Player.inventory.ItemCount == MAX_INVENTORY_SIZE) {

                            std::cout << "[!] 인벤토리가 꽉 찼습니다." << std::endl;
                            system("pause");
                            continue;

                        }
                        else if (Player.inventory.Gold < StoreWeapon[WeaponIndex].BuyPrice) {

                            std::cout << "[!] 골드가 모자랍니다." << std::endl;
                            system("pause");
                            continue;

                        }

                        Player.inventory.Item[Player.inventory.ItemCount] = StoreWeapon[WeaponIndex];
                        Player.inventory.ItemCount = Player.inventory.ItemCount + 1;
                        Player.inventory.Gold = Player.inventory.Gold - StoreWeapon[WeaponIndex].BuyPrice;

                        std::cout << "[!] " << StoreWeapon[WeaponIndex].Name << "을(를) 구매했습니다." << std::endl;
                        system("pause");

                    }

                    break;

                case STORE_MENU_ARMOR:

                    break;

                default:

                    break;

                }

            }

            break;

        //인벤토리 메뉴
        case MAIN_MENU_INVENTORY:

            /*PRINT_LINE;
            std::cout << "※ 인벤토리 ※ " << std::endl;
            PRINT_LINE;
            std::cout << "※ 플레이어 정보 ※" << std::endl;
            PRINT_LINE;
            std::cout << "이름 | " << Player.Name << std::endl;
            std::cout << "직업 | " << Player.JobName << std::endl;
            std::cout << "레벨 | " << Player.Level << " / 경험치 | " << Player.Exp << std::endl;
            std::cout << "체력 | " << Player.HP << "/(" << Player.HPMax << ")" << std::endl;
            std::cout << "마나 | " << Player.MP << "/(" << Player.MPMax << ")" << std::endl;
            std::cout << "공격력 | " << Player.ATKMin << " ~ " << Player.ATKMax << std::endl;
            std::cout << "방어력 | " << Player.DEFMin << " ~ " << Player.DEFMax << std::endl;
            std::cout << "보유 골드 | " << Player.inventory.Gold << "G" << std::endl;
            PRINT_LINE; */

            break;

        default:

            break;

        }

    }

    return 0;

}
