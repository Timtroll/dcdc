



![test_plantUML](http://www.plantuml.com/plantuml/png/R8n13e8m44NtSugvG6z0Z0sEIOsqf5CMh8Y9e2P82PPuVP7GhjY-z_u_Vi9j2lEx1vaxPJIAlks2E23NxAXeb3uRX89qjMSsCRqUpzNabaYdfxl_3WlzDt1IN5vbZIA26CtZIYHNbXRXKfcbsmiRtPJICjaqYswh0GOVMWn-HDz5Y93zo2ARdOI1A0hlVOfPQaACRbtuAgIHnf2W8S16LvGQ9G4bxdoCeKewKbfVuTmtyXojED75_DzxvjplZlktwTdfoJbUK3gyee97WHeDzut31xnDBSF6fl0EQylnniFCeR05IePw1ljV7RjZI8sjtIFOIWADw_N7mq5oqxrC9zrXCagkqidey2ZAoPmgS9RPZFyqs7AyTvnMct5CBRSdFiDZHnEe51Dvhx6X8GKqqk2yubrWZcoZPFXQEyelEr4UpTcZuh6pt76fPLYrRbYcbvRZyLdYSkXY7iS7wNNFYMhBzeiuwSRjY0Z_4sWj5sXebDF3pyz_J0h9DsPK22WHT2Fq5D0pB-PGtboS92iYQc24rF98T4-A4WYgKg0BTPROWsL2WygMA2cvSd5N8vceGGkrOCs55XrAU054ROlMeMiD8QWpqjcNutL2Y71U39BFHgkWjt4MYDxzAxYsIIDzto_OosglAstlQ8B7X1K1BmpRHbR_-mw1nhXk8_kIUDvZUCmRC36AsibJjzF1fr76IoGyI-C6pzrJWsU4EB_LJcjXb_ZjhQj9sxt9cPzgpjgL6EBK_VMMGADKYVmmx0LTHfH7eBr0KeStaPzEyjCT3kBNzsV90q--Z-9mw7QSxofGHYIvpCGobl1xOi9mMO7g144Rfw-ipr6KT0eOJzxsykTHMl-2OHCpZUCMfgSJ1YwkM19paJzoLyd-971aw28LkBYU2aPGZAw0CxnAiBmIE5hyccOSON1WRnNkSO1aYOdioO-lFD7tFT7tFD5tFT6RFT6RFT5RFT4RFD5tFT5VUQAtUQBlUpBlllnXurrdJIGPLK1qKyU_F8TnUv7_gHG2khBPUDmkRs0PNmpRaizNJhU8MHpcK9O1YXBOcdmcCvALjcBgnvYFb-UyiabqPP3q8ndFSbmw7p58Qnp6jswdq5fEqkChoxfAzIvII8fyU9-FSYQn5uyz43nKsWcSnZBzd6FVKdhycEYHVny4FxFUzWx0DIpdMotsr6banSQDYVxRYrpEMi7AgsMTkj8bOI-o-bHMsX1hWqrTmCWcWOl8lg0TdcuT9W8GDlv0l5ckQydRMD7qUVZ_LJWhZwkeJyHi3jTuNOsiYs5W6P_NjeBclLs0kM_d5S-3l2DGz1cqh8dCDLaqLxrXiL7rctGxNkRUN42rDGP_bPOHi1SP2GALKnS8yknr32D-N0FBMnQNvdVqZhd1EDqEPex3LthNqfk0AjUhvRHvshMrznlUFSo965YwALhaa9mgjR-1e1IE91in3SWIW522knJ22ARCzmrTdyxs7m00)

# Описание внутренней части системы #

/*in progress*/

Представленная схема была создана на основе **UML**-диаграммы классов. В ней представлены *открытые* операции для всех классов и для некоторых классов изображены группы *приватных* атрибутов для обозначения того, чем оперирует блок. 

На схеме изображены 7 классов: [User_action](#USER_ACTION), [System_info](#SYSTEM_INFO), [Measurements](#MEASUREMENTS), 
[Menu](#MENU), [Screen](#SCREEN), [Display](#DISPLAY) и один дополнительный в виде [JSON_Parser](#JSON_PARSER)

Сами классы в совокупности представляют собой ту часть системы, которая назвывается *блок контроля*,а также	 часть по работе с экраном.
Здесь происходят главные действия в виде: 

* Измерения 
* Установка
* Работа с блоком **I/O**

## Классы ##



### <a name="USER_ACTION">User_action</a> ###

Блок **User_Action** является классом, который предоставляет в парсер варианты взаимодействия с системой для корректного анализа поступившей команды. Далее задача, которая производит непосредственно "действия" в системе имеет доступ к реализации объявленных методов и выполняет их в системе. 

* Операции

На схеме изображены не фактические операции, а группы в которые они объединяются по признаку принадлежности к какому-то другому классу, в последствии уже эти методы отправлюятся в *.h файл* и закрепляются в парсере, как готовые строки. 


Блок включает в себя классы: **System_info, Menu, Measurement, Display**; а через них уже может непосредственно производить изменения в системе, получать данные или работать с блоком **I/O**.


### <a name="SYSTEM_INFO">System_info</a> ###

/*in progress*/

Этот блок - место для хранения *стартовых* характеристик, которые позволяют запустить всю систему. Но главное назначение этого класса - это хранить "предельные" параметры которые **должны** быть в системе и которые нельзя нарушать. 


1. Атрибуты

Это и есть стартовые характеристики системы, которые задаются еще на моменте компиляции, позволяющие *запустить* систему. Система должна знать с каким аккумулятором она работает, как его заряжать и тд.

* Тип батареи
* Напряжение отсечки 
* Максимальный ток потребления
* Формат зарядки
* и т.д.

Но сами атрибуты скрыты и доступ к ним осуществаяется посредством использования операций.

2. Операции


В операциях выделяются две группы работы.	

* Получить значение - **get**

		sys_info_get_voltage_cutoff()

* Установить/выбрать значение - **set**

		sys_info_set_type_battery()


### <a name="MEASUREMENTS">Measurements</a> ###

Сам блок по большей части представляет собой закрытую систему, где происходят измерения на АЦП и датчиках тока, и в отличии от **System_info**, этот блок хранит **реальные** данные о системе, которые постоянно обновляются, посредством использования ресурсов не подконтрольных системе. Данные хранятся в удобном для **Measurements** виде, разделяя на 3 группы атрибутов:

1. Voltage  
2. Current
3. Other

Но по требованию системы, использующей открытый интерфейс, например

	meas_voltage_gen()
	meas_current_charger()
	meas_contact_resistance()

Блок переконвертирует свои данные в нужный формат и предоставит требующему блоку. 

### <a name="MENU">Menu</a> ###

Класс **Menu** - это астрактный способ представлять переходы в системе(навигацию) и хранить данные для блока **I/O**. В нем методы - это варианты взаимодействия с экраном, например 
	
		screen_switch_right()

Блок создает двусвязный список из абстрактных экранов, использую конструктор блока **Screen**, и заполняет информацией из блока **Sys_info**. А методы позволяют переходить по этому списку, как пользователь перемещался бы по меню реальной системы, а также заносить/получать информацию. Также этот блок помогает другому классу - **Display** ориентироваться в экранах и корректно заполнять данные на отправку в блок **I/O**, посредством целого каскада запросов данных. 

Блок включает в себя класс: **Screen**.

### <a name="SCREEN">Screen</a> ###

Класс **Screen** описывает полную работу с "экранами", а точнее их создание, редактирование, уничтожение. Полученными экранами в дальнейшем оперирует астрактное **Menu**.

Атрибуты максимульно были упрощены и бОльшая часть обработки экрана ложиться на блок **I/O**, где в зависимости от разметки выставляются конкретные значения шрифтов, размеров таблицы и тд.  

### <a name="DISPLAY">Display</a> ###


Класс **Display** - это звено между системой с ее **Menu** и реальным экраном. То есть этот класс собирает информацию об активном экране из **Menu**, после чего другие блоки каскадом JSON запросов могут получить нужные данные и  построить уже у себя активный экран.

Пришедший JSON-запрос в **Action**, отправляется далее в **Display**, и с помощью JSON парсера обрабатывает и возвращается корректый ответ или предупреждение о некорректном запросе.
 
### <a name="JSON_PARSER">JSON_Parser</a> ###
 
Этот небольшой класс разбирает JSON строку, которая приходит в блок **Display**, по разобранным ключам, блок составляет ответ в JSON формате, используя уже внутренние функции **Display** для получения значений. 

Также есть возможность составить специальную пару "ключ-значение", которая нужна только в определеном случае и не может быть унифицирована. 