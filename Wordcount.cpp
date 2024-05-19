#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������
int countCharacters(FILE* file);
int countWords(FILE* file);

int main(int argc, char* argv[]) {
    // �������
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // ���ļ�
    FILE* file;
    if (fopen_s(&file, argv[2], "r") != 0) {
        perror("Error opening file");
        return 1;
    }

    int count;
    // ͳ���ַ����򵥴���
    if (strcmp(argv[1], "-c") == 0) {
        count = countCharacters(file);
        printf("�ַ�����%d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        count = countWords(file);
        printf("��������%d\n", count);
    }
    else {
        printf("Invalid parameter\n");
        return 1;
    }

    fclose(file);
    return 0;
}

// ͳ���ַ���
int countCharacters(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// ͳ�Ƶ�����
int countWords(FILE* file) {
    int count = 0;
    char word[100]; // ���赥�ʳ��Ȳ�����100
    while (fscanf_s(file, "%s", word, (unsigned)_countof(word)) != EOF) {
        count++;
    }
    return count;
}
