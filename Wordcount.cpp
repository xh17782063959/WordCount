#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
int countCharacters(FILE* file);
int countWords(FILE* file);

int main(int argc, char* argv[]) {
    // 参数检查
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE* file;
    if (fopen_s(&file, argv[2], "r") != 0) {
        perror("Error opening file");
        return 1;
    }

    int count;
    // 统计字符数或单词数
    if (strcmp(argv[1], "-c") == 0) {
        count = countCharacters(file);
        printf("字符数：%d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        count = countWords(file);
        printf("单词数：%d\n", count);
    }
    else {
        printf("Invalid parameter\n");
        return 1;
    }

    fclose(file);
    return 0;
}

// 统计字符数
int countCharacters(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// 统计单词数
int countWords(FILE* file) {
    int count = 0;
    char word[100]; // 假设单词长度不超过100
    while (fscanf_s(file, "%s", word, (unsigned)_countof(word)) != EOF) {
        count++;
    }
    return count;
}
