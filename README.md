# POP_PROJEKT_22Z
_Richad Staszkiewicz, Andrzej Bednarczyk_

## Zadanie
Zaimplementować i przetesotować algorytm A\* dla zadania znalezienia ścieżki o najmniejszej wadze od punktu A do B. Wejściem aplikacji jest plik z listą krawędzi grafu (dla każdej krawędzi zdefiniowany jest punkt początkowy, końcowy i waga krawędzi). Wyjściem aplikacji jest najkrótsza scieżka od punktu A do punktu B. Porównać działanie algorytmu A\* z "brutalnym" przeszukiwaniem grafu. Zastosowanie dodatkowego algorytmu będzie dodatkowym atutem przy ocenie projektu.

## Interpretacja
Mając przykładowe wejście w postaci pliku zawierającego:
1. W pierwszej linii: W (liczba wierzchołków), K (liczba krawędzi), P (liczba zapytań)
2. W następnych K liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego), D (odległość)
3. W następnych P liniach: S1 (nr wierzchołka początkowego), S2 (nr wierzchołka końcowego)

Przykład takiego pliku w postaci `test1` znajduje się poniżej:
```txt
3 3 1
0 1 4
1 2 6
0 2 20
0 2
```

Spodziewaną odpowiedzią programu `main.cpp` jest plik .csv zawierający P linii o formacie:
```txt
[Odległość brut], [Odległość A*], [Odległość Dijkstra], [Czas brut], [Czas A*], [Czas Dijkstra]
```

## Rozwiązanie
Zaimplementowano klasę Graph do przechowywania reprezentacji grafu.

W trakcie prac zaimplementowano następujące algorytmy:
1. A* - obsługiwany przez klasę Astar
2. Dijkstra - obsługiwany przez klasę Dijkstra
3. Brut - obsługiwany przez klasę Brut

Oprogramowanie tworzono z pomocą technik TDD na z testowaniem na podstawie biblioteki GTest. Każda z klas jest testowana w osobnym pliku i była tworzona rozdzielnie od reszty.


## Grafy testowe
### Test 1
Prosty graf w kształcie trójąta. Jedyne zapytanie prosi o najkrótszą ścieżkę pomiędzy wierzchołkami przebiegającą przez trzeci z nich.

![](raport_data/test1.png)

### Test 2
Większy graf w formie cyklu. Jedyne zapytanie prosi o drogę między sąsiednimi wierzchołkami, gdzie optymalna droga prowadzi nei przez łączącą krawędź, a przez całą resztę cyklu.

![](raport_data/test2.png)

### Test 3
Średniej wielkości graf łączący punktem artykulacji cykl z grafem o dwóch obiegach. Jeden punkt pozostaje bez połączeń. Jedyno zapytanie prosi o znalezienie drogi pomiędzy punktem w cyklu a jednym z punktów artykulacyjnych obiegów. Drugie prosi o znalezienie ścieżki z punktu wolnego do grafu.

![](raport_data/test3.png)

### Test 4
Średniej wielkości graf rozłączny skłądający się z kliki 4 wierzchołków z dołączoną krawędzią do piątego i łańcucha trzech wierzchołków. Pierwsze zapytanie prosi o znalezienie ścieżki pomiędzy kliką a łańcuchem.

![](raport_data/test4.png)

### Test 5
Graf pełny o 1000 wierzchołków.

### Test 6
Graf w postaciłańcucha o 10k wierzchołkach.

### Test 7
Graf w postaci łąńcucha o 25k wierzchołkach.

### Test 8
Graf w losowy o wypełnieniu 50% mający 5k wierzchołków.

### Test 9
Graf w losowy o wypełnieniu 50% mający 10k wierzchołków.

### Test 10
Graf w losowy o wypełnieniu 50% mający 25k wierzchołków.

### Test 11
Graf w losowy o wypełnieniu 20% mający 50k wierzchołków.

## Rezultaty
Podczas przeprowadzania testów czasowych otrzymano następujące rezultaty ilościowe:
| Graf | Ilość zapytań | A* | Dijkstra | Brut | Jednostka czasu |
| :---: | :---: | :---: | :---: | :---: | :---: |
| test1 | 1 | 1000 | 1000 | 1400 | nanosekundy |
| test2 | 1 |

## Dyskusja wyników

## Podsumowanie

## Dokumentacja
Dokumentacja została skompilowana na podstawie komentarzy z pomocą narzędzia DoxyGen. Wskazane w raporcie wizualizacje grafów dokonano z pomocą narzędzia https://csacademy.com/app/graph_editor/.

## Licencja
MIT GNU Open Licence
