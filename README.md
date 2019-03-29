# Вариант №17
Создать систему запросов «Салон → База данных дилера Hyundai → Производство Hyundai».
Клиент посещает салон и запрашивает конкретную машину.
Машины характеризуются следующими свойствами:
модель, год выпуска, цвет, объем двигателя, АКПП или МКПП, мощность двигателя,
топливный бак, расход топлива, габариты, подогрев руля, ABS, EDS, система навигации,
бортовой компьютер, подогрев сидений, багажник на крышу, количество подушек безопасности.
Пользователь использует салон для нахождения интересующего товара,
затем запрос отправляется в базу данных дилера, затем на производство.
Использовать паттерн «Цепочка обязанностей».
Данные о товаре для салона, дилера и производства берутся из внешних
входных файлов «salon», «dealer», «manufacture» соответственно.
