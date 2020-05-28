
![test_plantUML](http://www.plantuml.com/plantuml/png/R8xFJi904CRl-nJp03RHgo741jS48otfbWCdOapH9aWDb8kdKYuc6aryaa9em3-KLvXv8wShYpLww6Rc-xxvzJiPnvUZU78x47R3RxeEM8EW7rjrK5tborQlwPov85hIwVpdx8nHU7sZdOOdfMD8UxaCYTEcQb_ONR2CO5AJEwtOgkD9Dlm_v-VATNfjsrFI0r5TQfO5E-p-YFD64c8OnG5e34JztvpQEBmFZeyEw_WAkCMC4ffYJWdcW0NEUSXmpd9AZxZWEUTfIY_0JyfcWU-O7VnGU2qevI-X6JsNHCt29MRuWMl01TXNSHWDgpTPANz7w0at77-Z1tu_GVz-POgmjU4QURNriYBZchjliT2O5StAil3LQ1NiECx2u3jFmN4wpLJw_oVOosglA-tS4IKEpOf25fkTgQ9vzpKDqp1DMoMNDFR7X-tFcBOz3awV1FXMvZfmEOpJYB9KQXHR6qCQ59wGuAXwtuMdpQVn21hdhy9LkttYhuyBQTqjetWfd8EE-WW44KVnDpZI5fH95BgkaNGQGEqrDHB8x3vaVeJYH-nsyjVtLyKB3w55kTk9BVET0rG8fBuoFMskt9_41F6qS9g3ZhRtzeowxGL5XmXu2AvLF_VAXJU8gv1f6DOW0nqWSd7b5P2BV8rTaFr9sbDF9sMqn-LMUj26lGl7KRyhxJWJlNTm7zPxWkYrkrIuXKudHmnaJNxSqyG-riG-qiG-rCIkriIkriIkrSIkqCG-rCJUqyIkqyG-rcG-VNcUygbpFP924m7yAFZDU_I-aVcNIJ62dmuRhzlc0wpmhMTPydpCTBNDGNSnbJ2wC6EAeOwXp7wUAgyveL6AAH0LXlFOapuTzn2LwptWXzWQS8v9MdZdQCuH1eyKaw4GImvFb9ba8vzRJNfJO0VjBKpRpnnD3MdXckYPtnl9pnnlVUDmwQQnLcey2WiSSU-7HFyrCbUn5AxWIZL7CJL7R6IEFasPLi3ILwE8WAoDzWWi1xZkvT9OCcg2IXQD5wKjHxwviaqntJR_lp3do75X3OaOpUPYBzceaap1p_OvjuLhFjB5SMdNEUDvKV2a3TroVQs9oZNvqbpbIkVkAbVHkIazl5EHcD6rQxvvQWVUNuFrcdhh-by3RyyOXAYqCJ2G-et1AwJOUvl9YZC2fUXLxiY9wHluDXtTFm00)




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



### <a name="SYSTEM_INFO">System_info</a> ###



### <a name="MEASUREMENTS">Measurements</a> ###


### <a name="MENU">Menu</a> ###


### <a name="SCREEN">Screen</a> ###



### <a name="DISPLAY">Display</a> ###



### <a name="JSON_PARSER">JSON_Parser</a> ###
 