# Linked List Library

##Opis

Biblioteka linked list implementuje podstawowe operacje na liście jednokierunkowej w języku C. Pozwala na dynamiczne dodawanie, usuwanie, przeszukiwanie oraz konwersję listy do tablicy i odwrotnie.

##Funkcje

node* make_head(double value)

Tworzy pierwszy węzeł (głowę) listy z początkową wartością.

	•	Parametry:
	•	value - Wartość double do zapisania w pierwszym węźle.
	•	Zwraca: wskaźnik do utworzonego węzła (głowy listy).

void print_list(node* head)

Wypisuje zawartość listy od głowy (head) do końca.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.

node* append_node(node* head, double value)

Dodaje nowy węzeł o wartości value na końcu listy.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	value - Wartość double do dodania do listy.
	•	Zwraca: wskaźnik do głowy listy.

node* insert_node(node* head, double value, node* pos)

Wstawia nowy węzeł o wartości value przed wskazanym węzłem pos.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	value - Wartość double do dodania do listy.
	•	pos - Wskaźnik do węzła, przed którym wstawiony zostanie nowy węzeł.
	•	Zwraca: wskaźnik do głowy listy.

node* array_to_list(double* arr, int size)

Konwertuje tablicę arr do listy jednokierunkowej.

	•	Parametry:
	•	arr - Wskaźnik do tablicy double.
	•	size - Rozmiar tablicy.
	•	Zwraca: wskaźnik do głowy listy utworzonej na podstawie tablicy.

node* append_array_to_list(node* head, double* arr, int size)

Dodaje elementy z tablicy arr na końcu istniejącej listy.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	arr - Tablica double do dodania do listy.
	•	size - Rozmiar tablicy arr.
	•	Zwraca: wskaźnik do głowy listy.

node* append_after_value(node* head, double target, double value)

Dodaje nowy węzeł o wartości value po pierwszym węźle o wartości target.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	target - Wartość double istniejącego węzła.
	•	value - Wartość double nowego węzła.
	•	Zwraca: wskaźnik do głowy listy.

node* reverse_list(node* head)

Odwraca kolejność węzłów na liście.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	Zwraca: wskaźnik do nowej głowy odwróconej listy.

double* list_to_array(node* head)

Konwertuje listę na tablicę.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	Zwraca: wskaźnik do nowej tablicy double utworzonej z listy.

void free_list(node* head)

Zwalnia pamięć przydzieloną dla listy.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.

void delete_value(node* head, double value)

Usuwa pierwszy węzeł o wartości value z listy.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.
	•	value - Wartość double węzła do usunięcia.

void list_pop(node* head)

Usuwa ostatni węzeł z listy.

	•	Parametry:
	•	head - Wskaźnik do głowy listy.

 
-----------------------------------------------------------------------------------------------------------------------------------

#Hash Table Library

##Opis

Biblioteka hashtable implementuje strukturę danych typu tabela mieszająca (hash table) w języku C. Pozwala ona na przechowywanie par klucz-wartość, szybkie wyszukiwanie oraz podstawowe operacje manipulujące danymi.

##Funkcje

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

--------------------------------------------------------------------------------------------------------------------------------------

#Binary Tree Library

##Opis

Biblioteka binary tree implementuje strukturę danych drzewa binarnego w języku C, oferując podstawowe operacje takie jak wstawianie, przeszukiwanie oraz wyświetlanie drzewa.

##Funkcje

node* bt_make_node(double value)

Tworzy nowy węzeł drzewa binarnego z początkową wartością.

	•	Parametry:
	•	value - Wartość double, którą ma przechowywać nowy węzeł.
	•	Zwraca: wskaźnik do utworzonego węzła drzewa.

void bt_insert(node* root, double value)

Wstawia nowy węzeł o wartości value do drzewa binarnego, zachowując jego strukturę.

	•	Parametry:
	•	root - Wskaźnik do korzenia drzewa.
	•	value - Wartość double, którą należy wstawić.

void bt_print(node* root, int level, int indent_space)

Wypisuje zawartość drzewa binarnego w formie wizualnej, pokazując hierarchię drzewa na podstawie poziomu (level) i odstępów (indent_space).

	•	Parametry:
	•	root - Wskaźnik do korzenia drzewa.
	•	level - Poziom początkowy, od którego rozpoczyna się drukowanie (ustaw na 0 dla korzenia).
	•	indent_space - Liczba spacji używanych do wcięć między poziomami.

node* bt_insert_array(double* arr, int size)

Tworzy drzewo binarne na podstawie wartości przechowywanych w tablicy arr.

	•	Parametry:
	•	arr - Wskaźnik do tablicy double.
	•	size - Rozmiar tablicy arr.
	•	Zwraca: wskaźnik do korzenia drzewa binarnego utworzonego na podstawie tablicy.

bool bt_search(node* root, double value)

Przeszukuje drzewo binarne w poszukiwaniu wartości value.

	•	Parametry:
	•	root - Wskaźnik do korzenia drzewa.
	•	value - Wartość double, której szukamy.
	•	Zwraca: true, jeśli wartość value znajduje się w drzewie, lub false, jeśli jej nie ma.
