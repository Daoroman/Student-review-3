Фнукция LoadPerson. 

Недостатки:
1.	Длинный список аргументов, с совершенно неочевидным значением переменных. Что ведет к сложности в вызове, понимание назначения функции и тестирования. 
2.	Использование структур и классов таких как DBLogLevel, DBConnector и т.д. без контекста (не известен ни их функционал, ни то зачем они создавались).
3.	Функция выполняет множество различных действий, что осложняет составление тестов. 


Решения:
1.	Добавить комментарии к аргументам функции.
2.	Добавить комментарии к классам и структурам, которые используются в функциях.
3.	Разбить функцию на составные функции, согласно логике выполнения. 

Функция CheckDateTimeValidity

Недостатки:
1.	Однообразные блоки. 
2.	Сложно проходиться отладчиком. 


Решения:
1.	Вынести в отдельные функции-тесты проверку значения каждого поля структуры DateTime. Это позволит проверять их отдельно и вносить изменения в нужный тест. 
2.	 Вывести в канал отладки сообщение о прохождении всех тестов.  
3.	Так же возможно изменение самой структуры функции где на вход будут подаваться только значение для проверки и значение enum class DataType year, month и.т.д. но такое решение предполагает изменение самого подхода к функции. CheckDateTimeValidity

Функция ParseCitySubjson

Недостатки:
1.	Функция ParseCitySubjson выполняет одно действие заполнение информации о стране в вектор городов. Недостаток слишком большой список аргументов.


Решения:
1.	Вынести информацию о стране в отдельную структуру. 
2.	При вызове ParseCitySubjson в ParseCountryJson  указывать названия полей структуры CountryInformation  с помощью designated initializers.
