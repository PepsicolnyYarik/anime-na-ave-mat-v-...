#include <locale.h>
#include <stdio.h>
#include <windows.h>
#define size 100

int main()
{
	setlocale(LC_ALL, "Rus");
	char mas[size];
	int i = 0,n=0,dlina,max=0,start=0,temp,flag=0;
	do 
	{
		printf("Введите строку без знаков препинания(до 100 символов)\n");      // проверка на ввод
		fgets(mas, 100, stdin);
		system("cls");
	} while (mas[0] == '\n');
	for (dlina = 0; mas[dlina] != '\n'; dlina++); // циклом находим длину введенной строки
	printf("Длина введенной строки %d\n", dlina);
	for (int i = 0; i < dlina; i++)
	{
		if (mas[i] != ' ' )
		{
			n++;
		}
		if (mas[i] == ' ' || dlina - i == 1)    // здесь мы вычисляем самое длинное слово и id первой буквы
		{
			if (n >= max)
			{
				max = n;
				start = i - max;
			}
			n = 0;
		}
	}
	for (i = start; i < dlina; i++)
	{
		if (i + max + 1 < dlina && max!=dlina)  // добавляем исключение: если слово одно в строке, то символы не смещаются
		{
			temp = mas[i];
			mas[i] = mas[i + max + 1];         // смещаем символы
			mas[i + max + 1] = temp;
		} 
		if (max == dlina)                      // если слово одно в строке, то заканчиваем строку на 0 элементе
		{
			mas[0] = '\0';
		}
	}
	if (max != dlina)
	{
		mas[dlina - max - 1] = '\0';            // уменьшаем строку
	}
	printf("Самое длинное слово состоит из %d букв(ы)\nИзмененная строка:\n", max);
	puts(mas);
	return 0;
}