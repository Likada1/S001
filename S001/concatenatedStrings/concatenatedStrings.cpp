// concatenatedStrings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    char string[256];
    char string1[256];
    char string2[512];
    char f[] = "%s";
    char fd[] = "%d\n";
    _asm {
        // Чтение первой строки
        lea ebx, string
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        // Чтение второй строки
        lea ebx, string1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        // Подготовка цикла перезаписи первой строки
        lea ebx, string
        mov ecx, -1
        dec ebx
        lea edx, string2
        dec edx
        // Цикл перезаписи первой строки
        b1:
            inc ecx
            inc ebx
            inc edx
            mov al, [ebx]
            mov [edx], al
            cmp al, 0
            jnz b1
        // Подготовка цикла перезаписи второй строки
        lea ebx, string1
        dec ebx
        dec edx
        // Цикл перезаписи второй строки
        b2 :
            inc ebx
            inc edx
            mov al, [ebx]
            mov[edx], al
            cmp al, 0
            jnz b2

        // Вывод результата
        lea ebx, string2
        push ebx
        lea ecx, f
        lea ecx, f
        push ecx
        call printf
        add esp, 8
    }

}
