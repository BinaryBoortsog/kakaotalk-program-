#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char name[20];
    int number;
} Members;

Members members[MAX];

void sortMembers(int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (members[i].number < members[j].number)
            {
                Members temp = members[i];
                members[i] = members[j];
                members[j] = temp;
            }
        }
    }
}

void addMember(int *count)
{
    if (*count >= MAX)
    {
        printf("⚠️ 회원 목록이 가득 찼습니다.\n");
        return;
    }
    printf("👤 새 회원의 이름을 입력하세요: ");
    scanf("%s", members[*count].name);
    printf("🔢 회원의 번호를 입력하세요: ");
    scanf("%d", &members[*count].number);
    (*count)++;
    printf("✅ 회원이 성공적으로 등록되었습니다!\n");
}

void displayMembers(int count)
{
    if (count == 0)
    {
        printf("표시할 회원이 없습니다.\n");
        return;
    }
    printf("\n📋 회원 목록 (번호 내림차순 정렬):\n");
    sortMembers(count);
    for (int i = 0; i < count; i++)
    {
        printf("👉 이름: %s | 번호: %d\n", members[i].name, members[i].number);
    }
}

void searchMember(int count)
{
    char name[20];
    printf("🔍 찾고 싶은 회원의 이름을 입력하세요: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(members[i].name, name) == 0)
        {
            printf("✅ 회원을 찾았습니다! 이름: %s | 번호: %d\n", members[i].name, members[i].number);
            return;
        }
    }
    printf("⚠️ 해당 이름의 회원이 존재하지 않습니다.\n");
}

void deleteMember(int *count)
{
    char name[20];
    printf("❌ 삭제할 회원의 이름을 입력하세요: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(members[i].name, name) == 0)
        {
            for (int j = i; j < *count - 1; j++)
            {
                members[j] = members[j + 1];
            }
            (*count)--;
            printf("🗑️ 회원이 성공적으로 삭제되었습니다.\n");
            return;
        }
    }
    printf("⚠️ 해당 이름의 회원이 존재하지 않습니다.\n");
}

int main()
{
    int choice, count = 0;
    do
    {
        printf("\n=== 📚 회원 관리 메뉴 ===\n");
        printf("1. 회원 등록\n");
        printf("2. 회원 목록 보기\n");
        printf("3. 회원 검색\n");
        printf("4. 회원 삭제\n");
        printf("5. 프로그램 종료\n");
        printf("👉 원하시는 메뉴 번호를 입력하세요 (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addMember(&count);
            break;
        case 2:
            displayMembers(count);
            break;
        case 3:
            searchMember(count);
            break;
        case 4:
            deleteMember(&count);
            break;
        case 5:
            printf("👋 프로그램을 종료합니다. 좋은 하루 되세요!\n");
            break;
        default:
            printf("❗ 잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    } while (choice != 5);

    return 0;
}
