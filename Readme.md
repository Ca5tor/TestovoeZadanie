
# Тестовые Задания

### Задание 3. (файл main.cpp)

Дана матрица 2x13:

A B C D E F G H I J K L M \
N O P Q R S T U V W X Y Z

Вводится произвольное натуральное число n > 0. \
Необходимо сместить все элементы матрицы на n ячеек вправо \
по принципу "Змейки":
\
Пример: Если n = 2, то матрица будет иметь вид:

O N A B C D E F G H I J K \
P Q R S T U V W X Y Z M L

А если ввести число кратное 26, то получим исходную матрицу.

### Задание 2. (файл main1.cpp)

Вводится строка в формате <Фамилия Имя Отчество>.\
Необходимо выяснить, верно ли введена данная строка.

Строка считается верной если:
1. В строке допускаются только буквы (заглавные и прописные),
тире и пробелы;\
2. Фамилия, Имя и Отчество могут начинаться только с большой буквы. Все остальные буквы должны быть маленькие;\
3. Слова не могут начинаться либо заканчиваться тире. Тире 
допустимо в середине слова. Если в слове есть тире, последующая часть после него так же должна начинаться с большой буквы;\
4. Пробелы в строке могут содержаться только как разделитель слов. Строка не может начинаться/заканчиваться пробелом. Не допускается более одного пробела подряд;\
5. В некоторых зарубежных странах нет Отчества, и при этом имя состоит из более, чем одного слова. Итого в строке может быть 4 и более слов. В таком случае так же должны сохранится критерии правильного числа пробелов между словами;

В конце программа должна вывести "Верно", если все критерии соблюдены или "Неверно" если хотя бы одно условие нарушено.


### Мое решение задания 3:

Первое что Я делаю это проверяю условие что наше число больше нуля, и выдаю сообщение об ошибке и выхожу из функции в случае не корректного числа.

Вывожу исходную матрицу на конcоль для наглядности и проверяю следуещее:
1) Если введенное число больше 26, то число обновит значение, полученного из остатка по модулю.
2) Если введенное число равно 26 или 0, то вывожу сразу исходную матрицу и завершаю программу.

Для удобного сдвига решил использовать контейнер Очередь.
Это позволило мне не волноваться о том что выйду за границы матрицы или нужды в просчитывании вставки через индексы.
Заполняю очередь следующим образом:
Функция getFilledQueue.

Создаю динамическую очередь и начинаю заполнять по строчно элементы матрицы, но особым способом. 2ю строку матрицы присваиваю не с начала к концу а наоборот.
Например дана матрица:

1 2 3\
4 5 6

В моей очереди она будет представлена: 1 2 3 6 5 4

Дальше с помощью функции rotateQueue, начинаем сдвигать значения.

Пример свдига на 1:
Принцип такой, берём первое значение, удаляем его из начала и присваиваем в конец очереди.

Цикл для сдвига на 1 элемент равен кол-ву элементов - 1\
Пример для сдвига на 1 вправо:

Исходная очередь: 1 2 3 6 5 4

2 3 6 5 4 1;

3 6 5 4 1 2;

6 5 4 1 2 3;

5 4 1 2 3 6;

4 1 2 3 6 5;

Результат: 4 1 2 3 6 5.

После в updateMatrix обновляю значения матрицы.\
1-ой строке матрицы присваиваю половину значений из очереди от начала\
2-ой строке уже с конца остальнуюю половину очереди.

В конце вывожу результат обновленной матрицы в консоль(изменена именно текущая матрица, а не заполнена новая).


