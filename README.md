Repozytorium zawiera biblioteki implementujące następujące typy zmiennych do języka C:
- Lista Jednostronnie Łączona (Single Linked List)
- Tablica Mieszająca (Hash Table)
- Drzewo binarne (Binary Search Tree)

Biblioteka Single Linked List pozwala na następujące operacje:
- Tworzenie nowego węzła: make_head()
- Dołączanie węzła na końcu: listy append_node()
- Usunięcie ostatniego węzła: list_pop()
- Umieszczenie węzła pomiędzy dwoma innymi: insert_node()
- Zamiana tablicy na listę łączoną i odwrotnie: array_to_list(), list_to_array()
- Dodanie węzła po konkretnej wartości: append_after_value()
- Usunięcie kokretnej wartości: delete_value()
- Odwracanie listy: reverse_list()
- Wypisanie całej listy print_list()
I kilka innych:
![alt text](https://github.com/oskar-przybylski/Biblioteki/blob/master/Single%20Linked%20List/przykład.png?raw=true)
![alt text](https://github.com/oskar-przybylski/Biblioteki/blob/master/Single%20Linked%20List/przykład_output.png?raw=true)  

Tablica mieszająca

Opis

Biblioteka hashtable implementuje strukturę danych typu tabela mieszająca (hash table) w języku C. Pozwala ona na przechowywanie par klucz-wartość, szybkie wyszukiwanie oraz podstawowe operacje manipulujące danymi.

Funkcje

unsigned int hash(int key, int table_size)

Funkcja mieszająca generująca indeks na podstawie klucza key i rozmiaru tablicy table_size.

	•	Parametry:
	•	key - Klucz całkowity.
	•	table_size - Rozmiar tablicy haszującej.
	•	Zwraca: indeks unsigned int.

HT* ht_init(int size)

Inicjalizuje nową tabelę mieszającą o podanym rozmiarze size.

	•	Parametry:
	•	size - Rozmiar tablicy haszującej.
	•	Zwraca: wskaźnik do nowo utworzonej tabeli haszującej (HT*).

void ht_insert(HT* ht, int key, int value)

Wstawia parę klucz-wartość do tabeli haszującej.

	•	Parametry:
	•	ht - Wskaźnik do tabeli haszującej.
	•	key - Klucz całkowity.
	•	value - Wartość całkowita.

void ht_print(HT* ht)

Wypisuje zawartość tabeli haszującej.

	•	Parametry:
	•	ht - Wskaźnik do tabeli haszującej.

void ht_insert_arr(HT* ht, int* arr, int size)

Wstawia wiele kluczy z tablicy arr do tabeli haszującej.

	•	Parametry:
	•	ht - Wskaźnik do tabeli haszującej.
	•	arr - Tablica kluczy.
	•	size - Rozmiar tablicy arr.

int ht_lookup(HT* ht, int key)

Wyszukuje wartość na podstawie klucza key w tabeli haszującej.

	•	Parametry:
	•	ht - Wskaźnik do tabeli haszującej.
	•	key - Klucz całkowity.
	•	Zwraca: wartość powiązaną z key, lub -1, jeśli klucz nie istnieje.

void ht_free(HT* ht)

Zwalnia pamięć przydzieloną dla tabeli haszującej.
