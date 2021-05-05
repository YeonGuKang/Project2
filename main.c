#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm* time1, * time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main() {
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1() {

    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2() {
    stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1() {

}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2() {

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() {
    printf("file1 size : %d\n", (int)stat1.st_size);
    printf("file2 size : %d\n", (int)stat2.st_size);

    if ((int)stat1.st_size < (int)stat2.st_size)
    {
        printf("file2 size is bigger than file1\n");
    }
    else if ((int)stat1.st_size > (int)stat2.st_size)
    {
        printf("file1 size is bigger than file1\n");
    }
    else {
        printf("same size!\n");
    }

}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {
    printf("file1 blocks : %d\n", (int)stat1.st_blocks);
    printf("file2 blocks : %d\n", (int)stat2.st_blocks);

    if ((int)stat1.st_blocks < (int)stat2.st_blocks)
    {
        printf("file2 block is bigger than file1\n");
    }
    else if ((int)stat1.st_blocks > (int)stat2.st_blocks)
    {
        printf("file1 block is bigger than file1\n");
    }
    else {
        printf("same blocks!\n");
    }

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {
    time1 = localtime(&stat1.st_mtime);
    time2 = localtime(&stat2.st_mtime);

    printf("file1 last modification at %d / %d \n", time1->tm_mon + 1, time1->tm_mday);

    printf("file2 last modification at %d / %d \n", time2->tm_mon + 1, time2->tm_mday);


}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {
    printf("file1 last modification time at %d \n", stat1.st_mtime);
    printf("file2 last modification time at %d \n", stat2.st_mtime);



    if (stat1.st_mtime < stat2.st_mtime)
    {
        printf("file2 is modified latest than file1\n");
    }
    else if (stat1.st_mtime > stat2.st_mtime)
    {
        printf("file1 is modified latest than file2\n");
    }
    else {
        printf("same time!\n");
    }


}